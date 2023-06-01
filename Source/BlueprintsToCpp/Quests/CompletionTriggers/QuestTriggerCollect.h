// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Quests/QuestManager.h"
#include "QuestTriggerCollect.generated.h"

UCLASS()
class BLUEPRINTSTOCPP_API AQuestTriggerCollect : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AQuestTriggerCollect();
protected:
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp,
		class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	UFUNCTION(BlueprintPure)
	bool IsCorrectItem(AActor* Item);

	UFUNCTION(BlueprintPure)
	bool HasNotSeenItem(AActor* ItemToFind);

	UFUNCTION(BlueprintCallable)
	void MarkItemSeen(AActor* NewItem);

	UFUNCTION(BlueprintCallable)
	void NotifyQuestComplete();

	UFUNCTION(BlueprintPure, BlueprintImplementableEvent)
	AQuestManager* GetQuestManager() const;


protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* Root;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USphereComponent* Sphere;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName QuestId;
	UPROPERTY(BlueprintReadOnly)
	TSet<AActor*> SeenItems;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName ItemTag;
};
