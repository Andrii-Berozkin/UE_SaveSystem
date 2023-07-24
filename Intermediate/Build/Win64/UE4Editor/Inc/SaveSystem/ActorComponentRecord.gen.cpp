// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveSystem/Public/StructRecord/ActorComponentRecord/ActorComponentRecord.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeActorComponentRecord() {}
// Cross Module References
	SAVESYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FActorComponentRecord();
	UPackage* Z_Construct_UPackage__Script_SaveSystem();
	SAVESYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FObjectRecord();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
// End Cross Module References

static_assert(std::is_polymorphic<FActorComponentRecord>() == std::is_polymorphic<FObjectRecord>(), "USTRUCT FActorComponentRecord cannot be polymorphic unless super FObjectRecord is polymorphic");

class UScriptStruct* FActorComponentRecord::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern SAVESYSTEM_API uint32 Get_Z_Construct_UScriptStruct_FActorComponentRecord_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FActorComponentRecord, Z_Construct_UPackage__Script_SaveSystem(), TEXT("ActorComponentRecord"), sizeof(FActorComponentRecord), Get_Z_Construct_UScriptStruct_FActorComponentRecord_Hash());
	}
	return Singleton;
}
template<> SAVESYSTEM_API UScriptStruct* StaticStruct<FActorComponentRecord>()
{
	return FActorComponentRecord::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FActorComponentRecord(FActorComponentRecord::StaticStruct, TEXT("/Script/SaveSystem"), TEXT("ActorComponentRecord"), false, nullptr, nullptr);
static struct FScriptStruct_SaveSystem_StaticRegisterNativesFActorComponentRecord
{
	FScriptStruct_SaveSystem_StaticRegisterNativesFActorComponentRecord()
	{
		UScriptStruct::DeferCppStructOps<FActorComponentRecord>(FName(TEXT("ActorComponentRecord")));
	}
} ScriptStruct_SaveSystem_StaticRegisterNativesFActorComponentRecord;
	struct Z_Construct_UScriptStruct_FActorComponentRecord_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OwnerPtr_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OwnerPtr;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OwnerClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_OwnerClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OwnerName_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_OwnerName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsDefaultSubobject_MetaData[];
#endif
		static void NewProp_bIsDefaultSubobject_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsDefaultSubobject;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Objects_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Objects_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Objects;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FActorComponentRecord_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/StructRecord/ActorComponentRecord/ActorComponentRecord.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FActorComponentRecord_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FActorComponentRecord>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FActorComponentRecord_Statics::NewProp_OwnerPtr_MetaData[] = {
		{ "ModuleRelativePath", "Public/StructRecord/ActorComponentRecord/ActorComponentRecord.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FActorComponentRecord_Statics::NewProp_OwnerPtr = { "OwnerPtr", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FActorComponentRecord, OwnerPtr), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FActorComponentRecord_Statics::NewProp_OwnerPtr_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActorComponentRecord_Statics::NewProp_OwnerPtr_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FActorComponentRecord_Statics::NewProp_OwnerClass_MetaData[] = {
		{ "ModuleRelativePath", "Public/StructRecord/ActorComponentRecord/ActorComponentRecord.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FActorComponentRecord_Statics::NewProp_OwnerClass = { "OwnerClass", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FActorComponentRecord, OwnerClass), Z_Construct_UClass_UObject_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UScriptStruct_FActorComponentRecord_Statics::NewProp_OwnerClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActorComponentRecord_Statics::NewProp_OwnerClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FActorComponentRecord_Statics::NewProp_OwnerName_MetaData[] = {
		{ "ModuleRelativePath", "Public/StructRecord/ActorComponentRecord/ActorComponentRecord.h" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FActorComponentRecord_Statics::NewProp_OwnerName = { "OwnerName", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FActorComponentRecord, OwnerName), METADATA_PARAMS(Z_Construct_UScriptStruct_FActorComponentRecord_Statics::NewProp_OwnerName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActorComponentRecord_Statics::NewProp_OwnerName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FActorComponentRecord_Statics::NewProp_bIsDefaultSubobject_MetaData[] = {
		{ "ModuleRelativePath", "Public/StructRecord/ActorComponentRecord/ActorComponentRecord.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FActorComponentRecord_Statics::NewProp_bIsDefaultSubobject_SetBit(void* Obj)
	{
		((FActorComponentRecord*)Obj)->bIsDefaultSubobject = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FActorComponentRecord_Statics::NewProp_bIsDefaultSubobject = { "bIsDefaultSubobject", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FActorComponentRecord), &Z_Construct_UScriptStruct_FActorComponentRecord_Statics::NewProp_bIsDefaultSubobject_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FActorComponentRecord_Statics::NewProp_bIsDefaultSubobject_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActorComponentRecord_Statics::NewProp_bIsDefaultSubobject_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FActorComponentRecord_Statics::NewProp_Objects_Inner = { "Objects", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FObjectRecord, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FActorComponentRecord_Statics::NewProp_Objects_MetaData[] = {
		{ "ModuleRelativePath", "Public/StructRecord/ActorComponentRecord/ActorComponentRecord.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FActorComponentRecord_Statics::NewProp_Objects = { "Objects", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FActorComponentRecord, Objects), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FActorComponentRecord_Statics::NewProp_Objects_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActorComponentRecord_Statics::NewProp_Objects_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FActorComponentRecord_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActorComponentRecord_Statics::NewProp_OwnerPtr,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActorComponentRecord_Statics::NewProp_OwnerClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActorComponentRecord_Statics::NewProp_OwnerName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActorComponentRecord_Statics::NewProp_bIsDefaultSubobject,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActorComponentRecord_Statics::NewProp_Objects_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActorComponentRecord_Statics::NewProp_Objects,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FActorComponentRecord_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SaveSystem,
		Z_Construct_UScriptStruct_FObjectRecord,
		&NewStructOps,
		"ActorComponentRecord",
		sizeof(FActorComponentRecord),
		alignof(FActorComponentRecord),
		Z_Construct_UScriptStruct_FActorComponentRecord_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActorComponentRecord_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FActorComponentRecord_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActorComponentRecord_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FActorComponentRecord()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FActorComponentRecord_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_SaveSystem();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("ActorComponentRecord"), sizeof(FActorComponentRecord), Get_Z_Construct_UScriptStruct_FActorComponentRecord_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FActorComponentRecord_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FActorComponentRecord_Hash() { return 888906677U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
