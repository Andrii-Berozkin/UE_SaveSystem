// Copyright Andrii Berozkin. All Rights Reserved.

#pragma once

#include <CoreMinimal.h>
#include <StructRecord/ObjectRecord.h>
#include "ActorRecord.generated.h"



USTRUCT(BlueprintType)
struct FActorRecord : public FObjectRecord
{
	GENERATED_BODY()

public:

	UPROPERTY()
		FTransform Transform;

	UPROPERTY()
		AActor* OwnerPtr;

	UPROPERTY()
		UClass* OwnerClass;

	UPROPERTY()
		FName OwnerName;

	UPROPERTY()
		bool bIsHidden;

	UPROPERTY()
		TArray<FObjectRecord> Objects;

private:

public:

	FActorRecord()
		: Super(), Transform(FTransform()), OwnerPtr(nullptr), OwnerClass(nullptr), OwnerName(NAME_None), bIsHidden(false), Objects()
	{
	}

	FActorRecord(const FActorRecord& ActorRecord)
		:Super(ActorRecord),
		Transform(ActorRecord.Transform),
		OwnerPtr(ActorRecord.OwnerPtr),
		OwnerClass(ActorRecord.OwnerClass),
		OwnerName(ActorRecord.OwnerName),
		bIsHidden(ActorRecord.bIsHidden),
		Objects(ActorRecord.Objects)
	{}

	FActorRecord(const FObjectRecord& ObjectRecord)
		: Super(ObjectRecord), Transform(FTransform::Identity), OwnerPtr(nullptr), OwnerClass(nullptr), OwnerName(NAME_None), bIsHidden(false), Objects()
	{
	}

	virtual ~FActorRecord()
	{
	}

	FORCEINLINE virtual bool IsEmpty() const { return Super::IsEmpty() && !Transform.IsValid(); }

	inline FActorRecord& operator=(const FObjectRecord& RightItem)
	{
		Class = RightItem.Class;
		Name = RightItem.Name;
		OuterPtr = RightItem.OuterPtr;
		OuterClass = RightItem.OuterClass;
		OuterName = RightItem.OuterName;
		SelfPointer = RightItem.SelfPointer;
		BinaryData = RightItem.BinaryData;
		return *this;
	}

	inline friend FArchive& operator<<(FArchive& Ar, FActorRecord& ActorRecord)
	{
		FObjectRecord TempRec(ActorRecord);
		Ar << TempRec;
		if (Ar.IsLoading()) { ActorRecord = TempRec; }

		Ar << ActorRecord.Transform;
		Ar << ActorRecord.OwnerPtr;
		Ar << ActorRecord.OwnerClass;
		Ar << ActorRecord.OwnerName;
		Ar << ActorRecord.bIsHidden;
		Ar << ActorRecord.Objects;
		return Ar;
	}

private:
};