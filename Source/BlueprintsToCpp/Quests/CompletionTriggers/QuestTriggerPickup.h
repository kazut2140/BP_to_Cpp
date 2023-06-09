// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Quests/QuestManager.h"
#include "QuestTriggerPickup.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class BLUEPRINTSTOCPP_API UQuestTriggerPickup : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UQuestTriggerPickup();

	UFUNCTION(BlueprintCallable)
	void Pickup();

protected:

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName QuestId;
};
