// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveSystem/Public/StructRecord/ObjectRecord.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeObjectRecord() {}
// Cross Module References
	SAVESYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FObjectRecord();
	UPackage* Z_Construct_UPackage__Script_SaveSystem();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
// End Cross Module References
class UScriptStruct* FObjectRecord::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern SAVESYSTEM_API uint32 Get_Z_Construct_UScriptStruct_FObjectRecord_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FObjectRecord, Z_Construct_UPackage__Script_SaveSystem(), TEXT("ObjectRecord"), sizeof(FObjectRecord), Get_Z_Construct_UScriptStruct_FObjectRecord_Hash());
	}
	return Singleton;
}
template<> SAVESYSTEM_API UScriptStruct* StaticStruct<FObjectRecord>()
{
	return FObjectRecord::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FObjectRecord(FObjectRecord::StaticStruct, TEXT("/Script/SaveSystem"), TEXT("ObjectRecord"), false, nullptr, nullptr);
static struct FScriptStruct_SaveSystem_StaticRegisterNativesFObjectRecord
{
	FScriptStruct_SaveSystem_StaticRegisterNativesFObjectRecord()
	{
		UScriptStruct::DeferCppStructOps<FObjectRecord>(FName(TEXT("ObjectRecord")));
	}
} ScriptStruct_SaveSystem_StaticRegisterNativesFObjectRecord;
	struct Z_Construct_UScriptStruct_FObjectRecord_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Class_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_Class;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_Name;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OuterPtr_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OuterPtr;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OuterClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_OuterClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OuterName_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_OuterName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SelfPointer_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SelfPointer;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_BinaryData_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BinaryData_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_BinaryData;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FObjectRecord_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/StructRecord/ObjectRecord.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FObjectRecord_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FObjectRecord>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_Class_MetaData[] = {
		{ "ModuleRelativePath", "Public/StructRecord/ObjectRecord.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_Class = { "Class", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FObjectRecord, Class), Z_Construct_UClass_UObject_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_Class_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_Class_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_Name_MetaData[] = {
		{ "ModuleRelativePath", "Public/StructRecord/ObjectRecord.h" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FObjectRecord, Name), METADATA_PARAMS(Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_Name_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_Name_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_OuterPtr_MetaData[] = {
		{ "ModuleRelativePath", "Public/StructRecord/ObjectRecord.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_OuterPtr = { "OuterPtr", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FObjectRecord, OuterPtr), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_OuterPtr_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_OuterPtr_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_OuterClass_MetaData[] = {
		{ "ModuleRelativePath", "Public/StructRecord/ObjectRecord.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_OuterClass = { "OuterClass", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FObjectRecord, OuterClass), Z_Construct_UClass_UObject_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_OuterClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_OuterClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_OuterName_MetaData[] = {
		{ "ModuleRelativePath", "Public/StructRecord/ObjectRecord.h" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_OuterName = { "OuterName", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FObjectRecord, OuterName), METADATA_PARAMS(Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_OuterName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_OuterName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_SelfPointer_MetaData[] = {
		{ "ModuleRelativePath", "Public/StructRecord/ObjectRecord.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_SelfPointer = { "SelfPointer", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FObjectRecord, SelfPointer), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_SelfPointer_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_SelfPointer_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_BinaryData_Inner = { "BinaryData", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_BinaryData_MetaData[] = {
		{ "ModuleRelativePath", "Public/StructRecord/ObjectRecord.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_BinaryData = { "BinaryData", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FObjectRecord, BinaryData), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_BinaryData_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_BinaryData_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FObjectRecord_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_Class,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_Name,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_OuterPtr,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_OuterClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_OuterName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_SelfPointer,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_BinaryData_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FObjectRecord_Statics::NewProp_BinaryData,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FObjectRecord_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SaveSystem,
		nullptr,
		&NewStructOps,
		"ObjectRecord",
		sizeof(FObjectRecord),
		alignof(FObjectRecord),
		Z_Construct_UScriptStruct_FObjectRecord_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FObjectRecord_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FObjectRecord_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FObjectRecord_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FObjectRecord()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FObjectRecord_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_SaveSystem();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("ObjectRecord"), sizeof(FObjectRecord), Get_Z_Construct_UScriptStruct_FObjectRecord_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FObjectRecord_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FObjectRecord_Hash() { return 4284346089U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
