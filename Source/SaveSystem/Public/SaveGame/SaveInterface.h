// Copyright Andrii Berozkin. All Rights Reserved.

#pragma once

#include <CoreMinimal.h>
#include "SaveInterface.generated.h"



DECLARE_STATS_GROUP(TEXT("Save system group"), STATGROUP_SaveSystem, STATCAT_Advanced);

UINTERFACE(MinimalAPI, Blueprintable)
class USaveSystemBase : public UInterface
{
	GENERATED_BODY()
};

class ISaveSystemBase
{
	GENERATED_BODY()

public:

	virtual void Save(TArray<UObject*>& ObjectsPtr) = 0;
	virtual void Load(UWorld* World) = 0;
};