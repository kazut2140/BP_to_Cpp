// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameMode.h"

AQuestManager* UQuestLibrary::GetQuestManager()
{
	AGameMode* GameMode = Cast<AGameMode>(UGameplayStatics::GetGameMode(nullptr));
	return nullptr;
}
