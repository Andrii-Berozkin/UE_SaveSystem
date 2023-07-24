// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SAVESYSTEM_SaveInterface_generated_h
#error "SaveInterface.generated.h already included, missing '#pragma once' in SaveInterface.h"
#endif
#define SAVESYSTEM_SaveInterface_generated_h

#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveInterface_h_15_SPARSE_DATA
#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveInterface_h_15_RPC_WRAPPERS
#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveInterface_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveInterface_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	SAVESYSTEM_API USaveSystemBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USaveSystemBase) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(SAVESYSTEM_API, USaveSystemBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USaveSystemBase); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	SAVESYSTEM_API USaveSystemBase(USaveSystemBase&&); \
	SAVESYSTEM_API USaveSystemBase(const USaveSystemBase&); \
public:


#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveInterface_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	SAVESYSTEM_API USaveSystemBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	SAVESYSTEM_API USaveSystemBase(USaveSystemBase&&); \
	SAVESYSTEM_API USaveSystemBase(const USaveSystemBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(SAVESYSTEM_API, USaveSystemBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USaveSystemBase); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USaveSystemBase)


#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveInterface_h_15_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUSaveSystemBase(); \
	friend struct Z_Construct_UClass_USaveSystemBase_Statics; \
public: \
	DECLARE_CLASS(USaveSystemBase, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/SaveSystem"), SAVESYSTEM_API) \
	DECLARE_SERIALIZER(USaveSystemBase)


#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveInterface_h_15_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveInterface_h_15_GENERATED_UINTERFACE_BODY() \
	TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveInterface_h_15_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveInterface_h_15_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveInterface_h_15_GENERATED_UINTERFACE_BODY() \
	TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveInterface_h_15_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveInterface_h_15_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~ISaveSystemBase() {} \
public: \
	typedef USaveSystemBase UClassType; \
	typedef ISaveSystemBase ThisClass; \
	virtual UObject* _getUObject() const { check(0 && "Missing required implementation."); return nullptr; }


#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveInterface_h_15_INCLASS_IINTERFACE \
protected: \
	virtual ~ISaveSystemBase() {} \
public: \
	typedef USaveSystemBase UClassType; \
	typedef ISaveSystemBase ThisClass; \
	virtual UObject* _getUObject() const { check(0 && "Missing required implementation."); return nullptr; }


#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveInterface_h_12_PROLOG
#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveInterface_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveInterface_h_15_SPARSE_DATA \
	TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveInterface_h_15_RPC_WRAPPERS \
	TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveInterface_h_15_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveInterface_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveInterface_h_15_SPARSE_DATA \
	TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveInterface_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveInterface_h_15_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SAVESYSTEM_API UClass* StaticClass<class USaveSystemBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveInterface_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
