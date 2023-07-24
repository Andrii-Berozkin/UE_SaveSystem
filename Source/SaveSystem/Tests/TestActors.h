// Copyright Andrii Berozkin. All Rights Reserved.

#pragma once

#include <CoreMinimal.h>
#include "TestActors.generated.h"



UCLASS()
class ATestActor : public AActor
{
	GENERATED_BODY()

public:

	UPROPERTY()
	float TestFloat = 0.0f;

private:

public:

	ATestActor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get())
		: Super(ObjectInitializer)
	{

	}

private:
};