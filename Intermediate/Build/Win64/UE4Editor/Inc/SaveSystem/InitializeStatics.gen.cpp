// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveSystem/Public/SaveGame/InitializeStatics.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInitializeStatics() {}
// Cross Module References
	SAVESYSTEM_API UClass* Z_Construct_UClass_UInitializeStatics_NoRegister();
	SAVESYSTEM_API UClass* Z_Construct_UClass_UInitializeStatics();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_SaveSystem();
// End Cross Module References
	void UInitializeStatics::StaticRegisterNativesUInitializeStatics()
	{
	}
	UClass* Z_Construct_UClass_UInitializeStatics_NoRegister()
	{
		return UInitializeStatics::StaticClass();
	}
	struct Z_Construct_UClass_UInitializeStatics_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInitializeStatics_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_SaveSystem,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInitializeStatics_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SaveGame/InitializeStatics.h" },
		{ "ModuleRelativePath", "Public/SaveGame/InitializeStatics.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInitializeStatics_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInitializeStatics>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UInitializeStatics_Statics::ClassParams = {
		&UInitializeStatics::StaticClass,
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
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UInitializeStatics_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UInitializeStatics_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UInitializeStatics()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UInitializeStatics_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UInitializeStatics, 4240580409);
	template<> SAVESYSTEM_API UClass* StaticClass<UInitializeStatics>()
	{
		return UInitializeStatics::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UInitializeStatics(Z_Construct_UClass_UInitializeStatics, &UInitializeStatics::StaticClass, TEXT("/Script/SaveSystem"), TEXT("UInitializeStatics"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInitializeStatics);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
