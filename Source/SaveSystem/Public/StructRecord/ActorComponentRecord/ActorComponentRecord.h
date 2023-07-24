// Copyright Andrii Berozkin. All Rights Reserved.

#pragma once

#include <CoreMinimal.h>
#include <SaveSystem/Public/StructRecord/ObjectRecord.h>
#include "ActorComponentRecord.generated.h"



USTRUCT(BlueprintType)
struct FActorComponentRecord : public FObjectRecord
{
	GENERATED_BODY()

public:

	UPROPERTY()
		AActor* OwnerPtr;

	UPROPERTY()
		UClass* OwnerClass;

	UPROPERTY()
		FName OwnerName;

	UPROPERTY()
		bool bIsDefaultSubobject;

	UPROPERTY()
		TArray<FObjectRecord> Objects;

public:

	FActorComponentRecord()
		: Super(), OwnerPtr(nullptr), OwnerClass(nullptr), OwnerName(NAME_None), bIsDefaultSubobject(false), Objects()
	{
	}

	FActorComponentRecord(const FActorComponentRecord& ActorComponentRecord)
		:Super(ActorComponentRecord),
		OwnerPtr(ActorComponentRecord.OwnerPtr),
		OwnerClass(ActorComponentRecord.OwnerClass),
		OwnerName(ActorComponentRecord.OwnerName),
		bIsDefaultSubobject(ActorComponentRecord.bIsDefaultSubobject),
		Objects(ActorComponentRecord.Objects)
	{}

	FActorComponentRecord(const FObjectRecord& ObjectRecord)
		: Super(ObjectRecord), OwnerPtr(nullptr), OwnerClass(nullptr), OwnerName(NAME_None), bIsDefaultSubobject(false), Objects()
	{}

	virtual ~FActorComponentRecord()
	{}

	FORCEINLINE virtual bool IsEmpty() const { return Super::IsEmpty(); }

	inline FActorComponentRecord& operator=(const FObjectRecord& RightItem)
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

	inline friend FArchive& operator<<(FArchive& Ar, FActorComponentRecord& ActorComponentRecord)
	{
		FObjectRecord TempRec(ActorComponentRecord);
		Ar << TempRec;
		if (Ar.IsLoading()) { ActorComponentRecord = TempRec; }

		Ar << ActorComponentRecord.OwnerPtr;
		Ar << ActorComponentRecord.OwnerClass;
		Ar << ActorComponentRecord.OwnerName;
		Ar << ActorComponentRecord.bIsDefaultSubobject;
		Ar << ActorComponentRecord.Objects;
		return Ar;
	}
};