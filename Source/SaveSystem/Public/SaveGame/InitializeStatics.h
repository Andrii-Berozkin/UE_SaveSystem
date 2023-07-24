// Copyright Andrii Berozkin. All Rights Reserved.

#pragma once

#include <CoreMinimal.h>
#include <Kismet/BlueprintFunctionLibrary.h>
#include "InitializeStatics.generated.h"



struct FObjectRecord;
struct FActorRecord;
struct FActorComponentRecord;

UCLASS()
class SAVESYSTEM_API UInitializeStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	//UFUNCTION()
	static UObject* InitializeObject(const struct FObjectRecord& ObjectRecord, UWorld* WorldPtr, UObject* OptionalOuter = nullptr);

	static UObject* InitializeObjectChecked(const FObjectRecord& ObjectRecord, UWorld* WorldPtr, UObject* OptionalOuter = nullptr);

	static AActor* InitializeActor(const FActorRecord& ActorRecord, UWorld* World, bool bDeferredSpawn = false);

	static AActor* InitializeActorChecked(const FActorRecord& ActorRecord, UWorld* World, bool bDeferredSpawn = false);

	static UActorComponent* InitializeActorComponent(const FActorComponentRecord& ActorComponentRecord, UWorld* World);

	static UActorComponent* InitializeActorComponentChecked(const FActorComponentRecord& ActorComponentRecord, UWorld* World);
};