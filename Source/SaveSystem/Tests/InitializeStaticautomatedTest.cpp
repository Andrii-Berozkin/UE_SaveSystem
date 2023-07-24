// Copyright Andrii Berozkin. All Rights Reserved.

#pragma once

#include <CoreTypes.h>
#include <CoreMinimal.h>
#include <Containers/UnrealString.h>
#include <UObject/NameTypes.h>
#include <Misc/AutomationTest.h>
//#include <Tests/AutomationEditorCommon.h>
#include <Tests/AutomationCommon.h>

#include "TestActors.h"

#include <SaveSystem/Public/SaveGame/InitializeStatics.h>
#include <SaveSystem/Public/StructRecord/ActorRecord/ActorRecord.h>


//StaticsTest_Map

DECLARE_LOG_CATEGORY_EXTERN(FLogTest, Log, All);
DEFINE_LOG_CATEGORY(FLogTest);

static FName TestMapPath("SaveSystem/Content/Tests/");

inline UWorld* GetWorldForTestSafe()
{
	if (GEditor && GEditor->GetWorldContexts().Num() && GEditor->GetWorldContexts()[0].World())
	{
		return GEditor->GetWorldContexts()[0].World();
	}

	if (GEngine && GEngine->GetWorldContexts().Num() && GEngine->GetWorldContexts()[0].World())
	{
		return GEngine->GetWorldContexts()[0].World();
	}

	return nullptr;
}

inline UWorld* GetTestWorld()
{
	if (GEngine)
	{
		if (FWorldContext* WorldContext = GEngine->GetWorldContextFromPIEInstance(0))
		{
			return WorldContext->World();
		}
	}
	return nullptr;
}

//	4 Cases of Self and Outer ptr

inline FActorRecord GetRecordSelfPtrAndOuterPtr(AActor* Actor)
{
	FActorRecord ActorRecord;
	ActorRecord.SelfPointer = Actor;
	ActorRecord.OuterPtr = Actor->GetOuter();
	return ActorRecord;
}

inline FActorRecord GetRecordSelfPtr(AActor* Actor)
{
	FActorRecord ActorRecord;
	ActorRecord.SelfPointer = Actor;
	ActorRecord.OuterPtr = nullptr;
	return ActorRecord;
}

inline FActorRecord GetRecordOuterPtr(AActor* Actor)
{
	FActorRecord ActorRecord;
	ActorRecord.SelfPointer = nullptr;
	ActorRecord.OuterPtr = Actor->GetOuter();
	return ActorRecord;
}

inline FActorRecord GetRecordSelfAndOuterNull(AActor* Actor)
{
	FActorRecord ActorRecord;
	ActorRecord.SelfPointer = nullptr;
	ActorRecord.OuterPtr = nullptr;
	return ActorRecord;
}

//	16 Cases of Self Class,Name and Outer Class,Name

	//	4 Casese of Self Class,Name ; Outer by default
inline FActorRecord GetRecordSelfClassName(AActor* Actor)
{
	FActorRecord ActorRecord;
	ActorRecord.Class = Actor->GetClass();
	ActorRecord.Name = Actor->GetFName();
	ActorRecord.OuterClass = nullptr;
	ActorRecord.OuterName = NAME_None;
	return ActorRecord;
}

inline FActorRecord GetRecordSelfClass(AActor* Actor)
{
	FActorRecord ActorRecord;
	ActorRecord.Class = Actor->GetClass();
	ActorRecord.Name = NAME_None;
	ActorRecord.OuterClass = nullptr;
	ActorRecord.OuterName = NAME_None;
	return ActorRecord;
}

inline FActorRecord GetRecordSelfName(AActor* Actor)
{
	FActorRecord ActorRecord;
	ActorRecord.Class = nullptr;
	ActorRecord.Name = Actor->GetFName();
	ActorRecord.OuterClass = nullptr;
	ActorRecord.OuterName = NAME_None;
	return ActorRecord;
}

inline FActorRecord GetRecordSelfClassNameEmpty(AActor* Actor)
{
	FActorRecord ActorRecord;
	ActorRecord.Class = nullptr;
	ActorRecord.Name = NAME_None;
	ActorRecord.OuterClass = nullptr;
	ActorRecord.OuterName = NAME_None;
	return ActorRecord;
}
	//

	//	4 Casese of Outer Class,Name ; Self by default
inline FActorRecord GetRecordOuterClassName(AActor* Actor)
{
	FActorRecord ActorRecord;
	ActorRecord.Class = nullptr;
	ActorRecord.Name = NAME_None;
	ActorRecord.OuterClass = Actor->GetOuter()->GetClass();
	ActorRecord.OuterName = Actor->GetOuter()->GetFName();
	return ActorRecord;
}

inline FActorRecord GetRecordOuterClass(AActor* Actor)
{
	FActorRecord ActorRecord;
	ActorRecord.Class = nullptr;
	ActorRecord.Name = NAME_None;
	ActorRecord.OuterClass = Actor->GetOuter()->GetClass();
	ActorRecord.OuterName = NAME_None;
	return ActorRecord;
}

inline FActorRecord GetRecordOuterName(AActor* Actor)
{
	FActorRecord ActorRecord;
	ActorRecord.Class = nullptr;
	ActorRecord.Name = NAME_None;
	ActorRecord.OuterClass = nullptr;
	ActorRecord.OuterName = Actor->GetOuter()->GetFName();
	return ActorRecord;
}

inline FActorRecord GetRecordOuterClassNameEmpty(AActor* Actor)
{
	FActorRecord ActorRecord;
	ActorRecord.Class = nullptr;
	ActorRecord.Name = NAME_None;
	ActorRecord.OuterClass = nullptr;
	ActorRecord.OuterName = NAME_None;
	return ActorRecord;
}
	//

	//	4 Casese Self Class,Name ; Outer Class
inline FActorRecord GetRecordSelfClassNameAndOuterClass(AActor* Actor)
{
	FActorRecord ActorRecord;
	ActorRecord.Class = Actor->GetClass();
	ActorRecord.Name = Actor->GetFName();
	ActorRecord.OuterClass = Actor->GetOuter()->GetClass();
	ActorRecord.OuterName = NAME_None;
	return ActorRecord;
}

inline FActorRecord GetRecordSelfClassAndOuterClass(AActor* Actor)
{
	FActorRecord ActorRecord;
	ActorRecord.Class = Actor->GetClass();
	ActorRecord.Name = NAME_None;
	ActorRecord.OuterClass = Actor->GetOuter()->GetClass();
	ActorRecord.OuterName = NAME_None;
	return ActorRecord;
}

inline FActorRecord GetRecordSelfNameAndOuterClass(AActor* Actor)
{
	FActorRecord ActorRecord;
	ActorRecord.Class = nullptr;
	ActorRecord.Name = Actor->GetFName();
	ActorRecord.OuterClass = Actor->GetOuter()->GetClass();
	ActorRecord.OuterName = NAME_None;
	return ActorRecord;
}

inline FActorRecord GetRecordSelfClassNameEmptyAndOuterClass(AActor* Actor)
{
	FActorRecord ActorRecord;
	ActorRecord.Class = nullptr;
	ActorRecord.Name = NAME_None;
	ActorRecord.OuterClass = Actor->GetOuter()->GetClass();
	ActorRecord.OuterName = NAME_None;
	return ActorRecord;
}
	//

	//	4 Cases Self Class,Name ; Outer Name
inline FActorRecord GetRecordSelfClassNameAndOuterName(AActor* Actor)
{
	FActorRecord ActorRecord;
	ActorRecord.Class = Actor->GetClass();
	ActorRecord.Name = Actor->GetFName();
	ActorRecord.OuterClass = nullptr;
	ActorRecord.OuterName = Actor->GetOuter()->GetFName();
	return ActorRecord;
}

inline FActorRecord GetRecordSelfClassAndOuterName(AActor* Actor)
{
	FActorRecord ActorRecord;
	ActorRecord.Class = Actor->GetClass();
	ActorRecord.Name = NAME_None;
	ActorRecord.OuterClass = nullptr;
	ActorRecord.OuterName = Actor->GetOuter()->GetFName();
	return ActorRecord;
}

inline FActorRecord GetRecordSelfNameAndOuterName(AActor* Actor)
{
	FActorRecord ActorRecord;
	ActorRecord.Class = nullptr;
	ActorRecord.Name = Actor->GetFName();
	ActorRecord.OuterClass = nullptr;
	ActorRecord.OuterName = Actor->GetOuter()->GetFName();
	return ActorRecord;
}

inline FActorRecord GetRecordSelfClassNameEmptyAndOuterName(AActor* Actor)
{
	FActorRecord ActorRecord;
	ActorRecord.Class = nullptr;
	ActorRecord.Name = NAME_None;
	ActorRecord.OuterClass = nullptr;
	ActorRecord.OuterName = Actor->GetOuter()->GetFName();
	return ActorRecord;
}
	//
//

BEGIN_DEFINE_SPEC(UInitializeStaticTests, "UInitializeStatics.Test", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)
	int32 Counter = 0;
	const FName StaticTestMapName = "StaticsTest_Map";
	const FName StaticTestMapNameExten = FName(StaticTestMapName.ToString() + TEXT(".umap"));
	const FName TestActorName = "VisualTestActor";
	AActor* TestActorPtr = nullptr;
END_DEFINE_SPEC(UInitializeStaticTests)

void UInitializeStaticTests::Define()
{

	BeforeEach([this]() 
		{
			FString TestMapFullName = FPaths::ProjectPluginsDir() + TestMapPath.ToString() + StaticTestMapName.ToString();
			FPaths::NormalizeFilename(TestMapFullName);
			check(AutomationOpenMap(TestMapFullName));

			UWorld* WorldPtr = GetWorldForTestSafe();

			if (AActor* Actor = StaticCast<AActor*>(StaticFindObjectFast(ATestActor::StaticClass(), WorldPtr->GetCurrentLevel(), TestActorName)))
			{
				Actor->Destroy();
			}

			FActorSpawnParameters Param;
			Param.Name = TestActorName;
			Param.bDeferConstruction = false;
			TestActorPtr = WorldPtr->SpawnActor(ATestActor::StaticClass(), &FTransform::Identity, Param);
			//FAutomationEditorCommonUtils::LoadMap(TestMapFullName);
		});

	Describe("Initialize testing world and actors", [this]() 
		{
			It("Should return true", [this]()
				{
					TestTrue("Value of", true);
				});

			It("Should be equal 'World-GetFName()' == 'StaticsTest_Map' ", [this]()
				{
					UWorld* WorldPtr = GetWorldForTestSafe();
					FName WorldName;
					if (WorldPtr) { WorldName = WorldPtr->GetFName(); }
					TestEqual("Map name equal", StaticTestMapName, WorldName);
				});

			It("Should found existed Test actor with name", [this]()
				{
					TestNotNull("Test actor exist", TestActorPtr);
				});
		});

	LatentIt("Should rename EXIST actor and spawn new one from different from GameThread", FTimespan(0, 0, 2), [this](const FDoneDelegate Done) 
		{
			AsyncTask(ENamedThreads::StatsThread, [this, &Done]() 
				{
					FActorRecord ActorRecord = GetRecordSelfClassName(TestActorPtr);
					FName NameWhileExist, NameAfterDestroyAndInitialize = TestActorPtr->GetFName();

					TestActorPtr->Destroy();

					AActor* InitializedActor = nullptr;
					InitializedActor = UInitializeStatics::InitializeActor(ActorRecord, GetWorldForTestSafe());
					if (TestActorPtr->IsPendingKillOrUnreachable()) { NameAfterDestroyAndInitialize = TestActorPtr->GetFName(); }
					bool bSuccess = InitializedActor != nullptr && InitializedActor != TestActorPtr && NameWhileExist != NameAfterDestroyAndInitialize;
					TestTrue("Initiled actor was spawn from GameThread", bSuccess);
					//Done.ExecuteIfBound();
				});

			FPlatformProcess::Sleep(0.1f);
			Done.Execute();
		});

	Describe("Intialize actor with existed", [this]() 
		{

			Describe("With Pointers", [this]()
				{
					It("Should find EXISTED actor | with SelfPointer, OuterPtr", [this]()
						{
							FActorRecord ActRecord = GetRecordSelfPtrAndOuterPtr(TestActorPtr);

							AActor* InitializedActor = nullptr;
							InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
							TestEqual("Initialized actor equal existed", TestActorPtr, InitializedActor);
						});

					It("Should find EXISTED actor | with SelfPointer", [this]()
						{
							FActorRecord ActRecord = GetRecordSelfPtr(TestActorPtr);

							AActor* InitializedActor = nullptr;
							InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
							TestEqual("Initialized actor equal existed", TestActorPtr, InitializedActor);
						});

					It("Shouldn`t find EXISTED actor | with OuterPtr", [this]()
						{
							FActorRecord ActRecord = GetRecordOuterPtr(TestActorPtr);

							AActor* InitializedActor = nullptr;
							InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
							TestNull("Initialized actor equal existed", InitializedActor);
						});

					It("Shouldn`t find EXISTED actor | with full empty ActorRecord", [this]()
						{
							FActorRecord ActRecord = GetRecordSelfAndOuterNull(TestActorPtr);

							AActor* InitializedActor = nullptr;
							InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
							TestNull("Initialized actor equal existed", InitializedActor);
						});
				});

			Describe("With Class,Name", [this]() 
				{
					Describe("Self Class,Name", [this]() 
						{
							It("Should find EXISTED | with Self Class,Name", [this]()
								{
									FActorRecord ActRecord = GetRecordSelfClassName(TestActorPtr);

									AActor* InitializedActor = nullptr;
									InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
									TestEqual("Equal to TestActor", InitializedActor, TestActorPtr);
								});
							It("Should spawn with generic name insted find EXISTED | with Self Class", [this]()
								{
									FActorRecord ActRecord = GetRecordSelfClass(TestActorPtr);

									AActor* InitializedActor = nullptr;
									InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
									bool bSuccess = InitializedActor != nullptr && InitializedActor != TestActorPtr;
									TestTrue("InitializedActor != nullptr && InitializedActor != TestActorPtr", bSuccess);
								});
							It("Should find EXISTED | with Self Name", [this]()
								{
									FActorRecord ActRecord = GetRecordSelfName(TestActorPtr);

									AActor* InitializedActor = nullptr;
									InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
									TestEqual("Equal to TestActor", InitializedActor, TestActorPtr);
								});
							It("Shouldn`t find EXISTED | with empty", [this]()
								{
									FActorRecord ActRecord = GetRecordSelfClassNameEmpty(TestActorPtr);

									AActor* InitializedActor = nullptr;
									InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
									TestNull("Initialized found null", InitializedActor);
								});
						});

					Describe("Outer Class,Name", [this]() 
						{
							It("Shouldn`t find EXISTED | with Outer Class,Name", [this]()
								{
									FActorRecord ActRecord = GetRecordOuterClassName(TestActorPtr);

									AActor* InitializedActor = nullptr;
									InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
									TestNull("Initialized found null", InitializedActor);
								});
							It("Shouldn`t find EXISTED | with Outer Class", [this]()
								{
									FActorRecord ActRecord = GetRecordOuterClass(TestActorPtr);

									AActor* InitializedActor = nullptr;
									InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
									TestNull("Initialized found null", InitializedActor);
								});
							It("Shouldn`t find EXISTED | with Outer Name", [this]()
								{
									FActorRecord ActRecord = GetRecordOuterName(TestActorPtr);

									AActor* InitializedActor = nullptr;
									InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
									TestNull("Initialized found null", InitializedActor);
								});
							It("Shouldn`t find EXISTED | with empty", [this]()
								{
									FActorRecord ActRecord = GetRecordOuterClassNameEmpty(TestActorPtr);

									AActor* InitializedActor = nullptr;
									InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
									TestNull("Initialized found null", InitializedActor);
								});
						});

					Describe("Self Class,Name & Outer Class", [this]() 
						{
							It("Should find EXISTED | with Self Class,Name & Outer Class", [this]()
								{
									FActorRecord ActRecord = GetRecordSelfClassNameAndOuterClass(TestActorPtr);

									AActor* InitializedActor = nullptr;
									InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
									TestEqual("Equal to TestActor", InitializedActor, TestActorPtr);
								});
							It("Should spawn with generic name insted  find EXISTED | with Self Class & Outer Class", [this]()
								{
									FActorRecord ActRecord = GetRecordSelfClassAndOuterClass(TestActorPtr);

									AActor* InitializedActor = nullptr;
									InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
									bool bSuccess = InitializedActor != nullptr && InitializedActor != TestActorPtr;
									TestTrue("InitializedActor != nullptr && InitializedActor != TestActorPtr", bSuccess);
								});
							It("Should find EXISTED | with Self Name & Outer Class", [this]()
								{
									FActorRecord ActRecord = GetRecordSelfNameAndOuterClass(TestActorPtr);

									AActor* InitializedActor = nullptr;
									InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
									TestEqual("Equal to TestActor", InitializedActor, TestActorPtr);
								});
							It("Shouldn`t find EXISTED | with Self empty Class,Name & Outer Class", [this]()
								{
									FActorRecord ActRecord = GetRecordSelfClassNameEmptyAndOuterClass(TestActorPtr);

									AActor* InitializedActor = nullptr;
									InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
									TestNull("Initialized found null", InitializedActor);
								});
						});

					Describe("Self Class,Name & Outer Name", [this]() 
						{
							It("Should find EXISTED | with Self Class,Name & Outer Name", [this]()
								{
									FActorRecord ActRecord = GetRecordSelfClassNameAndOuterName(TestActorPtr);

									AActor* InitializedActor = nullptr;
									InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
									TestEqual("Equal to TestActor", InitializedActor, TestActorPtr);
								});
							It("Should spawn with generic name insted find EXISTED | with Self Class & Outer Name", [this]()
								{
									FActorRecord ActRecord = GetRecordSelfClassAndOuterName(TestActorPtr);

									AActor* InitializedActor = nullptr;
									InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
									bool bSuccess = InitializedActor != nullptr && InitializedActor != TestActorPtr;
									TestTrue("InitializedActor != nullptr && InitializedActor != TestActorPtr", bSuccess);
								});
							It("Should find EXISTED | with Self Name & Outer Name", [this]()
								{
									FActorRecord ActRecord = GetRecordSelfNameAndOuterName(TestActorPtr);

									AActor* InitializedActor = nullptr;
									InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
									TestEqual("Equal to TestActor", InitializedActor, TestActorPtr);
								});
							It("Shouldn`t find EXISTED | with Self empty Class,Name & Outer Name", [this]()
								{
									FActorRecord ActRecord = GetRecordSelfClassNameEmptyAndOuterName(TestActorPtr);

									AActor* InitializedActor = nullptr;
									InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
									TestNull("Initialized found null", InitializedActor);
								});
						});

				});
		});

	It("Should rename existed actor which mark PendingKill", [this]() 
		{
			FActorRecord ActRecord = GetRecordSelfClassName(TestActorPtr);
			FName ActorNameBeforeDestroy, ActorNameAfterDestroyAndInitialize = TestActorPtr->GetFName();

			TestActorPtr->Destroy();

			AActor* InitializedActor = nullptr;
			InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());

			if (TestActorPtr->IsPendingKillOrUnreachable()) { ActorNameAfterDestroyAndInitialize = TestActorPtr->GetFName(); }
			TestNotEqual("Must be different after intialization", ActorNameBeforeDestroy, ActorNameAfterDestroyAndInitialize);
		});

	Describe("Intialize actor with existed actor but mark as PendingKill", [this]()
		{

			Describe("With pointers", [this]() 
				{
					It("Should return nullptr | with SelfPointer, OuterPtr", [this]()
						{
							FActorRecord ActRecord = GetRecordSelfPtrAndOuterPtr(TestActorPtr);

							TestActorPtr->Destroy();

							AActor* InitializedActor = nullptr;
							InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
							TestNull("Initialized actor must be nullptr", InitializedActor);
						});
					It("Should return nullptr | with SelfPointer", [this]()
						{
							FActorRecord ActRecord = GetRecordSelfPtr(TestActorPtr);

							TestActorPtr->Destroy();

							AActor* InitializedActor = nullptr;
							InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
							TestNull("Initialized actor must be nullptr", InitializedActor);
						});
					It("Should return nullptr | with OuterPtr", [this]()
						{
							FActorRecord ActRecord = GetRecordOuterPtr(TestActorPtr);

							TestActorPtr->Destroy();

							AActor* InitializedActor = nullptr;
							InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
							TestNull("Initialized actor must be nullptr", InitializedActor);
						});
					It("Should return nullptr | with full empty ActorRecord", [this]()
						{
							FActorRecord ActRecord = GetRecordSelfAndOuterNull(TestActorPtr);

							TestActorPtr->Destroy();

							AActor* InitializedActor = nullptr;
							InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
							TestNull("Initialized actor must be nullptr", InitializedActor);
						});
				});

			Describe("With Class,Name", [this]() 
				{
					Describe("Self Class, Name", [this]() 
						{
							It("Should spawn new actor, and rename EXISTED | with Self Class,Name", [this]()
								{
									FActorRecord ActRecord = GetRecordSelfClassName(TestActorPtr);

									TestActorPtr->Destroy();

									AActor* InitializedActor = nullptr;
									InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
									bool bSuccess = InitializedActor != nullptr && InitializedActor != TestActorPtr;
									TestTrue("InitializedActor != nullptr && InitializedActor != TestActorPtr", bSuccess);
								});
							It("Should spawn with generic name insted find EXISTED | with Self Class", [this]()
								{
									FActorRecord ActRecord = GetRecordSelfClass(TestActorPtr);

									TestActorPtr->Destroy();

									AActor* InitializedActor = nullptr;
									InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
									bool bSuccess = InitializedActor != nullptr && InitializedActor != TestActorPtr;
									TestTrue("InitializedActor != nullptr && InitializedActor != TestActorPtr", bSuccess);
								});
							It("Should return nullptr | with Self Name", [this]()
								{
									FActorRecord ActRecord = GetRecordSelfName(TestActorPtr);

									TestActorPtr->Destroy();

									AActor* InitializedActor = nullptr;
									InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
									TestNull("Initialized must be nullptr", InitializedActor);
								});
							It("Should return nullptr | with empty", [this]()
								{
									FActorRecord ActRecord = GetRecordSelfClassNameEmpty(TestActorPtr);

									TestActorPtr->Destroy();

									AActor* InitializedActor = nullptr;
									InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
									TestNull("Initialized must be nullptr", InitializedActor);
								});
						});
					
					Describe("Outer Class,Name", [this]() 
						{
							It("Should return nullptr | with Outer Class,Name", [this]()
								{
									FActorRecord ActRecord = GetRecordOuterClassName(TestActorPtr);

									TestActorPtr->Destroy();

									AActor* InitializedActor = nullptr;
									InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
									TestNull("Initialized found null", InitializedActor);
								});
							It("Should return nullptr | with Outer Class", [this]()
								{
									FActorRecord ActRecord = GetRecordOuterClass(TestActorPtr);

									TestActorPtr->Destroy();

									AActor* InitializedActor = nullptr;
									InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
									TestNull("Initialized found null", InitializedActor);
								});
							It("Should return nullptr | with Outer Name", [this]()
								{
									FActorRecord ActRecord = GetRecordOuterName(TestActorPtr);

									TestActorPtr->Destroy();

									AActor* InitializedActor = nullptr;
									InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
									TestNull("Initialized found null", InitializedActor);
								});
							It("Should return nullptr | with empty", [this]()
								{
									FActorRecord ActRecord = GetRecordOuterClassNameEmpty(TestActorPtr);

									TestActorPtr->Destroy();

									AActor* InitializedActor = nullptr;
									InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
									TestNull("Initialized found null", InitializedActor);
								});
						});

					Describe("Self Class,Name & Outer Class", [this]() 
						{
							It("Should spawn new actor, and rename EXISTED | with Self Class,Name & Outer Class", [this]()
								{
									FActorRecord ActRecord = GetRecordSelfClassNameAndOuterClass(TestActorPtr);

									TestActorPtr->Destroy();

									AActor* InitializedActor = nullptr;
									InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
									bool bSuccess = InitializedActor != nullptr && InitializedActor != TestActorPtr;
									TestTrue("InitializedActor != nullptr && InitializedActor != TestActorPtr", bSuccess);
								});
							It("Should spawn with generic name insted  find EXISTED | with Self Class & Outer Class", [this]()
								{
									FActorRecord ActRecord = GetRecordSelfClassAndOuterClass(TestActorPtr);

									TestActorPtr->Destroy();

									AActor* InitializedActor = nullptr;
									InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
									bool bSuccess = InitializedActor != nullptr && InitializedActor != TestActorPtr;
									TestTrue("InitializedActor != nullptr && InitializedActor != TestActorPtr", bSuccess);
								});
							It("Should return nullptr | with Self Name & Outer Class", [this]()
								{
									FActorRecord ActRecord = GetRecordSelfNameAndOuterClass(TestActorPtr);

									TestActorPtr->Destroy();

									AActor* InitializedActor = nullptr;
									InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
									TestNull("Initialized must be nullptr", InitializedActor);
								});
							It("Should return nullptr | with Self empty Class,Name & Outer Class", [this]()
								{
									FActorRecord ActRecord = GetRecordSelfClassNameEmptyAndOuterClass(TestActorPtr);

									TestActorPtr->Destroy();

									AActor* InitializedActor = nullptr;
									InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
									TestNull("Initialized must be nullptr", InitializedActor);
								});
						});

					Describe("Self Class,Name & Outer Name", [this]()
						{
							It("Should spawn new actor, and rename EXISTED | with Self Class,Name & Outer Name", [this]()
								{
									FActorRecord ActRecord = GetRecordSelfClassNameAndOuterName(TestActorPtr);

									TestActorPtr->Destroy();

									AActor* InitializedActor = nullptr;
									InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
									bool bSuccess = InitializedActor != nullptr && InitializedActor != TestActorPtr;
									TestTrue("InitializedActor != nullptr && InitializedActor != TestActorPtr", bSuccess);
								});
							It("Should spawn with generic name insted find EXISTED | with Self Class & Outer Name", [this]()
								{
									FActorRecord ActRecord = GetRecordSelfClassAndOuterName(TestActorPtr);

									TestActorPtr->Destroy();

									AActor* InitializedActor = nullptr;
									InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
									bool bSuccess = InitializedActor != nullptr && InitializedActor != TestActorPtr;
									TestTrue("InitializedActor != nullptr && InitializedActor != TestActorPtr", bSuccess);
								});
							It("Should return nullptr | with Self Name & Outer Name", [this]()
								{
									FActorRecord ActRecord = GetRecordSelfNameAndOuterName(TestActorPtr);

									TestActorPtr->Destroy();

									AActor* InitializedActor = nullptr;
									InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
									TestNull("Initialized must be nullptr", InitializedActor);
								});
							It("Should return nullptr | with Self empty Class,Name & Outer Name", [this]()
								{
									FActorRecord ActRecord = GetRecordSelfClassNameEmptyAndOuterName(TestActorPtr);

									TestActorPtr->Destroy();

									AActor* InitializedActor = nullptr;
									InitializedActor = UInitializeStatics::InitializeActor(ActRecord, GetWorldForTestSafe());
									TestNull("Initialized must be nullptr", InitializedActor);
								});
						});
				});
		});

	AfterEach([this]()
		{
			TestActorPtr->Destroy(false, true);
			GetWorldForTestSafe()->RemoveActor(TestActorPtr, true);
			ADD_LATENT_AUTOMATION_COMMAND(FExitGameCommand);
		});
}