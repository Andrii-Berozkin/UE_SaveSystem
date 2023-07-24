// Copyright Andrii Berozkin. All Rights Reserved.

#include <SaveSystem/Public/SaveGame/SaveObject.h>
#include <Serialization/MemoryWriter.h>
#include <Serialization/MemoryReader.h>
#include <GenericPlatform/GenericPlatformProcess.h>
#include <SaveSystem/Public/SaveGame/InitializeStatics.h>
#include <Async/Async.h>
#include <Async/ParallelFor.h>



DEFINE_LOG_CATEGORY(SaveSystemLog);

USaveGameSlot::USaveGameSlot(const FObjectInitializer& ObjectInitializer/*= FObjectInitializer::Get()*/)
	: Super(ObjectInitializer), SaveTime(FDateTime::Now())
{
	bDebugEnable = true;

	bSaveObjectProperty = false;
	bIncludeDescendants = true;
	bUseUObjectSerialize = true;

	bUseParallelFor = false;
	bSaveWithThread = false;
	bLoadWithThread = false;
}

USaveGameSlot::~USaveGameSlot()
{
	if (Thread) { Thread->Kill(); delete Thread; Thread = nullptr; }
}

void USaveGameSlot::Serialize(FArchive& Ar)
{
	if (bUseUObjectSerialize) { Super::Serialize(Ar); return; }
	Ar << bDebugEnable;
	Ar << bSaveObjectProperty;
	Ar << bIncludeDescendants;
	Ar << bUseParallelFor;
	Ar << ObjectsRecord;
	Ar << SaveTime;
}

inline bool OuterFirstSort(const FObjectRecord& Lr, const FObjectRecord& Rr)
{
	if (Lr.OuterPtr == Rr.OuterPtr) { return true; }
	if (Lr.OuterPtr == Rr.SelfPointer) { return false; }
	if (Lr.OuterPtr && (Rr.OuterPtr == nullptr)) { return false; }
	if (Rr.OuterPtr) { return true; }
	return true;
}

inline bool OuterFirstUObjectSort(const UObject& Lr, const UObject& Rr)
{
	if (Lr.GetOuter() == Rr.GetOuter()) { return true; }
	if (Lr.GetOuter() == &Rr) { return false; }
	if (Lr.GetOuter() && (Rr.GetOuter() == nullptr)) { return false; }
	if (Rr.GetOuter()) { return true; }
	return true;
}

void USaveGameSlot::Save(TArray<UObject*>& ObjectsPtr)
{
#if WITH_EDITOR && !UE_BUILD_SHIPPING
	SCOPE_CYCLE_COUNTER(STAT_ObjSaveMain);
#endif // WITH_EDITOR && !UE_BUILD_SHIPPING

	if (IsUseParallelFor())
	{
		ParallelFor(ObjectsPtr.Num(), [this, &ObjectsPtr](int32 i)
			{
				ProcessingObjectSave(ObjectsPtr, i);
			});
	}
	else
	{
		for (int32 i = 0, iMax = ObjectsPtr.Num(); iMax > i; i++)
		{
			ProcessingObjectSave(ObjectsPtr, i);
		}
	}

	Mutex.Lock();
	ObjectsRecord.Sort(OuterFirstSort);
	Mutex.Unlock();

	if (IsSaveWithThread()) { Mutex.Lock(); }
	ObjectsPtr.Empty();
	if (IsSaveWithThread()) { Mutex.Unlock(); }

	if (IsSaveWithThread()) {
		FScopedEvent Event; AsyncTask(ENamedThreads::GameThread, [this, &Event]() {
			OnSaveComplete.Broadcast(this); OnThreadSaveComplete.Broadcast(this); Event.Trigger(); });
	}
	else { OnSaveComplete.Broadcast(this); OnThreadSaveComplete.Broadcast(this); }
}

void USaveGameSlot::Load(UWorld* World)
{
#if WITH_EDITOR && !UE_BUILD_SHIPPING
	SCOPE_CYCLE_COUNTER(STAT_ObjLoadMain);
#endif // WITH_EDITOR && !UE_BUILD_SHIPPING

	for (FObjectRecord ObjectRecord : ObjectsRecord)
	{
		LoadObject(ObjectRecord, World);
	}

	if (IsLoadWithThread()) {
		FScopedEvent Event; AsyncTask(ENamedThreads::GameThread, [this, &Event]() {
			OnLoadComplete.Broadcast(this); OnThreadLoadComplete.Broadcast(this); Event.Trigger(); });
	}
	else { OnLoadComplete.Broadcast(this); OnThreadLoadComplete.Broadcast(this); }
}

inline void USaveGameSlot::ProcessingObjectSave(TArray<UObject*>& ObjectsPtr, int32& i)
{
	FObjectRecord NewRec = SaveObject(ObjectsPtr[i]);

	Mutex.Lock();
	bool bIncludeNestedObjects = bIncludeDescendants;
	Mutex.Unlock();

	TArray<FObjectRecord> ChildsRec(SaveObjectsChilds(ObjectsPtr[i], bIncludeNestedObjects));

	Mutex.Lock();
	ObjectsRecord.Add(NewRec);
	ObjectsRecord.Append(ChildsRec);
	ObjectsPtr[i] = nullptr;
	Mutex.Unlock();
}

void USaveGameSlot::ThreadPrepare()
{
	InternalThreadComplete.Unbind();

	InternalThreadComplete.BindLambda([this]()
		{
			AsyncTask(ENamedThreads::GameThread, [this]()
				{ Thread->Kill(); delete Thread; Thread = nullptr; });
		});

	if (Thread) { delete Thread; Thread = nullptr; }
}

void USaveGameSlot::MultithreadSave(const TArray<UObject*>& ObjectsPtr)
{
	BufferArr.Empty();
	BufferArr = TArray<UObject*>(ObjectsPtr);

	if (!FGenericPlatformProcess::SupportsMultithreading()) { Save(BufferArr); }

	ThreadPrepare();

	bSaveWithThread = true;

	Thread = FRunnableThread::Create(this, TEXT("SaveSystem: SaveThread"), 0, EThreadPriority::TPri_Normal, FGenericPlatformAffinity::GetNoAffinityMask(), EThreadCreateFlags::None);
}

void USaveGameSlot::MultithreadLoad(UWorld* World)
{
	if (!FGenericPlatformProcess::SupportsMultithreading()) { Load(World); }
	CurrWorld = World;

	ThreadPrepare();

	bLoadWithThread = true;

	Thread = FRunnableThread::Create(this, TEXT("SaveSystem: LoadThread"), 0, EThreadPriority::TPri_Normal, FGenericPlatformAffinity::GetNoAffinityMask(), EThreadCreateFlags::None);
}

bool USaveGameSlot::Init()
{
	return true;
}

uint32 USaveGameSlot::Run()
{
	if (IsSaveWithThread()) { Save(BufferArr); }
	if (IsLoadWithThread()) { Load(CurrWorld); }

	InternalThreadComplete.ExecuteIfBound();

	return 0;
}

void USaveGameSlot::Stop()
{
	UE_LOG(SaveSystemLog, Display, TEXT("Notification : Thread Stop"));
	BufferArr.Empty();

	bSaveWithThread = false;
	bLoadWithThread = false;
	return;
}

bool USaveGameSlot::IsUseParallelFor() const
{
	return FGenericPlatformProcess::SupportsMultithreading() ? bUseParallelFor : false;
}

bool USaveGameSlot::IsObjectSaved(const UClass* ObjectClass, const FName ObjectName, int32& OutIndex)
{
#if WITH_EDITOR && !UE_BUILD_SHIPPING
	SCOPE_CYCLE_COUNTER(STAT_OuterSearch);
#endif // WITH_EDITOR && !UE_BUILD_SHIPPING

	OutIndex = 0;
	if (!ObjectClass) { return false; }
	for (int32 i = 0, iMax = ObjectsRecord.Num(); iMax > i; i++)
	{
		Mutex.Lock();
		if (ObjectsRecord[i].Class == ObjectClass && ObjectsRecord[i].Name == ObjectName)
		{
			OutIndex = i;
			return true;
		}
		Mutex.Unlock();
	}
	return false;
}

FObjectRecord USaveGameSlot::SaveObject(UObject* ObjectPtr)
{
#if WITH_EDITOR && !UE_BUILD_SHIPPING
	SCOPE_CYCLE_COUNTER(STAT_ObjectSave);
#endif // WITH_EDITOR && !UE_BUILD_SHIPPING

	FObjectRecord NewRecord;
	NewRecord.Class = ObjectPtr->GetClass();
	NewRecord.Name = ObjectPtr->GetFName();
	NewRecord.OuterPtr = ObjectPtr->GetOuter();	//	Outer of Actor is always a PersistentLevel
	NewRecord.OuterClass = ObjectPtr->GetOuter()->GetClass();
	NewRecord.OuterName = ObjectPtr->GetOuter()->GetFName();
	NewRecord.SelfPointer = ObjectPtr;

	FMemoryWriter MemoryWriter(NewRecord.BinaryData, true);
	FSaveGameStruct SaveGameStruct(MemoryWriter);

	ObjectPtr->Serialize(SaveGameStruct);

	return NewRecord;
}

void USaveGameSlot::SaveOnlyOuterRelatedChilds(const TArray<UObject*>& OuterChilds, TArray<FObjectRecord>& Savedrecords, UObjectBase*& LastOuter, int32 Index)
{
	UObject* Object = OuterChilds[Index];
	if (Object->GetOuter() != LastOuter) { return; }

	FObjectRecord NewRec = SaveObject(Object);
	Mutex.Lock();
	Savedrecords.Add(NewRec);
	Mutex.Unlock();

	int32 NextObj = Index + 1 < OuterChilds.Num() ? Index + 1 : OuterChilds.Num() - 1;
	if (OuterChilds[NextObj]->GetOuter() != LastOuter) { LastOuter = Object; }
}

TArray<FObjectRecord> USaveGameSlot::SaveObjectsChilds(UObjectBase* OuterPtr, bool bIncludeNestedObjects/*= true*/)
{
#if WITH_EDITOR && !UE_BUILD_SHIPPING
	SCOPE_CYCLE_COUNTER(STAT_ChildObjSave);
#endif // WITH_EDITOR && !UE_BUILD_SHIPPING

	TArray<FObjectRecord> ChildsRecord;

	UObjectBase* LastOuter = OuterPtr;

	//	Begin : Save childs
	TArray<UObject*> SavebaleChilds;
	if (FindOuterSavableChildObjects(OuterPtr, SavebaleChilds, bIncludeNestedObjects))
	{
		SavebaleChilds.Sort(OuterFirstUObjectSort);

		if (IsUseParallelFor())
		{
			ParallelFor(SavebaleChilds.Num(), [this, &SavebaleChilds, &ChildsRecord, &LastOuter](int32 i)
				{
					SaveOnlyOuterRelatedChilds(SavebaleChilds, ChildsRecord, LastOuter, i);
				});
		}
		else
		{
			for (int32 i = 0, iMax = SavebaleChilds.Num(); i < iMax; i++)
			{
				SaveOnlyOuterRelatedChilds(SavebaleChilds, ChildsRecord, LastOuter, i);
			}
		}
	}
	//	End   : Save childs

	ChildsRecord.Sort(OuterFirstSort);

	return ChildsRecord;
}

UObject* USaveGameSlot::LoadObject(const FObjectRecord& ObjectRecord, UWorld* World, UObject* OptionalOuter/*= nullptr*/)
{
#if WITH_EDITOR && !UE_BUILD_SHIPPING
	SCOPE_CYCLE_COUNTER(STAT_ObjectLoad);
#endif // WITH_EDITOR && !UE_BUILD_SHIPPING

	UObject* LoadedObject = UInitializeStatics::InitializeObject(ObjectRecord, World, OptionalOuter);

	FMemoryReader MemoryReader(ObjectRecord.BinaryData, true);
	FSaveGameStruct SaveGameStruct(MemoryReader);

	Mutex.Lock();
	LoadedObject->Serialize(SaveGameStruct);
	Mutex.Unlock();

	return LoadedObject;
}

bool USaveGameSlot::IsSavableProperty(FProperty* Property) const
{
#if WITH_EDITOR && !UE_BUILD_SHIPPING
	SCOPE_CYCLE_COUNTER(STAT_IsSavableProp);
#endif // WITH_EDITOR && !UE_BUILD_SHIPPING

	return !Property->HasAnyPropertyFlags(EPropertyFlags::CPF_Transient) && Property->HasAnyPropertyFlags(EPropertyFlags::CPF_SaveGame) ? true : false;
}

template<class T>
void USaveGameSlot::GetObjectSavableProperties(const UObjectBase* OuterObj, TArray<T*>& OutArr) const
{
#if WITH_EDITOR && !UE_BUILD_SHIPPING
	SCOPE_CYCLE_COUNTER(STAT_GetSavableProp);
#endif // WITH_EDITOR && !UE_BUILD_SHIPPING
	OutArr.Empty();

	for (FProperty* __restrict Property = OuterObj->GetClass()->PropertyLink; Property; Property = Property->PropertyLinkNext)
	{
		if (IsSavableProperty(Property))
		{
			if (T* CastedProperty = CastField<T>(Property))
			{
				OutArr.Add(CastedProperty);
			}
		}
	}
}

template<>
void USaveGameSlot::GetObjectSavableProperties<FProperty>(const UObjectBase* OuterObj, TArray<FProperty*>& OutArr) const
{
#if WITH_EDITOR && !UE_BUILD_SHIPPING
	SCOPE_CYCLE_COUNTER(STAT_GetSavableProp);
#endif // WITH_EDITOR && !UE_BUILD_SHIPPING
	OutArr.Empty();

	for (FProperty* __restrict Property = OuterObj->GetClass()->PropertyLink; Property; Property = Property->PropertyLinkNext)
	{
		if (IsSavableProperty(Property))
		{
			OutArr.Add(Property);
		}
	}
}

bool USaveGameSlot::FindOuterSavableChildObjects(const UObjectBase* Outer, TArray<UObject*>& OutArray, bool bIncludeNestedObjects/*= false*/)
{
#if WITH_EDITOR && !UE_BUILD_SHIPPING
	SCOPE_CYCLE_COUNTER(STAT_FindOuterChilds);
#endif // WITH_EDITOR && !UE_BUILD_SHIPPING

	OutArray.Empty();

	ForEachObjectWithOuter(Outer, [&OutArray](UObject* Object)
		{
			OutArray.Add(Object);
		}, bIncludeNestedObjects, RF_Transient, EInternalObjectFlags::PendingKill | EInternalObjectFlags::Unreachable);

	return OutArray.Num() > 0 ? true : false;
}

TArray<UObject*> USaveGameSlot::FilterSaveble(const UObjectBase* OuterPtr, const TArray<FObjectPropertyBase*>& SavebleObjectProperty, TArray<UObject*>& ObjectsToSave)
{
	TArray<UObject*> FilteredArray;
	for (FObjectPropertyBase* __restrict ObjProperty : SavebleObjectProperty)
	{
		if (UObject* CandidObject = ObjProperty->GetObjectPropertyValue_InContainer(OuterPtr))
		{
			for (UObject* __restrict Object : ObjectsToSave)
			{
				if (CandidObject == Object)
				{
					FilteredArray.AddUnique(CandidObject);
					ObjectsToSave.Remove(Object);
					break;
				}
			}
		}
	}

	return FilteredArray;
}