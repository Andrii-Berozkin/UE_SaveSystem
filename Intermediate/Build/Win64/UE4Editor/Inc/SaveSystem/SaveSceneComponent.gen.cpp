// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveSystem/Public/SaveGame/SaveActorComponents/SaveSceneComponent.h"
#include "Serialization/ArchiveUObjectFromStructuredArchive.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSaveSceneComponent() {}
// Cross Module References
	SAVESYSTEM_API UClass* Z_Construct_UClass_USaveActorWithComponentsScene_NoRegister();
	SAVESYSTEM_API UClass* Z_Construct_UClass_USaveActorWithComponentsScene();
	SAVESYSTEM_API UClass* Z_Construct_UClass_USaveActoWithComponent();
	UPackage* Z_Construct_UPackage__Script_SaveSystem();
	SAVESYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FSceneComponentRecord();
	SAVESYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FPrimitiveComponentRecord();
// End Cross Module References
	void USaveActorWithComponentsScene::StaticRegisterNativesUSaveActorWithComponentsScene()
	{
	}
	UClass* Z_Construct_UClass_USaveActorWithComponentsScene_NoRegister()
	{
		return USaveActorWithComponentsScene::StaticClass();
	}
	struct Z_Construct_UClass_USaveActorWithComponentsScene_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bSavePrimitivePhysicRepresentation_MetaData[];
#endif
		static void NewProp_bSavePrimitivePhysicRepresentation_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bSavePrimitivePhysicRepresentation;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_SceneComponentsRecord_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SceneComponentsRecord_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_SceneComponentsRecord;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PrimitiveComponentsRecord_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PrimitiveComponentsRecord_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_PrimitiveComponentsRecord;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USaveActorWithComponentsScene_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USaveActoWithComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_SaveSystem,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USaveActorWithComponentsScene_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SaveGame/SaveActorComponents/SaveSceneComponent.h" },
		{ "ModuleRelativePath", "Public/SaveGame/SaveActorComponents/SaveSceneComponent.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USaveActorWithComponentsScene_Statics::NewProp_bSavePrimitivePhysicRepresentation_MetaData[] = {
		{ "ModuleRelativePath", "Public/SaveGame/SaveActorComponents/SaveSceneComponent.h" },
	};
#endif
	void Z_Construct_UClass_USaveActorWithComponentsScene_Statics::NewProp_bSavePrimitivePhysicRepresentation_SetBit(void* Obj)
	{
		((USaveActorWithComponentsScene*)Obj)->bSavePrimitivePhysicRepresentation = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USaveActorWithComponentsScene_Statics::NewProp_bSavePrimitivePhysicRepresentation = { "bSavePrimitivePhysicRepresentation", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(USaveActorWithComponentsScene), &Z_Construct_UClass_USaveActorWithComponentsScene_Statics::NewProp_bSavePrimitivePhysicRepresentation_SetBit, METADATA_PARAMS(Z_Construct_UClass_USaveActorWithComponentsScene_Statics::NewProp_bSavePrimitivePhysicRepresentation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USaveActorWithComponentsScene_Statics::NewProp_bSavePrimitivePhysicRepresentation_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_USaveActorWithComponentsScene_Statics::NewProp_SceneComponentsRecord_Inner = { "SceneComponentsRecord", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FSceneComponentRecord, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USaveActorWithComponentsScene_Statics::NewProp_SceneComponentsRecord_MetaData[] = {
		{ "ModuleRelativePath", "Public/SaveGame/SaveActorComponents/SaveSceneComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_USaveActorWithComponentsScene_Statics::NewProp_SceneComponentsRecord = { "SceneComponentsRecord", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USaveActorWithComponentsScene, SceneComponentsRecord), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_USaveActorWithComponentsScene_Statics::NewProp_SceneComponentsRecord_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USaveActorWithComponentsScene_Statics::NewProp_SceneComponentsRecord_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_USaveActorWithComponentsScene_Statics::NewProp_PrimitiveComponentsRecord_Inner = { "PrimitiveComponentsRecord", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FPrimitiveComponentRecord, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USaveActorWithComponentsScene_Statics::NewProp_PrimitiveComponentsRecord_MetaData[] = {
		{ "ModuleRelativePath", "Public/SaveGame/SaveActorComponents/SaveSceneComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_USaveActorWithComponentsScene_Statics::NewProp_PrimitiveComponentsRecord = { "PrimitiveComponentsRecord", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USaveActorWithComponentsScene, PrimitiveComponentsRecord), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_USaveActorWithComponentsScene_Statics::NewProp_PrimitiveComponentsRecord_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USaveActorWithComponentsScene_Statics::NewProp_PrimitiveComponentsRecord_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USaveActorWithComponentsScene_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USaveActorWithComponentsScene_Statics::NewProp_bSavePrimitivePhysicRepresentation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USaveActorWithComponentsScene_Statics::NewProp_SceneComponentsRecord_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USaveActorWithComponentsScene_Statics::NewProp_SceneComponentsRecord,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USaveActorWithComponentsScene_Statics::NewProp_PrimitiveComponentsRecord_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USaveActorWithComponentsScene_Statics::NewProp_PrimitiveComponentsRecord,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USaveActorWithComponentsScene_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USaveActorWithComponentsScene>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USaveActorWithComponentsScene_Statics::ClassParams = {
		&USaveActorWithComponentsScene::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_USaveActorWithComponentsScene_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_USaveActorWithComponentsScene_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USaveActorWithComponentsScene_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USaveActorWithComponentsScene_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USaveActorWithComponentsScene()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USaveActorWithComponentsScene_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USaveActorWithComponentsScene, 312715789);
	template<> SAVESYSTEM_API UClass* StaticClass<USaveActorWithComponentsScene>()
	{
		return USaveActorWithComponentsScene::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USaveActorWithComponentsScene(Z_Construct_UClass_USaveActorWithComponentsScene, &USaveActorWithComponentsScene::StaticClass, TEXT("/Script/SaveSystem"), TEXT("USaveActorWithComponentsScene"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USaveActorWithComponentsScene);
	IMPLEMENT_FSTRUCTUREDARCHIVE_SERIALIZER(USaveActorWithComponentsScene)
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
