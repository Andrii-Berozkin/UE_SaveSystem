// Copyright Andrii Berozkin. All Rights Reserved.

#include <SaveSystem/Public/SaveGame/InitializeStatics.h>
#include <SaveSystem/Public/SaveGame/SaveInterface.h>
#include <SaveSystem/Public/SaveGame/SaveObject.h>
#include <SaveSystem/Public/StructRecord/ObjectRecord.h>
#include <SaveSystem/Public/StructRecord/ActorRecord/ActorRecord.h>
#include <SaveSystem/Public/StructRecord/ActorComponentRecord/ActorComponentRecord.h>
#include <Async/Async.h>



DECLARE_CYCLE_STAT(TEXT("Object Initialization"), STAT_ObjectInit, STATGROUP_SaveSystem);
DECLARE_CYCLE_STAT(TEXT("Actor Initialization"), STAT_ActorInit, STATGROUP_SaveSystem);
DECLARE_CYCLE_STAT(TEXT("Actor Component Initialization"), STAT_ActorCompInit, STATGROUP_SaveSystem);

UObject* UInitializeStatics::InitializeObject(const FObjectRecord& ObjectRecord, UWorld* WorldPtr, UObject* OptionalOuter/* = nullptr*/)
{
#if WITH_EDITOR && !UE_BUILD_SHIPPING
	SCOPE_CYCLE_COUNTER(STAT_ObjectInit);
#endif // WITH_EDITOR && !UE_BUILD_SHIPPING

	UObject* LoadedObject = nullptr;
	UObject* OuterObject = nullptr;

	bool bIsExist_DEPRECATED = false;
	bool bIsOuterExist_DEPRECATED = false;

	//	Begin Find object with given outer
	if (OptionalOuter && !OptionalOuter->IsPendingKillOrUnreachable() && ObjectRecord.OuterClass == OptionalOuter->GetClass())
	{
		OuterObject = OptionalOuter;
		LoadedObject = StaticFindObjectFast(ObjectRecord.Class, OuterObject, ObjectRecord.Name, true);
	}
	//	End   Find object with given outer

	//	Begin if Outer pointer valid try find object
	if (!LoadedObject && !OuterObject)
	{
		if (ObjectRecord.OuterPtr->IsValidLowLevelFast() && !ObjectRecord.OuterPtr->IsPendingKillOrUnreachable())
		{
			OuterObject = ObjectRecord.OuterPtr;
			LoadedObject = StaticFindObjectFast(ObjectRecord.Class, ObjectRecord.OuterPtr, ObjectRecord.Name, true);
		}
	}
	//	End   if Outer pointer valid try find object

	//	Begin Try to find Object outer as actor at TopLevel package
	if (!LoadedObject && !OuterObject)
	{
		if (UObject* CandidOuter = StaticFindObjectFast(ObjectRecord.OuterClass, WorldPtr->GetCurrentLevel(), ObjectRecord.OuterName, true))
		{
			if (!CandidOuter->IsPendingKillOrUnreachable()) { OuterObject = CandidOuter; }
		}

		if (OuterObject)
		{
			LoadedObject = StaticFindObjectFast(ObjectRecord.Class, OuterObject, ObjectRecord.Name, true);
		}
	}
	//	End   Try to find Object outer as actor at TopLevel package

	//	Begin (if Objecft dosen`t exist && OuterObject exist) -> Create new Object with existed ObjectOuter
	if (!LoadedObject && OuterObject)
	{
		if (!IsInGameThread())
		{
			FScopedEvent Event;
			AsyncTask(ENamedThreads::GameThread, [&LoadedObject, &OuterObject, &ObjectRecord, &Event]()
				{LoadedObject = NewObject<UObject>(OuterObject, ObjectRecord.Class, ObjectRecord.Name); Event.Trigger(); });
		}
		else { LoadedObject = NewObject<UObject>(OuterObject, ObjectRecord.Class, ObjectRecord.Name); }
	}
	//	End (if Objecft dosen`t exist && OuterObject exist) -> Create new Object with existed ObjectOuter

	return LoadedObject;
}

UObject* UInitializeStatics::InitializeObjectChecked(const FObjectRecord& ObjectRecord, UWorld* WorldPtr, UObject* OptionalOuter/*= nullptr*/)
{
	UObject* InitializedObject = InitializeObject(ObjectRecord, WorldPtr, OptionalOuter);

#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
	if (!InitializedObject)
	{
		UE_LOG(SaveSystemLog, Fatal, TEXT("Failed to initialize object '%s, %s, Outer %s, %s'"), *ObjectRecord.Name.ToString(),
			ObjectRecord.Class ? *ObjectRecord.Class->GetName() : TEXT("nullptr"),
			*ObjectRecord.OuterName.ToString(), ObjectRecord.OuterClass ? *ObjectRecord.Class->GetName() : TEXT("nullptr"));
	}
#endif // !(UE_BUILD_SHIPPING || UE_BUILD_TEST)

	return InitializedObject;
}

AActor* UInitializeStatics::InitializeActor(const FActorRecord& ActorRecord, UWorld* World, bool bDeferredSpawn)
{
#if WITH_EDITOR && !UE_BUILD_SHIPPING
	SCOPE_CYCLE_COUNTER(STAT_ActorInit);
#endif // WITH_EDITOR && !UE_BUILD_SHIPPING

	AActor* LoadedActor = nullptr;
	AActor* OwnerActor = nullptr;

	const bool bIsGameThread = IsInGameThread();

	//	Begin Check Actor exist at level
	if (!LoadedActor)
	{
		//	if dosen`t have owner, it must be TopLevel package
		if (ActorRecord.OwnerPtr && ActorRecord.OwnerPtr->IsValidLowLevelFast() && !ActorRecord.OwnerPtr->IsPendingKillOrUnreachable())
		{
			OwnerActor = ActorRecord.OwnerPtr;
		}

		//	In case we want initialize actor which already existed and GC hasn`t collect it yet	(Most time will be unusable)
		if (ActorRecord.SelfPointer && ActorRecord.SelfPointer->IsValidLowLevelFast() && !ActorRecord.SelfPointer->IsPendingKillOrUnreachable())
		{
			LoadedActor = Cast<AActor>(ActorRecord.SelfPointer);
		}

		//	This StaticFind can be used without GameThread as CurrentLevel as outer is safe
		if (AActor* Actor = StaticCast<AActor*>(StaticFindObjectFast(ActorRecord.Class, World->GetCurrentLevel(), ActorRecord.Name, true)))
		{
			if (Actor->IsPendingKillOrUnreachable())
			{
				//	If GC hasn`t collected actor yet, rename it to some generic uniq name to release current Name to SpawnActor
				if (!bIsGameThread)
				{
					FScopedEvent Event;
					AsyncTask(ENamedThreads::GameThread, [&Actor, &Event]()
						{
							FName NameToRename = MakeUniqueObjectName(Actor->GetOuter(), Actor->GetClass(), TEXT("ActorToKill_SaveSystem"));
							Actor->Rename(*NameToRename.ToString()); Event.Trigger();
						});
				}
				else
				{
					FName NameToRename = MakeUniqueObjectName(Actor->GetOuter(), Actor->GetClass(), TEXT("ActorToKill_SaveSystem"));
					Actor->Rename(*NameToRename.ToString());
				}
			}
			else
			{
				LoadedActor = Actor;
			}
		}
	}
	//	End   Check Actor exist at level	

	//	Begin Spawn Actor with additional owner
	if (!LoadedActor && ActorRecord.Class)
	{
		FActorSpawnParameters SpawnParam;
		SpawnParam.Name = ActorRecord.Name;
		SpawnParam.bDeferConstruction = bDeferredSpawn;
		SpawnParam.Owner = OwnerActor;
		SpawnParam.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;


		if (!bIsGameThread)
		{
			FScopedEvent Event;
			AsyncTask(ENamedThreads::GameThread, [&LoadedActor, &World, &ActorRecord, &SpawnParam, &Event]()
				{ LoadedActor = World->SpawnActor(ActorRecord.Class, &ActorRecord.Transform, SpawnParam); Event.Trigger(); });
		}
		else { LoadedActor = World->SpawnActor(ActorRecord.Class, &ActorRecord.Transform, SpawnParam); }
	}
	//	End   Spawn Actor with additional owner

	return LoadedActor;
}

AActor* UInitializeStatics::InitializeActorChecked(const FActorRecord& ActorRecord, UWorld* World, bool bDeferredSpawn)
{
	AActor* InitializedActor = InitializeActor(ActorRecord, World, bDeferredSpawn);

#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
	if (!InitializedActor) 
	{ 
		UE_LOG(SaveSystemLog, Fatal, TEXT("Failed to initialize actor '%s, %s, Outer %s, %s'"), *ActorRecord.Name.ToString(), 
			ActorRecord.Class ? *ActorRecord.Class->GetName() : TEXT("nullptr"),
			*ActorRecord.OuterName.ToString(), ActorRecord.OuterClass ? *ActorRecord.Class->GetName() : TEXT("nullptr"));
	}
#endif // !(UE_BUILD_SHIPPING || UE_BUILD_TEST)

	return InitializedActor;
}

inline void RegisterComponentWithRecord(UActorComponent*& ActorComponent, AActor*& ActorOwner, const FActorComponentRecord& ActorComponentRecord)
{
	ActorComponent = NewObject<UActorComponent>(ActorOwner, ActorComponentRecord.Class, ActorComponentRecord.Name);
	ActorComponent->OnComponentCreated();
	ActorComponent->RegisterComponent();
}

UActorComponent* UInitializeStatics::InitializeActorComponent(const FActorComponentRecord& ActorComponentRecord, UWorld* World)
{
#if WITH_EDITOR && !UE_BUILD_SHIPPING
	SCOPE_CYCLE_COUNTER(STAT_ActorCompInit);
#endif // WITH_EDITOR && !UE_BUILD_SHIPPING

	UActorComponent* ActComponent = nullptr;
	AActor* ActorOwner = nullptr;

	//	Begin Find existing component owner
	if (ActorComponentRecord.OwnerPtr)
	{
		if (!ActorComponentRecord.OwnerPtr->IsPendingKillOrUnreachable()) { ActorOwner = ActorComponentRecord.OwnerPtr; }
	}

	if (ActorComponentRecord.SelfPointer && ActorComponentRecord.SelfPointer->IsValidLowLevelFast() && !ActorComponentRecord.SelfPointer->IsPendingKillOrUnreachable())
	{
		ActComponent = Cast<UActorComponent>(ActorComponentRecord.SelfPointer); 
	}

	if (!ActorOwner)
	{
		//	This StaticFind save for execute at another Thread sa long as it Use to Outer a "CurrentLevel"
		if (AActor* Owner = StaticCast<AActor*>(StaticFindObjectFast(ActorComponentRecord.OuterClass, World->GetCurrentLevel(), ActorComponentRecord.OuterName, true)))
		{
			if (!Owner->IsPendingKillOrUnreachable()) { ActorOwner = Owner; }
		}
	}
	//	End   Find existing component owner

	const bool bIsGameThread = IsInGameThread();

	//	Begin Find already existed component (Constructed DefaultSubobjects by Actor)
	if (!ActComponent && ActorOwner)
	{

		if (!bIsGameThread)
		{
			//	This StaticFind must be executed at GameThread because it use actual pointer at Owner as Outer, and in term of Owner Package is at GameThread
			FScopedEvent Event;
			AsyncTask(ENamedThreads::GameThread, [&ActorComponentRecord, &ActorOwner, &ActComponent, &Event]()
				{
					if (UActorComponent* Component = StaticCast<UActorComponent*>(StaticFindObjectFast(ActorComponentRecord.Class, ActorOwner, ActorComponentRecord.Name, true)))
					{
						if (!Component->IsPendingKillOrUnreachable()) { ActComponent = Component; }
					}
					Event.Trigger();
				});
		}
		else
		{
			if (UActorComponent* Component = StaticCast<UActorComponent*>(StaticFindObjectFast(ActorComponentRecord.Class, ActorOwner, ActorComponentRecord.Name, true)))
			{
				if (!Component->IsPendingKillOrUnreachable()) { ActComponent = Component; }
			}
		}
	}
	//	End   Find already existed component (Constructed DefaultSubobjects by Actor)

	//	Begin create NonDefault Component and register it
	if (!ActComponent && ActorOwner)
	{
		if (!bIsGameThread)
		{
			FScopedEvent Event;
			AsyncTask(ENamedThreads::GameThread, [&ActComponent, &ActorOwner, &ActorComponentRecord, &Event]()
				{
					RegisterComponentWithRecord(ActComponent, ActorOwner, ActorComponentRecord);
					Event.Trigger();
				});
		}
		else
		{
			RegisterComponentWithRecord(ActComponent, ActorOwner, ActorComponentRecord);
		}
	}
	//	End   create NonDefault Component and register it

	return ActComponent;
}

UActorComponent* UInitializeStatics::InitializeActorComponentChecked(const FActorComponentRecord& ActorComponentRecord, UWorld* World)
{
	UActorComponent* InitializedActorComponent = InitializeActorComponent(ActorComponentRecord, World);

#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
	if (!InitializedActorComponent)
	{
		UE_LOG(SaveSystemLog, Fatal, TEXT("Failed to initialize actor component '%s, %s, Outer %s, %s'"), *ActorComponentRecord.Name.ToString(),
			ActorComponentRecord.Class ? *ActorComponentRecord.Class->GetName() : TEXT("nullptr"),
			*ActorComponentRecord.OuterName.ToString(), ActorComponentRecord.OuterClass ? *ActorComponentRecord.Class->GetName() : TEXT("nullptr"));
	}
#endif // !(UE_BUILD_SHIPPING || UE_BUILD_TEST)

	return InitializedActorComponent;
}