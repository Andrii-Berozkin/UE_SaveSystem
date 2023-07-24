// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class USaveGameSlot;
#ifdef SAVESYSTEM_SaveObject_generated_h
#error "SaveObject.generated.h already included, missing '#pragma once' in SaveObject.h"
#endif
#define SAVESYSTEM_SaveObject_generated_h

#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveObject_h_14_DELEGATE \
struct _Script_SaveSystem_eventSaveSystemCompleteSignatureBP_Parms \
{ \
	USaveGameSlot* SaveGameObject; \
}; \
static inline void FSaveSystemCompleteSignatureBP_DelegateWrapper(const FMulticastScriptDelegate& SaveSystemCompleteSignatureBP, USaveGameSlot* SaveGameObject) \
{ \
	_Script_SaveSystem_eventSaveSystemCompleteSignatureBP_Parms Parms; \
	Parms.SaveGameObject=SaveGameObject; \
	SaveSystemCompleteSignatureBP.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveObject_h_51_SPARSE_DATA
#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveObject_h_51_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execIsLoadWithThread); \
	DECLARE_FUNCTION(execIsSaveWithThread); \
	DECLARE_FUNCTION(execIsUseParallelFor); \
	DECLARE_FUNCTION(execSetUseParallelFor);


#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveObject_h_51_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execIsLoadWithThread); \
	DECLARE_FUNCTION(execIsSaveWithThread); \
	DECLARE_FUNCTION(execIsUseParallelFor); \
	DECLARE_FUNCTION(execSetUseParallelFor);


#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveObject_h_51_ARCHIVESERIALIZER \
	DECLARE_FSTRUCTUREDARCHIVE_SERIALIZER(USaveGameSlot, NO_API)


#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveObject_h_51_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSaveGameSlot(); \
	friend struct Z_Construct_UClass_USaveGameSlot_Statics; \
public: \
	DECLARE_CLASS(USaveGameSlot, USaveGame, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SaveSystem"), NO_API) \
	DECLARE_SERIALIZER(USaveGameSlot) \
	TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveObject_h_51_ARCHIVESERIALIZER \
	virtual UObject* _getUObject() const override { return const_cast<USaveGameSlot*>(this); }


#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveObject_h_51_INCLASS \
private: \
	static void StaticRegisterNativesUSaveGameSlot(); \
	friend struct Z_Construct_UClass_USaveGameSlot_Statics; \
public: \
	DECLARE_CLASS(USaveGameSlot, USaveGame, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SaveSystem"), NO_API) \
	DECLARE_SERIALIZER(USaveGameSlot) \
	TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveObject_h_51_ARCHIVESERIALIZER \
	virtual UObject* _getUObject() const override { return const_cast<USaveGameSlot*>(this); }


#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveObject_h_51_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USaveGameSlot(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USaveGameSlot) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USaveGameSlot); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USaveGameSlot); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USaveGameSlot(USaveGameSlot&&); \
	NO_API USaveGameSlot(const USaveGameSlot&); \
public:


#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveObject_h_51_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USaveGameSlot(USaveGameSlot&&); \
	NO_API USaveGameSlot(const USaveGameSlot&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USaveGameSlot); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USaveGameSlot); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USaveGameSlot)


#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveObject_h_51_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__ObjectsRecord() { return STRUCT_OFFSET(USaveGameSlot, ObjectsRecord); } \
	FORCEINLINE static uint32 __PPO__SaveTime() { return STRUCT_OFFSET(USaveGameSlot, SaveTime); } \
	FORCEINLINE static uint32 __PPO__bUseParallelFor() { return STRUCT_OFFSET(USaveGameSlot, bUseParallelFor); }


#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveObject_h_48_PROLOG
#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveObject_h_51_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveObject_h_51_PRIVATE_PROPERTY_OFFSET \
	TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveObject_h_51_SPARSE_DATA \
	TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveObject_h_51_RPC_WRAPPERS \
	TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveObject_h_51_INCLASS \
	TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveObject_h_51_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveObject_h_51_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveObject_h_51_PRIVATE_PROPERTY_OFFSET \
	TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveObject_h_51_SPARSE_DATA \
	TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveObject_h_51_RPC_WRAPPERS_NO_PURE_DECLS \
	TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveObject_h_51_INCLASS_NO_PURE_DECLS \
	TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveObject_h_51_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SAVESYSTEM_API UClass* StaticClass<class USaveGameSlot>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TycoonMobile_Plugins_SaveSystem_Source_SaveSystem_Public_SaveGame_SaveObject_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
