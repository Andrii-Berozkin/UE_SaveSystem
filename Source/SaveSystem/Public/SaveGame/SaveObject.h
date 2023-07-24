// Copyright Andrii Berozkin. All Rights Reserved.

#pragma once

#include <CoreMinimal.h>
#include <Serialization/ObjectAndNameAsStringProxyArchive.h>
#include <GameFramework/SaveGame.h>
#include <StructRecord/ObjectRecord.h>
#include <SaveGame/SaveInterface.h>
#include "SaveObject.generated.h"



DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSaveSystemCompleteSignatureBP, USaveGameSlot*, SaveGameObject);
DECLARE_MULTICAST_DELEGATE_OneParam(FSaveSystemCompleteSignature, USaveGameSlot*);

DECLARE_DELEGATE(FThreadCompleteInternalSignature);

DECLARE_LOG_CATEGORY_EXTERN(SaveSystemLog, Log, All);

DECLARE_CYCLE_STAT(TEXT("ObjectSave : Save Main"), STAT_ObjSaveMain, STATGROUP_SaveSystem);
DECLARE_CYCLE_STAT(TEXT("ObjectSave : Load Main"), STAT_ObjLoadMain, STATGROUP_SaveSystem);
DECLARE_CYCLE_STAT(TEXT("Object Save"), STAT_ObjectSave, STATGROUP_SaveSystem);
DECLARE_CYCLE_STAT(TEXT("Object childs Save"), STAT_ChildObjSave, STATGROUP_SaveSystem);
DECLARE_CYCLE_STAT(TEXT("IsSavableProperty"), STAT_IsSavableProp, STATGROUP_SaveSystem);
DECLARE_CYCLE_STAT(TEXT("GetSavableProperty"), STAT_GetSavableProp, STATGROUP_SaveSystem);
DECLARE_CYCLE_STAT(TEXT("FindOuterChilds"), STAT_FindOuterChilds, STATGROUP_SaveSystem);
//DECLARE_CYCLE_STAT(TEXT("Object Initialization"), STAT_ObjectInit, STATGROUP_SaveSystem);
DECLARE_CYCLE_STAT(TEXT("IsOuterSaved"), STAT_OuterSearch, STATGROUP_SaveSystem);
DECLARE_CYCLE_STAT(TEXT("Object Load"), STAT_ObjectLoad, STATGROUP_SaveSystem);



//	Begin SaveStruct
struct FSaveGameStruct : public FObjectAndNameAsStringProxyArchive
{
	FSaveGameStruct(FArchive& InInnerArchive)
		: FObjectAndNameAsStringProxyArchive(InInnerArchive, true)
	{
		//Save only UPROPERTY() with "SaveGame" flag enabled
		ArIsSaveGame = true;
		ArNoDelta = true;
	}
};
//	End   SaveStruct

//	Begin SaveSystem
UCLASS()
class SAVESYSTEM_API USaveGameSlot : public USaveGame, public ISaveSystemBase, public FRunnable
{
	GENERATED_BODY()

public:

	//	TO DO : Add Delegate To Start and finish of Start/Load

	UPROPERTY()
	bool bDebugEnable;

	UPROPERTY()
	/* This parameter determines whether object parameters
	* such as pointers to other objects or actors (if marked as 'SaveGame')
	* will be saved as other parameters (eg integer or boolean), or skipped */
	bool bSaveObjectProperty;	//	TO DO : Deprecate

	UPROPERTY()
	/* Determines including children of children when saving ObjectParameter */
	bool bIncludeDescendants;

	UPROPERTY()
	bool bUseUObjectSerialize;

	UPROPERTY(BlueprintAssignable, Transient)
	FSaveSystemCompleteSignatureBP OnSaveComplete;

	UPROPERTY(BlueprintAssignable, Transient)
	FSaveSystemCompleteSignatureBP OnLoadComplete;

	FSaveSystemCompleteSignature OnThreadSaveComplete;
	FSaveSystemCompleteSignature OnThreadLoadComplete;


protected:

	UPROPERTY()
	TArray<FObjectRecord> ObjectsRecord;

	FCriticalSection Mutex;

private:

	UPROPERTY()
	FDateTime SaveTime;

	FRunnableThread* Thread;

	UPROPERTY()
	bool bUseParallelFor;

	bool bSaveWithThread;
	bool bLoadWithThread;

	TArray<UObject*> BufferArr;

	UWorld* CurrWorld;

	FThreadCompleteInternalSignature InternalThreadComplete;

public:

	USaveGameSlot(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	~USaveGameSlot();

	virtual void Serialize(FArchive& Ar) override;

	//	Begin ISaveSystemBase interface
	virtual void Save(TArray<UObject*>& ObjectsPtr);

	virtual void Load(UWorld* World);
	//	End   SaveSystemBase interface

private:

	inline void ProcessingObjectSave(TArray<UObject*>& ObjectsPtr, int32& i);

	void ThreadPrepare();

public:

	void MultithreadSave(const TArray<UObject*>& ObjectsPtr);

	void MultithreadLoad(UWorld* World);

	FORCEINLINE FDateTime GetSaveTime() const { return SaveTime; }

	//	FRunnable interface
	virtual bool Init() override;
	virtual uint32 Run() override;
	virtual void Stop() override;

	UFUNCTION()
	void SetUseParallelFor(bool IsUse) { bUseParallelFor = IsUse; }

	UFUNCTION()
	FORCEINLINE bool IsUseParallelFor() const;

	UFUNCTION()
	FORCEINLINE bool IsSaveWithThread() const { return bSaveWithThread; }

	UFUNCTION()
	FORCEINLINE bool IsLoadWithThread() const { return bLoadWithThread; }

protected:

	/**	Check if outer pointer contains in Save Array of objects
	* @param OuterPtr - Pointer to Object`s outer
	* @param OutIndex - return Object index in SaveArray if was found, else return 0
	* @return - Return true if Object pointer was found and return Object index in SaveArray
	*/
	bool IsObjectSaved(const UClass* ObjectClass, const FName ObjectName, int32& OutIndex);

	virtual FObjectRecord SaveObject(UObject* ObjectPtr);

private:

	void SaveOnlyOuterRelatedChilds(const TArray<UObject*>& OuterChilds, TArray<FObjectRecord>& Savedrecords, UObjectBase*& LastOuter, int32 Index);

protected:

	virtual TArray<FObjectRecord> SaveObjectsChilds(UObjectBase* OuterPtr, bool bIncludeNestedObjects = false);

	virtual UObject* LoadObject(const FObjectRecord& ObjectRecord, UWorld* World, UObject* OptionalOuter = nullptr);

	/**Check if FProperty refer flags "SaveGame" and NOT "Transient"
	*/
	bool IsSavableProperty(FProperty* Property) const;

	/**Iterate throuth all object UProperty and fulfill array with UPropery with "SaveGame" flag and NOT "Transient"
	* @param OuterObj - Outer to search for
	* @param OutArr - OutputArray
	*/
	template <class T>
	void GetObjectSavableProperties(const UObjectBase* OuterObj, TArray<T*>& OutArr) const;

	virtual bool FindOuterSavableChildObjects(const UObjectBase* Outer, TArray<UObject*>& OutArray, bool bIncludeNestedObjects = false);

	TArray<UObject*> FilterSaveble(const UObjectBase* OuterPtr, const TArray<FObjectPropertyBase*>& SavebleObjectProperty, TArray<UObject*>& ObjectsToSave);

private:
};
