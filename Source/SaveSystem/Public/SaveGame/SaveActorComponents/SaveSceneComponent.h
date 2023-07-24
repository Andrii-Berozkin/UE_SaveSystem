// Copyright Andrii Berozkin. All Rights Reserved.

#pragma once

#include <CoreMinimal.h>
#include <SaveGame/SaveActorComponents/SaveActorAndComponent.h>
#include <StructRecord/ActorComponentRecord/SceneComponent/SceneComponentRecord.h>
#include <StructRecord/ActorComponentRecord/SceneComponent/PrimitiveComponentRecord.h>
#include "SaveSceneComponent.generated.h"



UCLASS()
class SAVESYSTEM_API USaveActorWithComponentsScene : public USaveActoWithComponent
{
	GENERATED_BODY()

public:

	UPROPERTY()
	bool bSavePrimitivePhysicRepresentation;

protected:

	UPROPERTY()
	TArray<FSceneComponentRecord> SceneComponentsRecord;

	UPROPERTY()
	TArray<FPrimitiveComponentRecord> PrimitiveComponentsRecord;

public:

	USaveActorWithComponentsScene(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	virtual void Serialize(FArchive& Ar) override;

protected:

	//	Begin USaveGameActors interface
	virtual void SaveComponents(TArray<UActorComponent*>& ActorComponents) override;

	virtual void LoadComponents(UWorld* World, UClass* OuterClass = nullptr, FName OuterName = NAME_None) override;
	//	End   USaveGameActors interface

private:

	inline void ProcessingSavePrimitiveComponent(TArray<UActorComponent*>& ActorComponents, int32& i);

	inline void ProcessingSaveSceneComponent(TArray<UActorComponent*>& ActorComponents, int32& i);

protected:

	//	Detailed realization

	FSceneComponentRecord SaveStructSceneComponent(USceneComponent* SceneComponent);

	USceneComponent* LoadStructSceneComponent(const FSceneComponentRecord& SceneRecord, UWorld* World);

	FPrimitiveComponentRecord SaveStructPrimitiveComponent(UPrimitiveComponent* PrimitiveComponent, TArray<FName> BoneNames = TArray<FName>(&NoneName, 1));

	UPrimitiveComponent* LoadStructPrimitiveComponent(const FPrimitiveComponentRecord& PrimitiveRecord, UWorld* World, TArray<FName> BoneNames = TArray<FName>(&NoneName, 1));

private:

	static const FName NoneName;

};