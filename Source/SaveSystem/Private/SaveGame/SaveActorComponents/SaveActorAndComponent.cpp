// Copyright Andrii Berozkin. All Rights Reserved.

#include <SaveSystem/Public/SaveGame/SaveActorComponents/SaveActorAndComponent.h>
#include <Serialization/MemoryWriter.h>
#include <Serialization/MemoryReader.h>
#include <SaveSystem/Public/SaveGame/InitializeStatics.h>
#include <Async/ParallelFor.h>



extern DEFINE_LOG_CATEGORY(SaveSystemLog);

USaveActoWithComponent::USaveActoWithComponent(const FObjectInitializer& ObjectInitializer/*= FObjectInitializer::Get()*/)
	:Super(ObjectInitializer)
{
}

void USaveActoWithComponent::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);
	if (bUseUObjectSerialize) { return; }
	Ar << ActorComponentsRecord;
}

void USaveActoWithComponent::SaveComponents(TArray<UActorComponent*>& ActorComponents)
{
#if WITH_EDITOR && !UE_BUILD_SHIPPING
	SCOPE_CYCLE_COUNTER(STAT_ActComponentSave);
#endif // WITH_EDITOR && !UE_BUILD_SHIPPING

	if (IsUseParallelFor())
	{
		ParallelFor(ActorComponents.Num(), [this, &ActorComponents](int32 i)
			{
				ProcessingSaveActorComponents(ActorComponents, i);
			});
	}
	else
	{
		for (int32 i = 0, iMax = ActorComponents.Num(); i < iMax; i++)
		{
			ProcessingSaveActorComponents(ActorComponents, i);
		}
	}

	ActorComponents.RemoveAll([](UActorComponent* Comp) {return Comp == nullptr ? true : false; });

	Super::SaveComponents(ActorComponents);
}

void USaveActoWithComponent::LoadComponents(UWorld* World, UClass* OuterClass/* = nullptr*/, FName OuterName/* = NAME_None*/)
{
#if WITH_EDITOR && !UE_BUILD_SHIPPING
	SCOPE_CYCLE_COUNTER(STAT_ActorCompInit);
#endif // WITH_EDITOR && !UE_BUILD_SHIPPING

	if (OuterClass != nullptr && OuterName != NAME_None)
	{
		for (const FActorComponentRecord ActorComponentRecord : ActorComponentsRecord)
		{
			if (ActorComponentRecord.OuterClass == OuterClass && ActorComponentRecord.OuterName == OuterName)
			{
				LoadStructActorComponent(ActorComponentRecord, World);
			}
		}
	}
	else
	{
		for (const FActorComponentRecord ActorComponentRecord : ActorComponentsRecord)
		{
			LoadStructActorComponent(ActorComponentRecord, World);
		}
	}

	Super::LoadComponents(World, OuterClass, OuterName);
}

inline void USaveActoWithComponent::ProcessingSaveActorComponents(TArray<UActorComponent*>& ActorComponents, int32& i)
{
	if (UActorComponent* ActorComponent = Cast<UActorComponent>(ActorComponents[i]))
	{
		FActorComponentRecord NewRec = SaveStructActorComponent(ActorComponent);
		Mutex.Lock();
		ActorComponentsRecord.Add(NewRec);
		ActorComponents[i] = nullptr;
		Mutex.Unlock();
	}
}

FActorComponentRecord USaveActoWithComponent::SaveStructActorComponent(UActorComponent* ActorComponent)
{
	FActorComponentRecord NewRecord;
	NewRecord = SaveObject(ActorComponent);

	//	Begin fill FActorComponentRecord param
	NewRecord.OwnerPtr = ActorComponent->GetOwner();
	NewRecord.OwnerClass = ActorComponent->GetOwner()->GetClass();
	NewRecord.OwnerName = ActorComponent->GetOwner()->GetFName();
	NewRecord.bIsDefaultSubobject = ActorComponent->IsDefaultSubobject();

	Mutex.Lock();
	bool bIncludeNestedObjects = bIncludeDescendants;
	Mutex.Unlock();

	NewRecord.Objects = SaveObjectsChilds(ActorComponent, bIncludeNestedObjects);

	return NewRecord;
}

UActorComponent* USaveActoWithComponent::LoadStructActorComponent(const FActorComponentRecord& ActorComponentRecord, UWorld* World)
{
	UActorComponent* ActorComponent = UInitializeStatics::InitializeActorComponent(ActorComponentRecord, World);

	for (FObjectRecord ObjRecord : ActorComponentRecord.Objects)
	{
		LoadObject(ObjRecord, World, ActorComponent);	//	Figure out how to prevent duping UObject if the gatherd with bIncludeNestedObjects
	}

	FMemoryReader MemoryReader(ActorComponentRecord.BinaryData, true);
	FSaveGameStruct SaveGameStruct(MemoryReader);

	Mutex.Lock();
	ActorComponent->Serialize(SaveGameStruct);
	Mutex.Unlock();

	return ActorComponent;
}