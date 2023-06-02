// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestTriggerPickup.h"
#include "Quests/QuestLibrary.h"

// Sets default values for this component's properties
UQuestTriggerPickup::UQuestTriggerPickup()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UQuestTriggerPickup::Pickup()
{
	UQuestLibrary::GetQuestManager(GetWorld())->CompleteQuest(QuestId, true);
}