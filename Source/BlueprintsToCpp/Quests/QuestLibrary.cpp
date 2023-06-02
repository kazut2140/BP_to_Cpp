// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Core/MainGameMode.h"
#include "Engine/World.h"
#include "GameFramework/GameMode.h"

AQuestManager* UQuestLibrary::GetQuestManager(const UObject* WorldContextObject)
{
	AMainGameMode* MainGameMode = Cast<AMainGameMode>(UGameplayStatics::GetGameMode(WorldContextObject));
	if (IsValid(MainGameMode))
	{
		UE_LOG(LogTemp, Warning, TEXT("Library"));
	}
	
	return MainGameMode->GetQuestManager();
}