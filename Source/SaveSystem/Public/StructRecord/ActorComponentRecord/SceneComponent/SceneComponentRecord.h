// Copyright Andrii Berozkin. All Rights Reserved.

#pragma once

#include <CoreMinimal.h>
#include <StructRecord/ActorComponentRecord/ActorComponentRecord.h>
#include "SceneComponentRecord.generated.h"



USTRUCT(BlueprintType)
struct FSceneComponentRecord : public FActorComponentRecord
{
	GENERATED_BODY()

public:

	UPROPERTY()
		FTransform Transform;

	UPROPERTY()
		/* TO DO : must be added casr for nullptr to prevent USaveGame Wrning. Add option to find Parent with class and name */
		UObject* AttachParentPtr;

	UPROPERTY()
		UClass* AttachParentClass;

	UPROPERTY()
		FName AttachParentName;

	UPROPERTY()
		FName AttachSocketName;

	UPROPERTY()
		bool bIsHidden;

public:

	FSceneComponentRecord()
		: Super(), Transform(FTransform::Identity), AttachParentPtr(nullptr), AttachParentClass(nullptr), AttachParentName(NAME_None), AttachSocketName(NAME_None), bIsHidden(false)
	{
	}

	FSceneComponentRecord(const FSceneComponentRecord& SceneComponentRecord)
		:Super(SceneComponentRecord),
		Transform(SceneComponentRecord.Transform),
		AttachParentPtr(SceneComponentRecord.AttachParentPtr),
		AttachParentClass(SceneComponentRecord.AttachParentClass),
		AttachParentName(SceneComponentRecord.AttachParentName),
		AttachSocketName(SceneComponentRecord.AttachSocketName),
		bIsHidden(SceneComponentRecord.bIsHidden)
	{}

	FSceneComponentRecord(const FActorComponentRecord& ActorComponentRecord)
		:Super(ActorComponentRecord),
		Transform(FTransform::Identity),
		AttachParentPtr(nullptr),
		AttachParentClass(nullptr),
		AttachParentName(NAME_None),
		AttachSocketName(NAME_None),
		bIsHidden(false)
	{}

	virtual ~FSceneComponentRecord()
	{}

	FORCEINLINE virtual bool IsEmpty() const { return Super::IsEmpty(); }

	inline FSceneComponentRecord& operator=(const FActorComponentRecord& RightItem)
	{
		Super::operator=(RightItem);
		OwnerPtr = RightItem.OwnerPtr;
		OwnerClass = RightItem.OwnerClass;
		OwnerName = RightItem.OwnerName;
		bIsDefaultSubobject = RightItem.bIsDefaultSubobject;
		Objects = RightItem.Objects;
		return *this;
	}

	inline friend FArchive& operator<<(FArchive& Ar, FSceneComponentRecord& SceneComponentRecord)
	{
		FActorComponentRecord TempRec(SceneComponentRecord);
		Ar << TempRec;
		if (Ar.IsLoading()) { SceneComponentRecord = TempRec; }

		Ar << SceneComponentRecord.Transform;
		Ar << SceneComponentRecord.AttachParentPtr;
		Ar << SceneComponentRecord.AttachParentClass;
		Ar << SceneComponentRecord.AttachParentName;
		Ar << SceneComponentRecord.AttachSocketName;
		Ar << SceneComponentRecord.bIsHidden;
		return Ar;
	}
};