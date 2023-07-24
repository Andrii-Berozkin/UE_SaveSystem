// Copyright Andrii Berozkin. All Rights Reserved.

#include <SaveSystem/Public/SaveGame/SaveActor/SaveActor.h>
#include <Serialization/MemoryWriter.h>
#include <Serialization/MemoryReader.h>
#include <Kismet/GameplayStatics.h>
#include <SaveSystem/Public/StructRecord/ActorComponentRecord/ActorComponentRecord.h>
#include <SaveSystem/Public/SaveGame/InitializeStatics.h>
#include <GameFramework/Actor.h>
#include <Async/ParallelFor.h>

DECLARE_CYCLE_STAT_EXTERN(TEXT("PostActorConstruction"), STAT_PostActorConstruction, STATGROUP_Engine, ENGINE_API);
extern DEFINE_LOG_CATEGORY(SaveSystemLog);



USaveGameActors::USaveGameActors(const FObjectInitializer& ObjectInitializer/*= FObjectInitializer::Get()*/)
	: Super(ObjectInitializer)
{
}

void USaveGameActors::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);
	if (bUseUObjectSerialize) { return; }
	Ar << ActorsRecord;
};

inline bool OwnerFirstSort(const FActorRecord& Lr, const FActorRecord& Rr)
{
	if (Lr.OwnerPtr == Rr.OwnerPtr) { return true; }
	if (Lr.OwnerPtr == Rr.SelfPointer) { return false; }
	if (Lr.OwnerPtr && (Rr.OwnerPtr == nullptr)) { return false; }
	if (Rr.OwnerPtr) { return true; }
	return true;
}

void USaveGameActors::Save(TArray<UObject*>& ObjectsPtr)
{
#if WITH_EDITOR && !UE_BUILD_SHIPPING
	SCOPE_CYCLE_COUNTER(STAT_ActSaveMain);
#endif // WITH_EDITOR && !UE_BUILD_SHIPPING

	//	Begin Save Actors
	if (IsUseParallelFor())
	{
		ParallelFor(ObjectsPtr.Num(), [this, &ObjectsPtr](int32 i)
			{
				ProcessingSaveActor(ObjectsPtr, i);
			});
	}
	else
	{
		for (int32 i = 0, iMax = ObjectsPtr.Num(); i < iMax; i++)
		{
			ProcessingSaveActor(ObjectsPtr, i);
		}
	}
	//	End   Save Actors

	{
#if WITH_EDITOR && !UE_BUILD_SHIPPING
		SCOPE_CYCLE_COUNTER(STAT_ActOwnerFirstSort);
#endif // WITH_EDITOR && !UE_BUILD_SHIPPING
		Mutex.Lock();
		ActorsRecord.Sort(OwnerFirstSort);
		Mutex.Unlock();
	}

	//	Begin Save ActorComponents
	//SaveComponents(ComponentsToSave);
	//	End   Save ActorComponents

	ObjectsPtr.RemoveAll([](UObject* Object) {return Object == nullptr ? true : false; });

	USaveGameSlot::Save(ObjectsPtr);
}

inline void ActorPostConstructLoadHelper(AActor*& ActorToFinish)
{
	ActorToFinish->PostActorConstruction();

	//	In case that we use DeferredSpawn we need set actor private bHasFinishedSpawning = true
	//	But Actor::FinishSpawn will execute AActor::ExecuteConstruction which reinit ActorComponent param that we has already loaded even with FComponentInstanceDataCache
	//	In other case when we call AActor::FinishSpawn or use non Deferred spawn, we can`t deserialize ActorComponent property before BeginPlay will have been called
	ActorToFinish->PostLoad();
}

void USaveGameActors::Load(UWorld* World)
{
#if WITH_EDITOR && !UE_BUILD_SHIPPING
	SCOPE_CYCLE_COUNTER(STAT_ActLoadMain);
#endif // WITH_EDITOR && !UE_BUILD_SHIPPING

	TArray<AActor*> ToFinishSpawnList;

	for (int32 i = 0, iMax = ActorsRecord.Num(); i < iMax; i++)
	{
		AActor* NewAct = LoadActor(ActorsRecord[i], World, true);

		if (!NewAct->IsActorBeginningPlay())
		{
			FTransform CurrTransform = ActorsRecord[i].Transform;

			ToFinishSpawnList.Add(NewAct);

			if (IsLoadWithThread())
			{
				FScopedEvent Event;
				AsyncTask(ENamedThreads::GameThread, [&NewAct, &CurrTransform, &Event]() { NewAct->ExecuteConstruction(CurrTransform, nullptr, nullptr, false); Event.Trigger(); });
			}
			else { NewAct->ExecuteConstruction(CurrTransform, nullptr, nullptr, false); }
		}

		LoadComponents(World, NewAct->GetClass(), NewAct->GetFName());

	}


	//	Has simillar call structure as Load or Save
	//LoadComponents(World);


	if (IsLoadWithThread())
	{
		FScopedEvent Event;
		AsyncTask(ENamedThreads::GameThread, [&ToFinishSpawnList, &Event]()
			{
				for (int32 i = 0, iMax = ToFinishSpawnList.Num(); i < iMax; i++)
				{
					ActorPostConstructLoadHelper(ToFinishSpawnList[i]);
				}
				Event.Trigger();
			});
	}
	else
	{
		for (int32 i = 0, iMax = ToFinishSpawnList.Num(); i < iMax; i++)
		{
			ActorPostConstructLoadHelper(ToFinishSpawnList[i]);
		}
	}

	USaveGameSlot::Load(World);
}

inline void USaveGameActors::ProcessingSaveActor(TArray<UObject*>& ObjectsPtr, int32& i)
{
	if (AActor* ActorPtr = Cast<AActor>(ObjectsPtr[i]))
	{
		FActorRecord NewRec = SaveActor(ActorPtr);
		Mutex.Lock();
		ActorsRecord.Add(NewRec);
		ObjectsPtr[i] = nullptr;
		Mutex.Unlock();
	}
}

FActorRecord USaveGameActors::SaveActor(AActor* ActorPtr)
{
#if WITH_EDITOR && !UE_BUILD_SHIPPING
	SCOPE_CYCLE_COUNTER(STAT_ActorSave);
#endif // WITH_EDITOR && !UE_BUILD_SHIPPING
	FActorRecord ActorRecord;
	ActorRecord = SaveObject(ActorPtr);


	//	Begin fill FActorRecord fields
	ActorRecord.Transform = ActorPtr->GetTransform();
	if (AActor* Owner = ActorPtr->GetOwner())
	{
		ActorRecord.OwnerPtr = Owner;
		ActorRecord.OwnerClass = Owner->GetClass();
		ActorRecord.OwnerName = Owner->GetFName();
	}
	ActorRecord.bIsHidden = ActorPtr->IsHidden();

	Mutex.Lock();
	bool bIncludeNestedObjects = bIncludeDescendants;
	Mutex.Unlock();

	ActorRecord.Objects = SaveObjectsChilds(ActorPtr, bIncludeNestedObjects);

	TArray<UActorComponent*> Components = ActorPtr->GetComponents().Array();
	SaveComponents(Components);

	return ActorRecord;
}

inline void ActorTransformHelper(AActor*& NewActor, const FActorRecord& ActorRecord)
{
	NewActor->SetActorTransform(ActorRecord.Transform, false, (FHitResult*)nullptr, ETeleportType::TeleportPhysics);
	NewActor->SetActorHiddenInGame(ActorRecord.bIsHidden);
}

AActor* USaveGameActors::LoadActor(const FActorRecord& ActorRecord, UWorld* World, bool bDeferredSpawn/*= false*/)
{
#if WITH_EDITOR && !UE_BUILD_SHIPPING
	SCOPE_CYCLE_COUNTER(STAT_ActorLoad);
#endif // WITH_EDITOR && !UE_BUILD_SHIPPING

	AActor* NewActor = UInitializeStatics::InitializeActor(ActorRecord, World, bDeferredSpawn);

	if (IsLoadWithThread())
	{
		FScopedEvent Event;
		AsyncTask(ENamedThreads::GameThread, [&NewActor, &ActorRecord, &Event]()
			{
				ActorTransformHelper(NewActor, ActorRecord);
				Event.Trigger();
			});
	}
	else
	{
		ActorTransformHelper(NewActor, ActorRecord);
	}

	for (const FObjectRecord ObjRecord : ActorRecord.Objects)
	{
		LoadObject(ObjRecord, World, NewActor);
	}

	FMemoryReader MemoryReader(ActorRecord.BinaryData, true);
	FSaveGameStruct SaveGameStruct(MemoryReader);

	Mutex.Lock();
	NewActor->Serialize(SaveGameStruct);
	Mutex.Unlock();

	return NewActor;
}

bool USaveGameActors::FindOuterSavableChildObjects(const UObjectBase* Outer, TArray<UObject*>& OutArray, bool bIncludeNestedObjects)
{
	OutArray.Empty();

	ForEachObjectWithOuter(Outer, [&OutArray, this](UObject* Object)
		{
			if (UActorComponent* ActComponent = Cast<UActorComponent>(Object)) { Mutex.Lock(); ComponentsToSave.Add(ActComponent); Mutex.Unlock(); }
			else { OutArray.Add(Object); }
		}, bIncludeNestedObjects, RF_Transient);

	return OutArray.Num() > 0 ? true : false;
}

void USaveGameActors::SaveComponents(TArray<UActorComponent*>& ActorComponents)
{
#if WITH_EDITOR && !UE_BUILD_SHIPPING
	SCOPE_CYCLE_COUNTER(STAT_ActComponentSave);
#endif // WITH_EDITOR && !UE_BUILD_SHIPPING

	ActorComponents.Empty();
	return;
}

void USaveGameActors::LoadComponents(UWorld* World, UClass* OuterClass/* = nullptr*/, FName OuterName/* = NAME_None*/)
{
#if WITH_EDITOR && !UE_BUILD_SHIPPING
	SCOPE_CYCLE_COUNTER(STAT_ActComponentLoad);
#endif // WITH_EDITOR && !UE_BUILD_SHIPPING

	return;
}

inline void RegisterComponentHelper(UActorComponent*& ActComponent, AActor*& ActorOwner, const FActorComponentRecord& ActComponentRecord)
{
	ActComponent = NewObject<UActorComponent>(ActorOwner, ActComponentRecord.Class, ActComponentRecord.Name);
	ActComponent->OnComponentCreated();
	ActComponent->RegisterComponent();
}

//	Detailed information about right order to create runtime component https://forums.unrealengine.com/t/what-is-the-correct-way-to-create-and-add-components-at-runtime/15605
/*
* //in some AActor class

void AYourActor::CreateComponent(UClass* CompClass,const FVector& Location, const FRotator& Rotation, const FName& AttachSocket=NAME_None)
{
  FName YourObjectName("Hiiii");

  //CompClass can be a BP
  UPrimitiveComponent* NewComp = ConstructObject<UPrimitiveComponent>( CompClass, this, YourObjectName);
  if(!NewComp)
 {
	return NULL;
 }
 //~~~~~~~~~~~~~

  NewComp->RegisterComponent();        //You must ConstructObject with a valid Outer that has world, see above
  NewComp->SetWorldLocation(Location);
  NewComp->SetWorldRotation(Rotation);
  NewComp->AttachTo(GetRootComponent(),SocketName,EAttachLocation::KeepWorldPosition);
   //could use different than Root Comp
}

UMyActorComponent* ActorComponent = ConstructObject<UMyActorComponent>(UMyActorComponent::StaticClass(), this);
ActorComponent->OnComponentCreated();
ActorComponent->RegisterComponent();
if (ActorComponent->bWantsInitializeComponent) ActorComponent->InitializeComponent();
*/


/**Find all possible UObject based candidat for saving,
* and filter them, by !RF_Transient && CPF_SaveGame flags,
* also try to find them in class property,
* and they must be uniq in OuterArray
* if candid meets all the requirements, add to OuterArray
*/