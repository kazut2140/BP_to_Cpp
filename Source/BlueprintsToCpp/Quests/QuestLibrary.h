// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "QuestManager.h"
#include "QuestLibrary.generated.h"

/**
 * 
 */
UCLASS()
class BLUEPRINTSTOCPP_API UQuestLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	static AQuestManager* GetQuestManager(const UObject* WorldContextObject);
};
