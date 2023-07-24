// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveSystem/Public/SaveGame/SaveActor/SaveActor.h"
#include "Serialization/ArchiveUObjectFromStructuredArchive.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSaveActor() {}
// Cross Module References
	SAVESYSTEM_API UClass* Z_Construct_UClass_USaveGameActors_NoRegister();
	SAVESYSTEM_API UClass* Z_Construct_UClass_USaveGameActors();
	SAVESYSTEM_API UClass* Z_Construct_UClass_USaveGameSlot();
	UPackage* Z_Construct_UPackage__Script_SaveSystem();
	SAVESYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FActorRecord();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent_NoRegister();
// End Cross Module References
	void USaveGameActors::StaticRegisterNativesUSaveGameActors()
	{
	}
	UClass* Z_Construct_UClass_USaveGameActors_NoRegister()
	{
		return USaveGameActors::StaticClass();
	}
	struct Z_Construct_UClass_USaveGameActors_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ActorsRecord_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ActorsRecord_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ActorsRecord;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ComponentsToSave_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ComponentsToSave_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ComponentsToSave;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USaveGameActors_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USaveGameSlot,
		(UObject* (*)())Z_Construct_UPackage__Script_SaveSystem,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USaveGameActors_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SaveGame/SaveActor/SaveActor.h" },
		{ "ModuleRelativePath", "Public/SaveGame/SaveActor/SaveActor.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_USaveGameActors_Statics::NewProp_ActorsRecord_Inner = { "ActorsRecord", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FActorRecord, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USaveGameActors_Statics::NewProp_ActorsRecord_MetaData[] = {
		{ "ModuleRelativePath", "Public/SaveGame/SaveActor/SaveActor.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_USaveGameActors_Statics::NewProp_ActorsRecord = { "ActorsRecord", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USaveGameActors, ActorsRecord), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_USaveGameActors_Statics::NewProp_ActorsRecord_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USaveGameActors_Statics::NewProp_ActorsRecord_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USaveGameActors_Statics::NewProp_ComponentsToSave_Inner = { "ComponentsToSave", nullptr, (EPropertyFlags)0x0000000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UActorComponent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USaveGameActors_Statics::NewProp_ComponentsToSave_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SaveGame/SaveActor/SaveActor.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_USaveGameActors_Statics::NewProp_ComponentsToSave = { "ComponentsToSave", nullptr, (EPropertyFlags)0x0020088000002008, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USaveGameActors, ComponentsToSave), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_USaveGameActors_Statics::NewProp_ComponentsToSave_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USaveGameActors_Statics::NewProp_ComponentsToSave_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USaveGameActors_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USaveGameActors_Statics::NewProp_ActorsRecord_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USaveGameActors_Statics::NewProp_ActorsRecord,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USaveGameActors_Statics::NewProp_ComponentsToSave_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USaveGameActors_Statics::NewProp_ComponentsToSave,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USaveGameActors_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USaveGameActors>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USaveGameActors_Statics::ClassParams = {
		&USaveGameActors::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_USaveGameActors_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_USaveGameActors_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USaveGameActors_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USaveGameActors_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USaveGameActors()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USaveGameActors_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USaveGameActors, 3488418057);
	template<> SAVESYSTEM_API UClass* StaticClass<USaveGameActors>()
	{
		return USaveGameActors::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USaveGameActors(Z_Construct_UClass_USaveGameActors, &USaveGameActors::StaticClass, TEXT("/Script/SaveSystem"), TEXT("USaveGameActors"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USaveGameActors);
	IMPLEMENT_FSTRUCTUREDARCHIVE_SERIALIZER(USaveGameActors)
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
