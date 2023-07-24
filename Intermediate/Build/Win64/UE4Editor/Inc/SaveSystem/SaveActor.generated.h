// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SAVESYSTEM_SaveActor_generated_h
#error "SaveActor.generated.h already included, missing '#pragma once' in SaveActor.h"
#endif
#define SAVESYSTEM_SaveActor_generated_h

#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveActor_SaveActor_h_30_SPARSE_DATA
#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveActor_SaveActor_h_30_RPC_WRAPPERS
#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveActor_SaveActor_h_30_RPC_WRAPPERS_NO_PURE_DECLS
#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveActor_SaveActor_h_30_ARCHIVESERIALIZER \
	DECLARE_FSTRUCTUREDARCHIVE_SERIALIZER(USaveGameActors, NO_API)


#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveActor_SaveActor_h_30_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSaveGameActors(); \
	friend struct Z_Construct_UClass_USaveGameActors_Statics; \
public: \
	DECLARE_CLASS(USaveGameActors, USaveGameSlot, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SaveSystem"), NO_API) \
	DECLARE_SERIALIZER(USaveGameActors) \
	TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveActor_SaveActor_h_30_ARCHIVESERIALIZER


#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveActor_SaveActor_h_30_INCLASS \
private: \
	static void StaticRegisterNativesUSaveGameActors(); \
	friend struct Z_Construct_UClass_USaveGameActors_Statics; \
public: \
	DECLARE_CLASS(USaveGameActors, USaveGameSlot, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SaveSystem"), NO_API) \
	DECLARE_SERIALIZER(USaveGameActors) \
	TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveActor_SaveActor_h_30_ARCHIVESERIALIZER


#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveActor_SaveActor_h_30_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USaveGameActors(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USaveGameActors) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USaveGameActors); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USaveGameActors); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USaveGameActors(USaveGameActors&&); \
	NO_API USaveGameActors(const USaveGameActors&); \
public:


#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveActor_SaveActor_h_30_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USaveGameActors(USaveGameActors&&); \
	NO_API USaveGameActors(const USaveGameActors&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USaveGameActors); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USaveGameActors); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USaveGameActors)


#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveActor_SaveActor_h_30_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__ActorsRecord() { return STRUCT_OFFSET(USaveGameActors, ActorsRecord); } \
	FORCEINLINE static uint32 __PPO__ComponentsToSave() { return STRUCT_OFFSET(USaveGameActors, ComponentsToSave); }


#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveActor_SaveActor_h_25_PROLOG
#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveActor_SaveActor_h_30_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveActor_SaveActor_h_30_PRIVATE_PROPERTY_OFFSET \
	TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveActor_SaveActor_h_30_SPARSE_DATA \
	TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveActor_SaveActor_h_30_RPC_WRAPPERS \
	TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveActor_SaveActor_h_30_INCLASS \
	TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveActor_SaveActor_h_30_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveActor_SaveActor_h_30_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveActor_SaveActor_h_30_PRIVATE_PROPERTY_OFFSET \
	TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveActor_SaveActor_h_30_SPARSE_DATA \
	TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveActor_SaveActor_h_30_RPC_WRAPPERS_NO_PURE_DECLS \
	TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveActor_SaveActor_h_30_INCLASS_NO_PURE_DECLS \
	TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveActor_SaveActor_h_30_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SAVESYSTEM_API UClass* StaticClass<class USaveGameActors>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveActor_SaveActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
