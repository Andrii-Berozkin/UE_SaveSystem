// Copyright Andrii Berozkin. All Rights Reserved.

#pragma once

#include <CoreMinimal.h>
#include "ObjectRecord.generated.h"

USTRUCT(BlueprintType, Blueprintable)
struct FObjectRecord
{
	GENERATED_BODY()

public:

	UPROPERTY()
	UClass* Class;

	UPROPERTY()
	FName Name;

	UPROPERTY()
	UObject* OuterPtr;

	UPROPERTY()
	UClass* OuterClass;

	UPROPERTY()
	FName OuterName;

	UPROPERTY()
	UObject* SelfPointer;

	UPROPERTY()
	TArray<uint8> BinaryData;

protected:

private:

public:

	FObjectRecord()
		: Class(nullptr), Name(NAME_None), OuterPtr(nullptr), OuterClass(nullptr), OuterName(NAME_None), SelfPointer(nullptr), BinaryData()
	{

	}

	FObjectRecord(const FObjectRecord& ObjectRecord)
		: Class(ObjectRecord.Class),
		Name(ObjectRecord.Name),
		OuterPtr(ObjectRecord.OuterPtr),
		OuterClass(ObjectRecord.OuterClass),
		OuterName(ObjectRecord.OuterName),
		SelfPointer(ObjectRecord.SelfPointer),
		BinaryData(ObjectRecord.BinaryData)
	{}

	virtual ~FObjectRecord()
	{}

	FORCEINLINE virtual bool IsEmpty() const { return Class == nullptr && Name.IsNone() && OuterPtr == nullptr && OuterPtr == nullptr && BinaryData.Num() <= 0; }

	inline bool operator==(const FObjectRecord& RightItem)
	{
		return Class == RightItem.Class &&
			Name == RightItem.Name &&
			OuterPtr == RightItem.OuterPtr &&
			SelfPointer == RightItem.SelfPointer &&
			BinaryData == RightItem.BinaryData;
	}

	inline friend FArchive& operator<<(FArchive& Ar, FObjectRecord& ObjectRecord)
	{
		Ar << ObjectRecord.Class;
		Ar << ObjectRecord.Name;
		Ar << ObjectRecord.OuterPtr;
		Ar << ObjectRecord.OuterClass;
		Ar << ObjectRecord.OuterName;
		Ar << ObjectRecord.SelfPointer;
		Ar << ObjectRecord.BinaryData;
		return Ar;
	}

private:
};