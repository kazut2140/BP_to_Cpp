// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "QuestTriggerVolume.generated.h"

UCLASS()
class BLUEPRINTSTOCPP_API AQuestTriggerVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AQuestTriggerVolume();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* Root;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBoxComponent* Box;

};
