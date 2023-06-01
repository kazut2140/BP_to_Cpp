// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Quests/QuestManager.h"
#include "QuestTriggerVolume.generated.h"

UCLASS()
class BLUEPRINTSTOCPP_API AQuestTriggerVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AQuestTriggerVolume();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp,
		class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	UFUNCTION(BlueprintPure, BlueprintImplementableEvent)
	AQuestManager* GetQuestManager() const;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* Root;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBoxComponent* Box;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName QuestId;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool CompleteWholeQuest;

	bool bDoOnce = true;

};
