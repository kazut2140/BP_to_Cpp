// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "QuestTriggerCollect.generated.h"

UCLASS()
class BLUEPRINTSTOCPP_API AQuestTriggerCollect : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AQuestTriggerCollect();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* Root;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USphereComponent* Sphere;

};
