// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveSystem/Public/SaveGame/SaveObject.h"
#include "Serialization/ArchiveUObjectFromStructuredArchive.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSaveObject() {}
// Cross Module References
	SAVESYSTEM_API UFunction* Z_Construct_UDelegateFunction_SaveSystem_SaveSystemCompleteSignatureBP__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_SaveSystem();
	SAVESYSTEM_API UClass* Z_Construct_UClass_USaveGameSlot_NoRegister();
	SAVESYSTEM_API UClass* Z_Construct_UClass_USaveGameSlot();
	ENGINE_API UClass* Z_Construct_UClass_USaveGame();
	SAVESYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FObjectRecord();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDateTime();
	SAVESYSTEM_API UClass* Z_Construct_UClass_USaveSystemBase_NoRegister();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_SaveSystem_SaveSystemCompleteSignatureBP__DelegateSignature_Statics
	{
		struct _Script_SaveSystem_eventSaveSystemCompleteSignatureBP_Parms
		{
			USaveGameSlot* SaveGameObject;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SaveGameObject;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_SaveSystem_SaveSystemCompleteSignatureBP__DelegateSignature_Statics::NewProp_SaveGameObject = { "SaveGameObject", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_SaveSystem_eventSaveSystemCompleteSignatureBP_Parms, SaveGameObject), Z_Construct_UClass_USaveGameSlot_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_SaveSystem_SaveSystemCompleteSignatureBP__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SaveSystem_SaveSystemCompleteSignatureBP__DelegateSignature_Statics::NewProp_SaveGameObject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SaveSystem_SaveSystemCompleteSignatureBP__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SaveGame/SaveObject.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SaveSystem_SaveSystemCompleteSignatureBP__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SaveSystem, nullptr, "SaveSystemCompleteSignatureBP__DelegateSignature", nullptr, nullptr, sizeof(_Script_SaveSystem_eventSaveSystemCompleteSignatureBP_Parms), Z_Construct_UDelegateFunction_SaveSystem_SaveSystemCompleteSignatureBP__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SaveSystem_SaveSystemCompleteSignatureBP__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SaveSystem_SaveSystemCompleteSignatureBP__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SaveSystem_SaveSystemCompleteSignatureBP__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SaveSystem_SaveSystemCompleteSignatureBP__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_SaveSystem_SaveSystemCompleteSignatureBP__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(USaveGameSlot::execIsLoadWithThread)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsLoadWithThread();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USaveGameSlot::execIsSaveWithThread)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsSaveWithThread();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USaveGameSlot::execIsUseParallelFor)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsUseParallelFor();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USaveGameSlot::execSetUseParallelFor)
	{
		P_GET_UBOOL(Z_Param_IsUse);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetUseParallelFor(Z_Param_IsUse);
		P_NATIVE_END;
	}
	void USaveGameSlot::StaticRegisterNativesUSaveGameSlot()
	{
		UClass* Class = USaveGameSlot::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "IsLoadWithThread", &USaveGameSlot::execIsLoadWithThread },
			{ "IsSaveWithThread", &USaveGameSlot::execIsSaveWithThread },
			{ "IsUseParallelFor", &USaveGameSlot::execIsUseParallelFor },
			{ "SetUseParallelFor", &USaveGameSlot::execSetUseParallelFor },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USaveGameSlot_IsLoadWithThread_Statics
	{
		struct SaveGameSlot_eventIsLoadWithThread_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USaveGameSlot_IsLoadWithThread_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SaveGameSlot_eventIsLoadWithThread_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USaveGameSlot_IsLoadWithThread_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SaveGameSlot_eventIsLoadWithThread_Parms), &Z_Construct_UFunction_USaveGameSlot_IsLoadWithThread_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USaveGameSlot_IsLoadWithThread_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USaveGameSlot_IsLoadWithThread_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USaveGameSlot_IsLoadWithThread_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SaveGame/SaveObject.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USaveGameSlot_IsLoadWithThread_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USaveGameSlot, nullptr, "IsLoadWithThread", nullptr, nullptr, sizeof(SaveGameSlot_eventIsLoadWithThread_Parms), Z_Construct_UFunction_USaveGameSlot_IsLoadWithThread_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USaveGameSlot_IsLoadWithThread_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x40020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USaveGameSlot_IsLoadWithThread_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USaveGameSlot_IsLoadWithThread_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USaveGameSlot_IsLoadWithThread()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USaveGameSlot_IsLoadWithThread_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USaveGameSlot_IsSaveWithThread_Statics
	{
		struct SaveGameSlot_eventIsSaveWithThread_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USaveGameSlot_IsSaveWithThread_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SaveGameSlot_eventIsSaveWithThread_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USaveGameSlot_IsSaveWithThread_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SaveGameSlot_eventIsSaveWithThread_Parms), &Z_Construct_UFunction_USaveGameSlot_IsSaveWithThread_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USaveGameSlot_IsSaveWithThread_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USaveGameSlot_IsSaveWithThread_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USaveGameSlot_IsSaveWithThread_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SaveGame/SaveObject.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USaveGameSlot_IsSaveWithThread_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USaveGameSlot, nullptr, "IsSaveWithThread", nullptr, nullptr, sizeof(SaveGameSlot_eventIsSaveWithThread_Parms), Z_Construct_UFunction_USaveGameSlot_IsSaveWithThread_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USaveGameSlot_IsSaveWithThread_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x40020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USaveGameSlot_IsSaveWithThread_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USaveGameSlot_IsSaveWithThread_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USaveGameSlot_IsSaveWithThread()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USaveGameSlot_IsSaveWithThread_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USaveGameSlot_IsUseParallelFor_Statics
	{
		struct SaveGameSlot_eventIsUseParallelFor_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USaveGameSlot_IsUseParallelFor_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SaveGameSlot_eventIsUseParallelFor_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USaveGameSlot_IsUseParallelFor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SaveGameSlot_eventIsUseParallelFor_Parms), &Z_Construct_UFunction_USaveGameSlot_IsUseParallelFor_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USaveGameSlot_IsUseParallelFor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USaveGameSlot_IsUseParallelFor_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USaveGameSlot_IsUseParallelFor_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SaveGame/SaveObject.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USaveGameSlot_IsUseParallelFor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USaveGameSlot, nullptr, "IsUseParallelFor", nullptr, nullptr, sizeof(SaveGameSlot_eventIsUseParallelFor_Parms), Z_Construct_UFunction_USaveGameSlot_IsUseParallelFor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USaveGameSlot_IsUseParallelFor_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x40020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USaveGameSlot_IsUseParallelFor_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USaveGameSlot_IsUseParallelFor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USaveGameSlot_IsUseParallelFor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USaveGameSlot_IsUseParallelFor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USaveGameSlot_SetUseParallelFor_Statics
	{
		struct SaveGameSlot_eventSetUseParallelFor_Parms
		{
			bool IsUse;
		};
		static void NewProp_IsUse_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsUse;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USaveGameSlot_SetUseParallelFor_Statics::NewProp_IsUse_SetBit(void* Obj)
	{
		((SaveGameSlot_eventSetUseParallelFor_Parms*)Obj)->IsUse = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USaveGameSlot_SetUseParallelFor_Statics::NewProp_IsUse = { "IsUse", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SaveGameSlot_eventSetUseParallelFor_Parms), &Z_Construct_UFunction_USaveGameSlot_SetUseParallelFor_Statics::NewProp_IsUse_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USaveGameSlot_SetUseParallelFor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USaveGameSlot_SetUseParallelFor_Statics::NewProp_IsUse,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USaveGameSlot_SetUseParallelFor_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SaveGame/SaveObject.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USaveGameSlot_SetUseParallelFor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USaveGameSlot, nullptr, "SetUseParallelFor", nullptr, nullptr, sizeof(SaveGameSlot_eventSetUseParallelFor_Parms), Z_Construct_UFunction_USaveGameSlot_SetUseParallelFor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USaveGameSlot_SetUseParallelFor_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USaveGameSlot_SetUseParallelFor_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USaveGameSlot_SetUseParallelFor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USaveGameSlot_SetUseParallelFor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USaveGameSlot_SetUseParallelFor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_USaveGameSlot_NoRegister()
	{
		return USaveGameSlot::StaticClass();
	}
	struct Z_Construct_UClass_USaveGameSlot_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bDebugEnable_MetaData[];
#endif
		static void NewProp_bDebugEnable_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bDebugEnable;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bSaveObjectProperty_MetaData[];
#endif
		static void NewProp_bSaveObjectProperty_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bSaveObjectProperty;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIncludeDescendants_MetaData[];
#endif
		static void NewProp_bIncludeDescendants_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIncludeDescendants;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bUseUObjectSerialize_MetaData[];
#endif
		static void NewProp_bUseUObjectSerialize_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bUseUObjectSerialize;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnSaveComplete_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSaveComplete;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnLoadComplete_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnLoadComplete;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ObjectsRecord_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ObjectsRecord_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ObjectsRecord;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SaveTime_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_SaveTime;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bUseParallelFor_MetaData[];
#endif
		static void NewProp_bUseParallelFor_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bUseParallelFor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USaveGameSlot_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USaveGame,
		(UObject* (*)())Z_Construct_UPackage__Script_SaveSystem,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USaveGameSlot_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USaveGameSlot_IsLoadWithThread, "IsLoadWithThread" }, // 2217010849
		{ &Z_Construct_UFunction_USaveGameSlot_IsSaveWithThread, "IsSaveWithThread" }, // 3162341387
		{ &Z_Construct_UFunction_USaveGameSlot_IsUseParallelFor, "IsUseParallelFor" }, // 2581376730
		{ &Z_Construct_UFunction_USaveGameSlot_SetUseParallelFor, "SetUseParallelFor" }, // 2151335080
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USaveGameSlot_Statics::Class_MetaDataParams[] = {
		{ "Comment", "//\x09""Begin SaveSystem\n" },
		{ "IncludePath", "SaveGame/SaveObject.h" },
		{ "ModuleRelativePath", "Public/SaveGame/SaveObject.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "ToolTip", "Begin SaveSystem" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USaveGameSlot_Statics::NewProp_bDebugEnable_MetaData[] = {
		{ "Comment", "//\x09TO DO : Add Delegate To Start and finish of Start/Load\n" },
		{ "ModuleRelativePath", "Public/SaveGame/SaveObject.h" },
		{ "ToolTip", "TO DO : Add Delegate To Start and finish of Start/Load" },
	};
#endif
	void Z_Construct_UClass_USaveGameSlot_Statics::NewProp_bDebugEnable_SetBit(void* Obj)
	{
		((USaveGameSlot*)Obj)->bDebugEnable = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USaveGameSlot_Statics::NewProp_bDebugEnable = { "bDebugEnable", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(USaveGameSlot), &Z_Construct_UClass_USaveGameSlot_Statics::NewProp_bDebugEnable_SetBit, METADATA_PARAMS(Z_Construct_UClass_USaveGameSlot_Statics::NewProp_bDebugEnable_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USaveGameSlot_Statics::NewProp_bDebugEnable_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USaveGameSlot_Statics::NewProp_bSaveObjectProperty_MetaData[] = {
		{ "Comment", "/* This parameter determines whether object parameters\n\x09* such as pointers to other objects or actors (if marked as 'SaveGame')\n\x09* will be saved as other parameters (eg integer or boolean), or skipped */" },
		{ "ModuleRelativePath", "Public/SaveGame/SaveObject.h" },
		{ "ToolTip", "This parameter determines whether object parameters\n      * such as pointers to other objects or actors (if marked as 'SaveGame')\n      * will be saved as other parameters (eg integer or boolean), or skipped" },
	};
#endif
	void Z_Construct_UClass_USaveGameSlot_Statics::NewProp_bSaveObjectProperty_SetBit(void* Obj)
	{
		((USaveGameSlot*)Obj)->bSaveObjectProperty = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USaveGameSlot_Statics::NewProp_bSaveObjectProperty = { "bSaveObjectProperty", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(USaveGameSlot), &Z_Construct_UClass_USaveGameSlot_Statics::NewProp_bSaveObjectProperty_SetBit, METADATA_PARAMS(Z_Construct_UClass_USaveGameSlot_Statics::NewProp_bSaveObjectProperty_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USaveGameSlot_Statics::NewProp_bSaveObjectProperty_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USaveGameSlot_Statics::NewProp_bIncludeDescendants_MetaData[] = {
		{ "Comment", "/* Determines including children of children when saving ObjectParameter */" },
		{ "ModuleRelativePath", "Public/SaveGame/SaveObject.h" },
		{ "ToolTip", "Determines including children of children when saving ObjectParameter" },
	};
#endif
	void Z_Construct_UClass_USaveGameSlot_Statics::NewProp_bIncludeDescendants_SetBit(void* Obj)
	{
		((USaveGameSlot*)Obj)->bIncludeDescendants = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USaveGameSlot_Statics::NewProp_bIncludeDescendants = { "bIncludeDescendants", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(USaveGameSlot), &Z_Construct_UClass_USaveGameSlot_Statics::NewProp_bIncludeDescendants_SetBit, METADATA_PARAMS(Z_Construct_UClass_USaveGameSlot_Statics::NewProp_bIncludeDescendants_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USaveGameSlot_Statics::NewProp_bIncludeDescendants_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USaveGameSlot_Statics::NewProp_bUseUObjectSerialize_MetaData[] = {
		{ "ModuleRelativePath", "Public/SaveGame/SaveObject.h" },
	};
#endif
	void Z_Construct_UClass_USaveGameSlot_Statics::NewProp_bUseUObjectSerialize_SetBit(void* Obj)
	{
		((USaveGameSlot*)Obj)->bUseUObjectSerialize = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USaveGameSlot_Statics::NewProp_bUseUObjectSerialize = { "bUseUObjectSerialize", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(USaveGameSlot), &Z_Construct_UClass_USaveGameSlot_Statics::NewProp_bUseUObjectSerialize_SetBit, METADATA_PARAMS(Z_Construct_UClass_USaveGameSlot_Statics::NewProp_bUseUObjectSerialize_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USaveGameSlot_Statics::NewProp_bUseUObjectSerialize_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USaveGameSlot_Statics::NewProp_OnSaveComplete_MetaData[] = {
		{ "ModuleRelativePath", "Public/SaveGame/SaveObject.h" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USaveGameSlot_Statics::NewProp_OnSaveComplete = { "OnSaveComplete", nullptr, (EPropertyFlags)0x0010000010082000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USaveGameSlot, OnSaveComplete), Z_Construct_UDelegateFunction_SaveSystem_SaveSystemCompleteSignatureBP__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_USaveGameSlot_Statics::NewProp_OnSaveComplete_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USaveGameSlot_Statics::NewProp_OnSaveComplete_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USaveGameSlot_Statics::NewProp_OnLoadComplete_MetaData[] = {
		{ "ModuleRelativePath", "Public/SaveGame/SaveObject.h" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USaveGameSlot_Statics::NewProp_OnLoadComplete = { "OnLoadComplete", nullptr, (EPropertyFlags)0x0010000010082000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USaveGameSlot, OnLoadComplete), Z_Construct_UDelegateFunction_SaveSystem_SaveSystemCompleteSignatureBP__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_USaveGameSlot_Statics::NewProp_OnLoadComplete_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USaveGameSlot_Statics::NewProp_OnLoadComplete_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_USaveGameSlot_Statics::NewProp_ObjectsRecord_Inner = { "ObjectsRecord", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FObjectRecord, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USaveGameSlot_Statics::NewProp_ObjectsRecord_MetaData[] = {
		{ "ModuleRelativePath", "Public/SaveGame/SaveObject.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_USaveGameSlot_Statics::NewProp_ObjectsRecord = { "ObjectsRecord", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USaveGameSlot, ObjectsRecord), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_USaveGameSlot_Statics::NewProp_ObjectsRecord_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USaveGameSlot_Statics::NewProp_ObjectsRecord_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USaveGameSlot_Statics::NewProp_SaveTime_MetaData[] = {
		{ "ModuleRelativePath", "Public/SaveGame/SaveObject.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_USaveGameSlot_Statics::NewProp_SaveTime = { "SaveTime", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USaveGameSlot, SaveTime), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(Z_Construct_UClass_USaveGameSlot_Statics::NewProp_SaveTime_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USaveGameSlot_Statics::NewProp_SaveTime_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USaveGameSlot_Statics::NewProp_bUseParallelFor_MetaData[] = {
		{ "ModuleRelativePath", "Public/SaveGame/SaveObject.h" },
	};
#endif
	void Z_Construct_UClass_USaveGameSlot_Statics::NewProp_bUseParallelFor_SetBit(void* Obj)
	{
		((USaveGameSlot*)Obj)->bUseParallelFor = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USaveGameSlot_Statics::NewProp_bUseParallelFor = { "bUseParallelFor", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(USaveGameSlot), &Z_Construct_UClass_USaveGameSlot_Statics::NewProp_bUseParallelFor_SetBit, METADATA_PARAMS(Z_Construct_UClass_USaveGameSlot_Statics::NewProp_bUseParallelFor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USaveGameSlot_Statics::NewProp_bUseParallelFor_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USaveGameSlot_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USaveGameSlot_Statics::NewProp_bDebugEnable,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USaveGameSlot_Statics::NewProp_bSaveObjectProperty,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USaveGameSlot_Statics::NewProp_bIncludeDescendants,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USaveGameSlot_Statics::NewProp_bUseUObjectSerialize,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USaveGameSlot_Statics::NewProp_OnSaveComplete,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USaveGameSlot_Statics::NewProp_OnLoadComplete,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USaveGameSlot_Statics::NewProp_ObjectsRecord_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USaveGameSlot_Statics::NewProp_ObjectsRecord,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USaveGameSlot_Statics::NewProp_SaveTime,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USaveGameSlot_Statics::NewProp_bUseParallelFor,
	};
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_USaveGameSlot_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_USaveSystemBase_NoRegister, (int32)VTABLE_OFFSET(USaveGameSlot, ISaveSystemBase), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USaveGameSlot_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USaveGameSlot>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USaveGameSlot_Statics::ClassParams = {
		&USaveGameSlot::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_USaveGameSlot_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_USaveGameSlot_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USaveGameSlot_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USaveGameSlot_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USaveGameSlot()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USaveGameSlot_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USaveGameSlot, 4135646535);
	template<> SAVESYSTEM_API UClass* StaticClass<USaveGameSlot>()
	{
		return USaveGameSlot::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USaveGameSlot(Z_Construct_UClass_USaveGameSlot, &USaveGameSlot::StaticClass, TEXT("/Script/SaveSystem"), TEXT("USaveGameSlot"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USaveGameSlot);
	IMPLEMENT_FSTRUCTUREDARCHIVE_SERIALIZER(USaveGameSlot)
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
