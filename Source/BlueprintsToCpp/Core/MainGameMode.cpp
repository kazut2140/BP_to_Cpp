// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameMode.h"
#include "Engine/World.h"


void AMainGameMode::BeginPlay()
{
	Super::BeginPlay();
	FString Path = "/Game/UI/WBP_MainDisplay.WBP_MainDisplay_C";
	TSubclassOf<class UUserWidget> WidgetClass = TSoftClassPtr<UUserWidget>(FSoftObjectPath(*Path)).LoadSynchronous();
}

//AQuestManager* AMainGameMode::GetQuestManager()
//{
//	if (IsValid(QuestManager))
//	{
//		return QuestManager;
//	}
//
//	FString aAssetPath = "/Game/Quests/BP_QuestManager.BP_QuestManager_C";
//	TSubclassOf<AQuestManager> aActorClass = TSoftClassPtr<AQuestManager>(FSoftObjectPath(*aAssetPath)).LoadSynchronous();
//	if (aActorClass != nullptr) {
//
//		// スポーン
//		AQuestManager* aQuestManager = GetWorld()->SpawnActor<AQuestManager>(aActorClass);
//
//		// スポーンしたアクターへ何か処理をしたい場合
//		QuestManager = aQuestManager;
//	}
//
//	return QuestManager;
//}