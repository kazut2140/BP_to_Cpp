// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Quests/QuestManager.h"
#include "MainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class BLUEPRINTSTOCPP_API AMainGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	AQuestManager* GetQuestManager();

protected:
	UPROPERTY(BlueprintReadOnly)
	AQuestManager* QuestManager;
};
