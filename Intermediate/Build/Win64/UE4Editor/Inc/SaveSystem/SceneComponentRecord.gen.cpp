// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveSystem/Public/StructRecord/ActorComponentRecord/SceneComponent/SceneComponentRecord.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSceneComponentRecord() {}
// Cross Module References
	SAVESYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FSceneComponentRecord();
	UPackage* Z_Construct_UPackage__Script_SaveSystem();
	SAVESYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FActorComponentRecord();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
// End Cross Module References

static_assert(std::is_polymorphic<FSceneComponentRecord>() == std::is_polymorphic<FActorComponentRecord>(), "USTRUCT FSceneComponentRecord cannot be polymorphic unless super FActorComponentRecord is polymorphic");

class UScriptStruct* FSceneComponentRecord::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern SAVESYSTEM_API uint32 Get_Z_Construct_UScriptStruct_FSceneComponentRecord_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FSceneComponentRecord, Z_Construct_UPackage__Script_SaveSystem(), TEXT("SceneComponentRecord"), sizeof(FSceneComponentRecord), Get_Z_Construct_UScriptStruct_FSceneComponentRecord_Hash());
	}
	return Singleton;
}
template<> SAVESYSTEM_API UScriptStruct* StaticStruct<FSceneComponentRecord>()
{
	return FSceneComponentRecord::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FSceneComponentRecord(FSceneComponentRecord::StaticStruct, TEXT("/Script/SaveSystem"), TEXT("SceneComponentRecord"), false, nullptr, nullptr);
static struct FScriptStruct_SaveSystem_StaticRegisterNativesFSceneComponentRecord
{
	FScriptStruct_SaveSystem_StaticRegisterNativesFSceneComponentRecord()
	{
		UScriptStruct::DeferCppStructOps<FSceneComponentRecord>(FName(TEXT("SceneComponentRecord")));
	}
} ScriptStruct_SaveSystem_StaticRegisterNativesFSceneComponentRecord;
	struct Z_Construct_UScriptStruct_FSceneComponentRecord_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Transform_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Transform;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttachParentPtr_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AttachParentPtr;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttachParentClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_AttachParentClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttachParentName_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_AttachParentName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttachSocketName_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_AttachSocketName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsHidden_MetaData[];
#endif
		static void NewProp_bIsHidden_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsHidden;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/StructRecord/ActorComponentRecord/SceneComponent/SceneComponentRecord.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSceneComponentRecord>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::NewProp_Transform_MetaData[] = {
		{ "ModuleRelativePath", "Public/StructRecord/ActorComponentRecord/SceneComponent/SceneComponentRecord.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::NewProp_Transform = { "Transform", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSceneComponentRecord, Transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::NewProp_Transform_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::NewProp_Transform_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::NewProp_AttachParentPtr_MetaData[] = {
		{ "Comment", "/* TO DO : must be added casr for nullptr to prevent USaveGame Wrning. Add option to find Parent with class and name */" },
		{ "ModuleRelativePath", "Public/StructRecord/ActorComponentRecord/SceneComponent/SceneComponentRecord.h" },
		{ "ToolTip", "TO DO : must be added casr for nullptr to prevent USaveGame Wrning. Add option to find Parent with class and name" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::NewProp_AttachParentPtr = { "AttachParentPtr", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSceneComponentRecord, AttachParentPtr), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::NewProp_AttachParentPtr_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::NewProp_AttachParentPtr_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::NewProp_AttachParentClass_MetaData[] = {
		{ "ModuleRelativePath", "Public/StructRecord/ActorComponentRecord/SceneComponent/SceneComponentRecord.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::NewProp_AttachParentClass = { "AttachParentClass", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSceneComponentRecord, AttachParentClass), Z_Construct_UClass_UObject_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::NewProp_AttachParentClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::NewProp_AttachParentClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::NewProp_AttachParentName_MetaData[] = {
		{ "ModuleRelativePath", "Public/StructRecord/ActorComponentRecord/SceneComponent/SceneComponentRecord.h" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::NewProp_AttachParentName = { "AttachParentName", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSceneComponentRecord, AttachParentName), METADATA_PARAMS(Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::NewProp_AttachParentName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::NewProp_AttachParentName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::NewProp_AttachSocketName_MetaData[] = {
		{ "ModuleRelativePath", "Public/StructRecord/ActorComponentRecord/SceneComponent/SceneComponentRecord.h" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::NewProp_AttachSocketName = { "AttachSocketName", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSceneComponentRecord, AttachSocketName), METADATA_PARAMS(Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::NewProp_AttachSocketName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::NewProp_AttachSocketName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::NewProp_bIsHidden_MetaData[] = {
		{ "ModuleRelativePath", "Public/StructRecord/ActorComponentRecord/SceneComponent/SceneComponentRecord.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::NewProp_bIsHidden_SetBit(void* Obj)
	{
		((FSceneComponentRecord*)Obj)->bIsHidden = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::NewProp_bIsHidden = { "bIsHidden", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FSceneComponentRecord), &Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::NewProp_bIsHidden_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::NewProp_bIsHidden_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::NewProp_bIsHidden_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::NewProp_Transform,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::NewProp_AttachParentPtr,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::NewProp_AttachParentClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::NewProp_AttachParentName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::NewProp_AttachSocketName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::NewProp_bIsHidden,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SaveSystem,
		Z_Construct_UScriptStruct_FActorComponentRecord,
		&NewStructOps,
		"SceneComponentRecord",
		sizeof(FSceneComponentRecord),
		alignof(FSceneComponentRecord),
		Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSceneComponentRecord()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FSceneComponentRecord_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_SaveSystem();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("SceneComponentRecord"), sizeof(FSceneComponentRecord), Get_Z_Construct_UScriptStruct_FSceneComponentRecord_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FSceneComponentRecord_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FSceneComponentRecord_Hash() { return 695135608U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
