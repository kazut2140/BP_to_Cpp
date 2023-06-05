// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameMode.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "UserWidget.h"


//void AMainGameMode::BeginPlay()
//{
//	Super::BeginPlay();
//	FString Path = "/Game/UI/WBP_MainDisplay.WBP_MainDisplay_C";
//	APlayerController* aPlayerController = UGameplayStatics::GetPlayerController(this, 0);
//
//	TSubclassOf<class UUserWidget> WidgetClass = TSoftClassPtr<UUserWidget>(FSoftObjectPath(*Path)).LoadSynchronous();
//	UUserWidget* UserWidget = CreateWidget<UUserWidget>(GetWorld(), WidgetClass);
//}

AQuestManager* AMainGameMode::GetQuestManager()
{
	if (IsValid(QuestManager))
	{
		return QuestManager;
	}

	FString AssetPath = "/Game/Quests/BP_QuestManager.BP_QuestManager_C";
	TSubclassOf<AQuestManager> QuestManagerClass = TSoftClassPtr<AQuestManager>(FSoftObjectPath(*AssetPath)).LoadSynchronous();
	if (QuestManagerClass != nullptr) {

		// スポーン
		AQuestManager* NewQuestManager = GetWorld()->SpawnActor<AQuestManager>(QuestManagerClass);

		// スポーンしたアクターへ何か処理をしたい場合
		QuestManager = NewQuestManager;
	}

	return QuestManager;
}