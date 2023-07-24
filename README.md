# SaveSystem Plugin
Save system wich capable of properly serialize and desirialize different objects, actors, components.
Can easely be expanded by inheritance.
Serialize all UPROPERTY with SaveGame specifier
Can save and respawn Object, Actors wich both placed in editor or spawned runtime. Correctly return position in world space.
Actor Components, Scene Components, Primitive components also properly serialized with variables and correct order of assigned components to actor.
Scene Components and Primitive Components save transform in world, physical state, velocity wich also can be restored at loading

## Library vesions

Tested on Unreal Engine 4.25.4

## Installing

1. Copy all folders into [ProjectRootDir]/Plugins/SaveSystem.

2. Open [ProjectName].build.cs and add the following code in the constructor.

````
PublicDependencyModuleNames.AddRange(new string[] { "SaveSystem" });
PrivateDependencyModuleNames.AddRange(new string[] { "SaveSystem" });
````

3. Generate Visual Studio project file (**Find in project root dir [ProjectName].uproject -> RMB -> Generate Visual Studio project file**)
and after that you will be able to compile project

## Usage
````
#include <SaveSystem/Public/SaveGame/SaveActorComponents/SaveSceneComponent.h>
````

Example of saving process

````
	void SaveArrayObjects(TArray<UObject*> ArrayToSave, FString SaveSlotName)
	{
		USaveGameActors* SaveGame = NewObject<USaveActorWithComponentsScene>(GetTransientPackage());
		TArray<UObject*> HeapSaveArr(ArrayToSave);
		SaveGame->Save(HeapSaveArr);
		UGameplayStatics::SaveGameToSlot(SaveGame, SaveSlotName, 0);
	}
````
Example of loading process
````
	void LoadObjects(FString SaveSlotName)
	{
		USaveGameActors* SaveGame = StaticCast<USaveActorWithComponentsScene*>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, 0));
		SaveGame->Load(GetWorld());
	}
````
