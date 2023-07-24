// Copyright Andrii Berozkin. All Rights Reserved.

#include <SaveSystem/Public/SaveGame/SaveActorComponents/SaveSceneComponent.h>
#include <Serialization/MemoryWriter.h>
#include <Serialization/MemoryReader.h>



extern DEFINE_LOG_CATEGORY(SaveSystemLog);

const FName USaveActorWithComponentsScene::NoneName(NAME_None);

USaveActorWithComponentsScene::USaveActorWithComponentsScene(const FObjectInitializer& ObjectInitializer/*= FObjectInitializer::Get()*/)
	:Super(ObjectInitializer)
{
	bSavePrimitivePhysicRepresentation = true;
}

void USaveActorWithComponentsScene::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);
	if (bUseUObjectSerialize) { return; }
	Ar << SceneComponentsRecord;
	Ar << PrimitiveComponentsRecord;
}

inline bool OuterFirsComponentSort(const FActorComponentRecord& Lr, const FActorComponentRecord& Rr)
{
	if (Lr.OuterPtr == Rr.OuterPtr) { return true; }
	if (Lr.OuterPtr == Rr.SelfPointer) { return false; }
	if (Lr.OuterPtr && (Rr.OuterPtr == nullptr)) { return false; }
	if (Rr.OuterPtr) { return true; }
	return true;
}

void USaveActorWithComponentsScene::SaveComponents(TArray<UActorComponent*>& ActorComponents)
{
#if WITH_EDITOR && !UE_BUILD_SHIPPING
	SCOPE_CYCLE_COUNTER(STAT_ActComponentSave);
#endif // WITH_EDITOR && !UE_BUILD_SHIPPING

	if (IsUseParallelFor())
	{
		ParallelFor(ActorComponents.Num(), [this, &ActorComponents](int32 i)
			{
				ProcessingSavePrimitiveComponent(ActorComponents, i);

				ProcessingSaveSceneComponent(ActorComponents, i);
			});
	}
	else
	{
		for (int32 i = 0, iMax = ActorComponents.Num(); i < iMax; i++)
		{
			ProcessingSavePrimitiveComponent(ActorComponents, i);

			ProcessingSaveSceneComponent(ActorComponents, i);
		}
	}

	PrimitiveComponentsRecord.Sort(OuterFirsComponentSort);
	SceneComponentsRecord.Sort(OuterFirsComponentSort);

	ActorComponents.RemoveAll([](UActorComponent* Comp) {return Comp == nullptr ? true : false; });

	Super::SaveComponents(ActorComponents);
}

void USaveActorWithComponentsScene::LoadComponents(UWorld* World, UClass* OuterClass/* = nullptr*/, FName OuterName/* = NAME_Noneme*/)
{
#if WITH_EDITOR && !UE_BUILD_SHIPPING
	SCOPE_CYCLE_COUNTER(STAT_ActorCompInit);
#endif // WITH_EDITOR && !UE_BUILD_SHIPPING

	if (OuterClass != nullptr && OuterName != NAME_None)
	{
		for (const FPrimitiveComponentRecord PrimitiveRecord : PrimitiveComponentsRecord)
		{
			if (PrimitiveRecord.OuterClass == OuterClass && PrimitiveRecord.OuterName == OuterName)
			{
				LoadStructPrimitiveComponent(PrimitiveRecord, World);
			}
		}

		for (const FSceneComponentRecord SceneRecord : SceneComponentsRecord)
		{
			if (SceneRecord.OuterClass == OuterClass && SceneRecord.OuterName == OuterName)
			{
				LoadStructSceneComponent(SceneRecord, World);
			}
		}
	}
	else
	{
		for (const FPrimitiveComponentRecord PrimitiveRecord : PrimitiveComponentsRecord)
		{
			LoadStructPrimitiveComponent(PrimitiveRecord, World);
		}

		for (const FSceneComponentRecord SceneRecord : SceneComponentsRecord)
		{
			LoadStructSceneComponent(SceneRecord, World);
		}
	}

	Super::LoadComponents(World, OuterClass, OuterName);
}

inline void USaveActorWithComponentsScene::ProcessingSavePrimitiveComponent(TArray<UActorComponent*>& ActorComponents, int32& i)
{
	if (UPrimitiveComponent* PrimitiveComponent = Cast<UPrimitiveComponent>(ActorComponents[i]))
	{
		FPrimitiveComponentRecord NewRec = SaveStructPrimitiveComponent(PrimitiveComponent);
		Mutex.Lock();
		PrimitiveComponentsRecord.Add(NewRec);
		ActorComponents[i] = nullptr;
		Mutex.Unlock();
	}
}

inline void USaveActorWithComponentsScene::ProcessingSaveSceneComponent(TArray<UActorComponent*>& ActorComponents, int32& i)
{
	if (USceneComponent* SceneComponent = Cast<USceneComponent>(ActorComponents[i]))
	{
		FSceneComponentRecord NewRec = SaveStructSceneComponent(SceneComponent);
		Mutex.Lock();
		SceneComponentsRecord.Add(NewRec);
		ActorComponents[i] = nullptr;
		Mutex.Unlock();
	}
}

FSceneComponentRecord USaveActorWithComponentsScene::SaveStructSceneComponent(USceneComponent* SceneComponent)
{
	FSceneComponentRecord NewRecord;
	NewRecord = SaveStructActorComponent(SceneComponent);

	//	Begin fill FSceneComponentRecord param
	NewRecord.Transform = SceneComponent->GetComponentTransform();
	if (USceneComponent* AttachParent = SceneComponent->GetAttachParent())
	{
		NewRecord.AttachParentPtr = AttachParent;
		NewRecord.AttachParentClass = AttachParent->GetClass();
		NewRecord.AttachParentName = AttachParent->GetFName();
	}

	NewRecord.AttachSocketName = SceneComponent->GetAttachSocketName();
	NewRecord.bIsHidden = SceneComponent->bHiddenInGame;

	return NewRecord;
}

inline void SceneComponenTransformtHelper(USceneComponent*& ScenComponent, USceneComponent*& AttachParent, const FSceneComponentRecord& SceneRecord)
{
	ScenComponent->SetWorldTransform(SceneRecord.Transform, false, (FHitResult*)nullptr, ETeleportType::TeleportPhysics);
	ScenComponent->AttachToComponent(AttachParent, FAttachmentTransformRules::KeepWorldTransform, SceneRecord.AttachSocketName);
	ScenComponent->SetHiddenInGame(SceneRecord.bIsHidden);
}

USceneComponent* USaveActorWithComponentsScene::LoadStructSceneComponent(const FSceneComponentRecord& SceneRecord, UWorld* World)
{
	USceneComponent* ScenComponent = nullptr;
	ScenComponent = StaticCast<USceneComponent*>(LoadStructActorComponent(SceneRecord, World));

	//	Begin load SceneComponent param
	USceneComponent* AttachParent = nullptr;
	if (SceneRecord.AttachParentPtr && !SceneRecord.AttachParentPtr->IsPendingKillOrUnreachable() && SceneRecord.AttachParentPtr != GetTransientPackage())
	{
		AttachParent = StaticCast<USceneComponent*>(SceneRecord.AttachParentPtr);
	}

	if (!AttachParent && SceneRecord.AttachParentClass)
	{
		if (IsLoadWithThread())
		{
			FScopedEvent Event;
			AsyncTask(ENamedThreads::GameThread, [&AttachParent, &SceneRecord, &ScenComponent, &Event]()
				{
					if (USceneComponent* NewAttachParent =
						StaticCast<USceneComponent*>(StaticFindObjectFast(SceneRecord.AttachParentClass, ScenComponent->GetOwner(), SceneRecord.AttachParentName, true)))
					{
						AttachParent = NewAttachParent;
					}
					Event.Trigger();
				});
		}
		else
		{
			if (USceneComponent* NewAttachParent =
				StaticCast<USceneComponent*>(StaticFindObjectFast(SceneRecord.AttachParentClass, ScenComponent->GetOwner(), SceneRecord.AttachParentName, true)))
			{
				AttachParent = NewAttachParent;
			}
		}
	}

	if (IsLoadWithThread())
	{
		FScopedEvent Event;
		AsyncTask(ENamedThreads::GameThread, [&ScenComponent, &AttachParent, &SceneRecord, &Event]()
			{
				SceneComponenTransformtHelper(ScenComponent, AttachParent, SceneRecord);
				Event.Trigger();
			});
	}
	else
	{
		SceneComponenTransformtHelper(ScenComponent, AttachParent, SceneRecord);
	}

	return ScenComponent;
}

FPrimitiveComponentRecord USaveActorWithComponentsScene::SaveStructPrimitiveComponent(UPrimitiveComponent* PrimitiveComponent, TArray<FName> BoneNames/* = TArray<FName>(&NoneName, 1)*/)
{
	FPrimitiveComponentRecord NewRecord;
	NewRecord = SaveStructSceneComponent(PrimitiveComponent);

	//	Begin fill FPrimitiveComponentRecord param
	NewRecord.bIsWelded = PrimitiveComponent->IsWelded();
	if (bSavePrimitivePhysicRepresentation)
	{
		NewRecord.BoneToBodyInst.Reserve(BoneNames.Num());
		for (FName BoneName : BoneNames)
		{
			FBodyInstance* BodyInstance = PrimitiveComponent->GetBodyInstance(BoneName, NewRecord.bIsWelded);
			if (UPhysicalMaterial* PhysMat = BodyInstance->GetSimplePhysicalMaterial())
			{
				UE_LOG(SaveSystemLog, Display, TEXT("Phys mat exist"));
			}
			else
			{

			}

			FTransform BodyTransform = BodyInstance->GetUnrealWorldTransform();
			FTransform BodyTransformNonProject = BodyInstance->GetUnrealWorldTransform(false);

			if (BodyTransform.Equals(BodyTransformNonProject)) { UE_LOG(SaveSystemLog, Display, TEXT("Transform exact")); }

			FTransform BodyTransformGlobal = BodyInstance->GetUnrealWorldTransform(true, true);
			FTransform BodyTransformNonProjectGlobal = BodyInstance->GetUnrealWorldTransform(false, true);

			if (BodyTransformGlobal.Equals(BodyTransformNonProjectGlobal)) { UE_LOG(SaveSystemLog, Display, TEXT("BodyTransformGlobal exact")); }

			NewRecord.BoneToBodyInst.Add(BoneName, FBodyInstanceRecord(*BodyInstance,
				BodyInstance->GetUnrealWorldTransform(),
				BodyInstance->GetUnrealWorldVelocity(),
				BodyInstance->GetUnrealWorldAngularVelocityInRadians()));
		}
	}

	return NewRecord;
}

inline void PrimitiveComponentPhysicInitHelper(UBodySetup*& BodySetup,
	FPhysScene*& PhysScene,
	const FInitBodySpawnParams& BodyParam,
	FBodyInstance*& BoneBodyInstance,
	const FBodyInstanceRecord*& Represent,
	UPrimitiveComponent*& PrimitiveComponent,
	FName& BoneName)
{
	if (BodySetup) { BoneBodyInstance->InitBody(BodySetup, Represent->BodyTransform, PrimitiveComponent, PhysScene, BodyParam); }

	BoneBodyInstance->SetLinearVelocity(Represent->UnrealWorldLinearVelocity, false, false);
	BoneBodyInstance->SetAngularVelocityInRadians(Represent->UnrealWorldAngularVelocityRadians, false, false);
	if (PrimitiveComponent->IsSimulatingPhysics(BoneName)) { BoneBodyInstance->WakeInstance(); }
}

UPrimitiveComponent* USaveActorWithComponentsScene::LoadStructPrimitiveComponent(const FPrimitiveComponentRecord& PrimitiveRecord, UWorld* World, TArray<FName> BoneNames/* = TArray<FName>(&NoneName, 1)*/)
{
	UPrimitiveComponent* PrimitiveComponent = nullptr;
	PrimitiveComponent = StaticCast<UPrimitiveComponent*>(LoadStructSceneComponent(PrimitiveRecord, World));

	//	Begin fill PrimitiveComponent param
	if (PrimitiveRecord.bIsWelded) { PrimitiveComponent->WeldToImplementation(StaticCast<USceneComponent*>(PrimitiveRecord.AttachParentPtr), PrimitiveRecord.AttachSocketName, true); }
	if (bSavePrimitivePhysicRepresentation)
	{
		UBodySetup* BodySetup = PrimitiveComponent->GetBodySetup();
		FPhysScene* PhysScene = World->GetPhysicsScene();
		FInitBodySpawnParams BodyParam(PrimitiveComponent);

		for (FName BoneName : BoneNames)
		{
			const FBodyInstanceRecord* Represent = PrimitiveRecord.BoneToBodyInst.Find(BoneName);

			PrimitiveComponent->GetBodyInstance(BoneName)->TermBody(true);
			PrimitiveComponent->GetBodyInstance(BoneName)->CopyBodyInstancePropertiesFrom(&Represent->BodyInstance);	//	If this dosen`t work try to apply it 
																														//	straight at GetBodyInstance(BoneName)
			FBodyInstance* BoneBodyInstance = PrimitiveComponent->GetBodyInstance(BoneName);

			if (IsLoadWithThread())
			{
				FScopedEvent Event;
				AsyncTask(ENamedThreads::GameThread, [&BodySetup, &PhysScene, &BodyParam, &BoneBodyInstance, &Represent, &PrimitiveComponent, &BoneName, &Event]()
					{
						PrimitiveComponentPhysicInitHelper(BodySetup, PhysScene, BodyParam, BoneBodyInstance, Represent, PrimitiveComponent, BoneName);
						Event.Trigger();
					});
			}
			else
			{
				PrimitiveComponentPhysicInitHelper(BodySetup, PhysScene, BodyParam, BoneBodyInstance, Represent, PrimitiveComponent, BoneName);
			}
		}

		if (IsLoadWithThread())
		{
			AsyncTask(ENamedThreads::GameThread, [&PrimitiveComponent]() { PrimitiveComponent->GlobalCreatePhysicsDelegate.Broadcast(PrimitiveComponent); });
		}
		else { PrimitiveComponent->GlobalCreatePhysicsDelegate.Broadcast(PrimitiveComponent); }

	}

	return PrimitiveComponent;
}