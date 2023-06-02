// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameMode.h"
#include "Engine/World.h"

AQuestManager* AMainGameMode::GetQuestManager()
{
	if (IsValid(QuestManager))
	{
		return QuestManager;
	}

	FString aAssetPath = "/Game/Quests/BP_QuestManager.BP_QuestManager_C";
	TSubclassOf<AQuestManager> aActorClass = TSoftClassPtr<AQuestManager>(FSoftObjectPath(*aAssetPath)).LoadSynchronous();
	if (aActorClass != nullptr) {

		// �X�|�[��
		AQuestManager* aQuestManager = GetWorld()->SpawnActor<AQuestManager>(aActorClass);

		// �X�|�[�������A�N�^�[�։����������������ꍇ
		QuestManager = aQuestManager;
	}

	return QuestManager;
}
