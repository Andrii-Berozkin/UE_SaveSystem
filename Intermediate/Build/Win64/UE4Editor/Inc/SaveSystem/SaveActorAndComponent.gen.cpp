// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveSystem/Public/SaveGame/SaveActorComponents/SaveActorAndComponent.h"
#include "Serialization/ArchiveUObjectFromStructuredArchive.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSaveActorAndComponent() {}
// Cross Module References
	SAVESYSTEM_API UClass* Z_Construct_UClass_USaveActoWithComponent_NoRegister();
	SAVESYSTEM_API UClass* Z_Construct_UClass_USaveActoWithComponent();
	SAVESYSTEM_API UClass* Z_Construct_UClass_USaveGameActors();
	UPackage* Z_Construct_UPackage__Script_SaveSystem();
	SAVESYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FActorComponentRecord();
// End Cross Module References
	void USaveActoWithComponent::StaticRegisterNativesUSaveActoWithComponent()
	{
	}
	UClass* Z_Construct_UClass_USaveActoWithComponent_NoRegister()
	{
		return USaveActoWithComponent::StaticClass();
	}
	struct Z_Construct_UClass_USaveActoWithComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ActorComponentsRecord_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ActorComponentsRecord_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ActorComponentsRecord;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USaveActoWithComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USaveGameActors,
		(UObject* (*)())Z_Construct_UPackage__Script_SaveSystem,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USaveActoWithComponent_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SaveGame/SaveActorComponents/SaveActorAndComponent.h" },
		{ "ModuleRelativePath", "Public/SaveGame/SaveActorComponents/SaveActorAndComponent.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_USaveActoWithComponent_Statics::NewProp_ActorComponentsRecord_Inner = { "ActorComponentsRecord", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FActorComponentRecord, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USaveActoWithComponent_Statics::NewProp_ActorComponentsRecord_MetaData[] = {
		{ "ModuleRelativePath", "Public/SaveGame/SaveActorComponents/SaveActorAndComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_USaveActoWithComponent_Statics::NewProp_ActorComponentsRecord = { "ActorComponentsRecord", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USaveActoWithComponent, ActorComponentsRecord), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_USaveActoWithComponent_Statics::NewProp_ActorComponentsRecord_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USaveActoWithComponent_Statics::NewProp_ActorComponentsRecord_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USaveActoWithComponent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USaveActoWithComponent_Statics::NewProp_ActorComponentsRecord_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USaveActoWithComponent_Statics::NewProp_ActorComponentsRecord,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USaveActoWithComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USaveActoWithComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USaveActoWithComponent_Statics::ClassParams = {
		&USaveActoWithComponent::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_USaveActoWithComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_USaveActoWithComponent_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USaveActoWithComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USaveActoWithComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USaveActoWithComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USaveActoWithComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USaveActoWithComponent, 2227000152);
	template<> SAVESYSTEM_API UClass* StaticClass<USaveActoWithComponent>()
	{
		return USaveActoWithComponent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USaveActoWithComponent(Z_Construct_UClass_USaveActoWithComponent, &USaveActoWithComponent::StaticClass, TEXT("/Script/SaveSystem"), TEXT("USaveActoWithComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USaveActoWithComponent);
	IMPLEMENT_FSTRUCTUREDARCHIVE_SERIALIZER(USaveActoWithComponent)
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
