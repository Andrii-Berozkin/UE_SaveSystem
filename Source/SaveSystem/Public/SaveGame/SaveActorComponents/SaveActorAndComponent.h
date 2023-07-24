// Copyright Andrii Berozkin. All Rights Reserved.

#pragma once
#include <CoreMinimal.h>
#include <SaveGame/SaveActor/SaveActor.h>
#include <StructRecord/ActorComponentRecord/ActorComponentRecord.h>
#include "SaveActorAndComponent.generated.h"



UCLASS()
class SAVESYSTEM_API USaveActoWithComponent : public USaveGameActors
{
	GENERATED_BODY()

public:

protected:

	UPROPERTY()
	TArray<FActorComponentRecord> ActorComponentsRecord;

public:

	USaveActoWithComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	virtual void Serialize(FArchive& Ar) override;

protected:

	//	Begin USaveGameActors interface
	virtual void SaveComponents(TArray<UActorComponent*>& ActorComponents) override;

	virtual void LoadComponents(UWorld* World, UClass* OuterClass = nullptr, FName OuterName = NAME_None) override;
	//	End   USaveGameActors interface

private:

	inline void ProcessingSaveActorComponents(TArray<UActorComponent*>& ActorComponents, int32& i);

protected:

	//	Detailed realization
	FActorComponentRecord SaveStructActorComponent(UActorComponent* ActorComponent);

	UActorComponent* LoadStructActorComponent(const FActorComponentRecord& ActorComponentRecord, UWorld* World);

private:
};