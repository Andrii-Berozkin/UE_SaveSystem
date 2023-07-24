// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveSystem/Public/StructRecord/ActorComponentRecord/SceneComponent/PrimitiveComponentRecord.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePrimitiveComponentRecord() {}
// Cross Module References
	SAVESYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FPrimitiveComponentRecord();
	UPackage* Z_Construct_UPackage__Script_SaveSystem();
	SAVESYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FSceneComponentRecord();
	SAVESYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FBodyInstanceRecord();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FBodyInstance();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References

static_assert(std::is_polymorphic<FPrimitiveComponentRecord>() == std::is_polymorphic<FSceneComponentRecord>(), "USTRUCT FPrimitiveComponentRecord cannot be polymorphic unless super FSceneComponentRecord is polymorphic");

class UScriptStruct* FPrimitiveComponentRecord::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern SAVESYSTEM_API uint32 Get_Z_Construct_UScriptStruct_FPrimitiveComponentRecord_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FPrimitiveComponentRecord, Z_Construct_UPackage__Script_SaveSystem(), TEXT("PrimitiveComponentRecord"), sizeof(FPrimitiveComponentRecord), Get_Z_Construct_UScriptStruct_FPrimitiveComponentRecord_Hash());
	}
	return Singleton;
}
template<> SAVESYSTEM_API UScriptStruct* StaticStruct<FPrimitiveComponentRecord>()
{
	return FPrimitiveComponentRecord::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FPrimitiveComponentRecord(FPrimitiveComponentRecord::StaticStruct, TEXT("/Script/SaveSystem"), TEXT("PrimitiveComponentRecord"), false, nullptr, nullptr);
static struct FScriptStruct_SaveSystem_StaticRegisterNativesFPrimitiveComponentRecord
{
	FScriptStruct_SaveSystem_StaticRegisterNativesFPrimitiveComponentRecord()
	{
		UScriptStruct::DeferCppStructOps<FPrimitiveComponentRecord>(FName(TEXT("PrimitiveComponentRecord")));
	}
} ScriptStruct_SaveSystem_StaticRegisterNativesFPrimitiveComponentRecord;
	struct Z_Construct_UScriptStruct_FPrimitiveComponentRecord_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsWelded_MetaData[];
#endif
		static void NewProp_bIsWelded_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsWelded;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_BoneToBodyInst_ValueProp;
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_BoneToBodyInst_Key_KeyProp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BoneToBodyInst_MetaData[];
#endif
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_BoneToBodyInst;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPrimitiveComponentRecord_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/StructRecord/ActorComponentRecord/SceneComponent/PrimitiveComponentRecord.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPrimitiveComponentRecord_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPrimitiveComponentRecord>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPrimitiveComponentRecord_Statics::NewProp_bIsWelded_MetaData[] = {
		{ "Comment", "/*\x09Uses to define primitive component welding simulation\n\x09*\x09""False by default*/" },
		{ "ModuleRelativePath", "Public/StructRecord/ActorComponentRecord/SceneComponent/PrimitiveComponentRecord.h" },
		{ "ToolTip", "Uses to define primitive component welding simulation\n*       False by default" },
	};
#endif
	void Z_Construct_UScriptStruct_FPrimitiveComponentRecord_Statics::NewProp_bIsWelded_SetBit(void* Obj)
	{
		((FPrimitiveComponentRecord*)Obj)->bIsWelded = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPrimitiveComponentRecord_Statics::NewProp_bIsWelded = { "bIsWelded", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FPrimitiveComponentRecord), &Z_Construct_UScriptStruct_FPrimitiveComponentRecord_Statics::NewProp_bIsWelded_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FPrimitiveComponentRecord_Statics::NewProp_bIsWelded_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPrimitiveComponentRecord_Statics::NewProp_bIsWelded_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPrimitiveComponentRecord_Statics::NewProp_BoneToBodyInst_ValueProp = { "BoneToBodyInst", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, Z_Construct_UScriptStruct_FBodyInstanceRecord, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FPrimitiveComponentRecord_Statics::NewProp_BoneToBodyInst_Key_KeyProp = { "BoneToBodyInst_Key", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPrimitiveComponentRecord_Statics::NewProp_BoneToBodyInst_MetaData[] = {
		{ "ModuleRelativePath", "Public/StructRecord/ActorComponentRecord/SceneComponent/PrimitiveComponentRecord.h" },
	};
#endif
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FPrimitiveComponentRecord_Statics::NewProp_BoneToBodyInst = { "BoneToBodyInst", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPrimitiveComponentRecord, BoneToBodyInst), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FPrimitiveComponentRecord_Statics::NewProp_BoneToBodyInst_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPrimitiveComponentRecord_Statics::NewProp_BoneToBodyInst_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPrimitiveComponentRecord_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPrimitiveComponentRecord_Statics::NewProp_bIsWelded,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPrimitiveComponentRecord_Statics::NewProp_BoneToBodyInst_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPrimitiveComponentRecord_Statics::NewProp_BoneToBodyInst_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPrimitiveComponentRecord_Statics::NewProp_BoneToBodyInst,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPrimitiveComponentRecord_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SaveSystem,
		Z_Construct_UScriptStruct_FSceneComponentRecord,
		&NewStructOps,
		"PrimitiveComponentRecord",
		sizeof(FPrimitiveComponentRecord),
		alignof(FPrimitiveComponentRecord),
		Z_Construct_UScriptStruct_FPrimitiveComponentRecord_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPrimitiveComponentRecord_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FPrimitiveComponentRecord_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPrimitiveComponentRecord_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FPrimitiveComponentRecord()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FPrimitiveComponentRecord_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_SaveSystem();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("PrimitiveComponentRecord"), sizeof(FPrimitiveComponentRecord), Get_Z_Construct_UScriptStruct_FPrimitiveComponentRecord_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FPrimitiveComponentRecord_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FPrimitiveComponentRecord_Hash() { return 3955829326U; }
class UScriptStruct* FBodyInstanceRecord::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern SAVESYSTEM_API uint32 Get_Z_Construct_UScriptStruct_FBodyInstanceRecord_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FBodyInstanceRecord, Z_Construct_UPackage__Script_SaveSystem(), TEXT("BodyInstanceRecord"), sizeof(FBodyInstanceRecord), Get_Z_Construct_UScriptStruct_FBodyInstanceRecord_Hash());
	}
	return Singleton;
}
template<> SAVESYSTEM_API UScriptStruct* StaticStruct<FBodyInstanceRecord>()
{
	return FBodyInstanceRecord::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FBodyInstanceRecord(FBodyInstanceRecord::StaticStruct, TEXT("/Script/SaveSystem"), TEXT("BodyInstanceRecord"), false, nullptr, nullptr);
static struct FScriptStruct_SaveSystem_StaticRegisterNativesFBodyInstanceRecord
{
	FScriptStruct_SaveSystem_StaticRegisterNativesFBodyInstanceRecord()
	{
		UScriptStruct::DeferCppStructOps<FBodyInstanceRecord>(FName(TEXT("BodyInstanceRecord")));
	}
} ScriptStruct_SaveSystem_StaticRegisterNativesFBodyInstanceRecord;
	struct Z_Construct_UScriptStruct_FBodyInstanceRecord_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BodyInstance_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_BodyInstance;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BodyTransform_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_BodyTransform;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_UnrealWorldLinearVelocity_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_UnrealWorldLinearVelocity;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_UnrealWorldAngularVelocityRadians_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_UnrealWorldAngularVelocityRadians;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBodyInstanceRecord_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/StructRecord/ActorComponentRecord/SceneComponent/PrimitiveComponentRecord.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FBodyInstanceRecord_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FBodyInstanceRecord>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBodyInstanceRecord_Statics::NewProp_BodyInstance_MetaData[] = {
		{ "ModuleRelativePath", "Public/StructRecord/ActorComponentRecord/SceneComponent/PrimitiveComponentRecord.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FBodyInstanceRecord_Statics::NewProp_BodyInstance = { "BodyInstance", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FBodyInstanceRecord, BodyInstance), Z_Construct_UScriptStruct_FBodyInstance, METADATA_PARAMS(Z_Construct_UScriptStruct_FBodyInstanceRecord_Statics::NewProp_BodyInstance_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBodyInstanceRecord_Statics::NewProp_BodyInstance_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBodyInstanceRecord_Statics::NewProp_BodyTransform_MetaData[] = {
		{ "ModuleRelativePath", "Public/StructRecord/ActorComponentRecord/SceneComponent/PrimitiveComponentRecord.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FBodyInstanceRecord_Statics::NewProp_BodyTransform = { "BodyTransform", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FBodyInstanceRecord, BodyTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(Z_Construct_UScriptStruct_FBodyInstanceRecord_Statics::NewProp_BodyTransform_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBodyInstanceRecord_Statics::NewProp_BodyTransform_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBodyInstanceRecord_Statics::NewProp_UnrealWorldLinearVelocity_MetaData[] = {
		{ "ModuleRelativePath", "Public/StructRecord/ActorComponentRecord/SceneComponent/PrimitiveComponentRecord.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FBodyInstanceRecord_Statics::NewProp_UnrealWorldLinearVelocity = { "UnrealWorldLinearVelocity", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FBodyInstanceRecord, UnrealWorldLinearVelocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FBodyInstanceRecord_Statics::NewProp_UnrealWorldLinearVelocity_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBodyInstanceRecord_Statics::NewProp_UnrealWorldLinearVelocity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBodyInstanceRecord_Statics::NewProp_UnrealWorldAngularVelocityRadians_MetaData[] = {
		{ "ModuleRelativePath", "Public/StructRecord/ActorComponentRecord/SceneComponent/PrimitiveComponentRecord.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FBodyInstanceRecord_Statics::NewProp_UnrealWorldAngularVelocityRadians = { "UnrealWorldAngularVelocityRadians", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FBodyInstanceRecord, UnrealWorldAngularVelocityRadians), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FBodyInstanceRecord_Statics::NewProp_UnrealWorldAngularVelocityRadians_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBodyInstanceRecord_Statics::NewProp_UnrealWorldAngularVelocityRadians_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FBodyInstanceRecord_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBodyInstanceRecord_Statics::NewProp_BodyInstance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBodyInstanceRecord_Statics::NewProp_BodyTransform,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBodyInstanceRecord_Statics::NewProp_UnrealWorldLinearVelocity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBodyInstanceRecord_Statics::NewProp_UnrealWorldAngularVelocityRadians,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FBodyInstanceRecord_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SaveSystem,
		nullptr,
		&NewStructOps,
		"BodyInstanceRecord",
		sizeof(FBodyInstanceRecord),
		alignof(FBodyInstanceRecord),
		Z_Construct_UScriptStruct_FBodyInstanceRecord_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBodyInstanceRecord_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FBodyInstanceRecord_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBodyInstanceRecord_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FBodyInstanceRecord()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FBodyInstanceRecord_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_SaveSystem();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("BodyInstanceRecord"), sizeof(FBodyInstanceRecord), Get_Z_Construct_UScriptStruct_FBodyInstanceRecord_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FBodyInstanceRecord_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FBodyInstanceRecord_Hash() { return 2817141663U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
