// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveSystem/Public/SaveGame/SaveInterface.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSaveInterface() {}
// Cross Module References
	SAVESYSTEM_API UClass* Z_Construct_UClass_USaveSystemBase_NoRegister();
	SAVESYSTEM_API UClass* Z_Construct_UClass_USaveSystemBase();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_SaveSystem();
// End Cross Module References
	void USaveSystemBase::StaticRegisterNativesUSaveSystemBase()
	{
	}
	UClass* Z_Construct_UClass_USaveSystemBase_NoRegister()
	{
		return USaveSystemBase::StaticClass();
	}
	struct Z_Construct_UClass_USaveSystemBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USaveSystemBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_SaveSystem,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USaveSystemBase_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/SaveGame/SaveInterface.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USaveSystemBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ISaveSystemBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USaveSystemBase_Statics::ClassParams = {
		&USaveSystemBase::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000840A1u,
		METADATA_PARAMS(Z_Construct_UClass_USaveSystemBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USaveSystemBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USaveSystemBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USaveSystemBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USaveSystemBase, 2811799027);
	template<> SAVESYSTEM_API UClass* StaticClass<USaveSystemBase>()
	{
		return USaveSystemBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USaveSystemBase(Z_Construct_UClass_USaveSystemBase, &USaveSystemBase::StaticClass, TEXT("/Script/SaveSystem"), TEXT("USaveSystemBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USaveSystemBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
