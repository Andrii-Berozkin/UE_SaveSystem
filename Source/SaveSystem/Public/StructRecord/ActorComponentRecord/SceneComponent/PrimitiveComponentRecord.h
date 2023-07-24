// Copyright Andrii Berozkin. All Rights Reserved.

#pragma once

#include <CoreMinimal.h>
#include <StructRecord/ActorComponentRecord/SceneComponent/SceneComponentRecord.h>
#include "PrimitiveComponentRecord.generated.h"



USTRUCT(BlueprintType)
struct FBodyInstanceRecord
{
	GENERATED_BODY()
public:

	UPROPERTY()
		FBodyInstance BodyInstance;

	UPROPERTY()
		FTransform BodyTransform;

	UPROPERTY()
		FVector UnrealWorldLinearVelocity;

	UPROPERTY()
		FVector UnrealWorldAngularVelocityRadians;

	FBodyInstanceRecord()
		: BodyInstance(FBodyInstance()), BodyTransform(FTransform::Identity), UnrealWorldLinearVelocity(FVector::ZeroVector), UnrealWorldAngularVelocityRadians(FVector::ZeroVector)
	{
	}

	FBodyInstanceRecord(FBodyInstance BodyInstance, FTransform BodyTransform, FVector Linearvelocity, FVector AngularVelocityRadians)
		: BodyInstance(BodyInstance), BodyTransform(BodyTransform), UnrealWorldLinearVelocity(Linearvelocity), UnrealWorldAngularVelocityRadians(AngularVelocityRadians)
	{

	}

	virtual ~FBodyInstanceRecord() {};

	inline friend FArchive& operator<<(FArchive& Ar, FBodyInstanceRecord& BodyInstRecord)
	{
		BodyInstRecord.BodyInstance.StaticStruct()->SerializeItem(Ar, &BodyInstRecord.BodyInstance, nullptr);

		Ar << BodyInstRecord.BodyTransform;
		Ar << BodyInstRecord.UnrealWorldLinearVelocity;
		Ar << BodyInstRecord.UnrealWorldAngularVelocityRadians;
		return Ar;
	}
};

USTRUCT(BlueprintType)
struct FPrimitiveComponentRecord : public FSceneComponentRecord
{
	GENERATED_BODY()

public:

	/*	Uses to define primitive component welding simulation
	*	False by default*/
	UPROPERTY()
		bool bIsWelded;

	UPROPERTY()
		TMap<FName, FBodyInstanceRecord> BoneToBodyInst;

public:

	FPrimitiveComponentRecord()
		: Super(), bIsWelded(false), BoneToBodyInst()
	{
	}

	FPrimitiveComponentRecord(const FPrimitiveComponentRecord& PrimitiveComponentRecord)
		: Super(PrimitiveComponentRecord),
		bIsWelded(PrimitiveComponentRecord.bIsWelded),
		BoneToBodyInst(PrimitiveComponentRecord.BoneToBodyInst)
	{}

	FPrimitiveComponentRecord(const FSceneComponentRecord& SceneComponentRecord)
		: Super(SceneComponentRecord),
		bIsWelded(false),
		BoneToBodyInst()
	{}

	virtual ~FPrimitiveComponentRecord()
	{}

	FORCEINLINE virtual bool IsEmpty() const { return Super::IsEmpty(); }

	inline FPrimitiveComponentRecord& operator=(const FSceneComponentRecord& RightItem)
	{
		Super::operator=(RightItem);
		Transform = RightItem.Transform;
		AttachParentPtr = RightItem.AttachParentPtr;
		AttachParentClass = RightItem.AttachParentClass;
		AttachParentName = RightItem.AttachParentName;
		AttachSocketName = RightItem.AttachSocketName;
		bIsHidden = RightItem.bIsHidden;
		return *this;
	}

	inline friend FArchive& operator<<(FArchive& Ar, FPrimitiveComponentRecord& PrimitiveComponentRecord)
	{
		FSceneComponentRecord TempRec(PrimitiveComponentRecord);
		Ar << TempRec;
		if (Ar.IsLoading()) { PrimitiveComponentRecord = TempRec; }

		Ar << PrimitiveComponentRecord.bIsWelded;
		Ar << PrimitiveComponentRecord.BoneToBodyInst;
		return Ar;
	}
};