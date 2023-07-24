// Copyright Andrii Berozkin. All Rights Reserved.

#pragma once

#include <CoreMinimal.h>
#include <SaveGame/SaveObject.h>
#include <StructRecord/ActorRecord/ActorRecord.h>
#include <StructRecord/ActorComponentRecord/ActorComponentRecord.h>
#include "SaveActor.generated.h"



DECLARE_CYCLE_STAT(TEXT("IsOnwerSaved"), STAT_OwnerSearch, STATGROUP_SaveSystem);
DECLARE_CYCLE_STAT(TEXT("Actor Save"), STAT_ActorSave, STATGROUP_SaveSystem);
DECLARE_CYCLE_STAT(TEXT("Actor Load"), STAT_ActorLoad, STATGROUP_SaveSystem);
DECLARE_CYCLE_STAT(TEXT("ActorSave : Save Main"), STAT_ActSaveMain, STATGROUP_SaveSystem);
DECLARE_CYCLE_STAT(TEXT("ActorLoad : Load Main"), STAT_ActLoadMain, STATGROUP_SaveSystem);
DECLARE_CYCLE_STAT(TEXT("Actor Records sort : OwnerFirstSort"), STAT_ActOwnerFirstSort, STATGROUP_SaveSystem);

DECLARE_CYCLE_STAT(TEXT("Actor Component : Save"), STAT_ActComponentSave, STATGROUP_SaveSystem);
DECLARE_CYCLE_STAT(TEXT("Actor Component : Load"), STAT_ActComponentLoad, STATGROUP_SaveSystem);

class UActorComponent;

UCLASS()
class SAVESYSTEM_API USaveGameActors : public USaveGameSlot	//	TO DO : Add ActorComponent save (probably better save at "ActorsRecord"), 
																//	can be added as Inherited class from "USaveGameActors" OR "USaveGameSlot"  
																//	OR (Better) Add optional possibility to "USaveGameActors"
{
	GENERATED_BODY()

public:

protected:

	UPROPERTY()
	TArray<FActorRecord> ActorsRecord;

	UPROPERTY(Transient)
	TArray<UActorComponent*> ComponentsToSave;

private:

public:

	USaveGameActors(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	virtual void Serialize(FArchive& Ar) override;

	//	Begin ISaveSystemBase interface
	virtual void Save(TArray<UObject*>& ObjectsPtr) override;

	virtual void Load(UWorld* World) override;
	//	End   SaveSystemBase interface


private:

	inline void ProcessingSaveActor(TArray<UObject*>& ObjectsPtr, int32& i);

protected:

	virtual FActorRecord SaveActor(AActor* ActorPtr);

	virtual AActor* LoadActor(const FActorRecord& ActorRecord, UWorld* World, bool bDeferredSpawn = false);

	virtual bool FindOuterSavableChildObjects(const UObjectBase* Outer, TArray<UObject*>& OutArray, bool bIncludeNestedObjects = false) override;

	//	Begin ActorComponents section

	virtual void SaveComponents(TArray<UActorComponent*>& ActorComponents);

	virtual void LoadComponents(UWorld* World, UClass* OuterClass = nullptr, FName OuterName = NAME_None);

	//	End   ActorComponents section

private:

};