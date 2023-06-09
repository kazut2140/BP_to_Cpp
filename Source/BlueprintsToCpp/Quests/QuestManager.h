// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QuestInfo.h"
#include "QuestManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCompletedQuestSignature, int32, Index);

UCLASS()
class BLUEPRINTSTOCPP_API AQuestManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AQuestManager();

	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void CompleteQuest(FName QuestId, bool CompleteWholeQuest);

	UFUNCTION(BlueprintPure)
	FQuestInfo GetQuest(FName Name) const;

	UFUNCTION(BlueprintPure, BlueprintImplementableEvent)
	TArray<FQuestInfo> GetQuests();

	UFUNCTION(BlueprintPure, BlueprintImplementableEvent)
	bool IsActiveIndex(int32 Index);


	UFUNCTION(BlueprintPure, BlueprintImplementableEvent)
	bool IsActiveQuest(FName Name) const;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FCompletedQuestSignature CompletedQuest;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// PureはBlueprintCallableも含まれる
	UFUNCTION(BlueprintPure, BlueprintImplementableEvent)
	int32 GetQuestIndex(FName QuestId) const;

public:	
	// Called every frame
	// アクタはこの名前
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FQuestInfo> QuestList;
};
