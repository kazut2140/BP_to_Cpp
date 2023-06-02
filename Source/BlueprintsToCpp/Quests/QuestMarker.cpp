// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestMarker.h"
#include "Quests/QuestLibrary.h"

// Sets default values
AQuestMarker::AQuestMarker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));

	SetRootComponent(Root);
	ParticleSystem->SetupAttachment(Root);
}

void AQuestMarker::BeginPlay()
{
	// ƒoƒCƒ“ƒh
	UQuestLibrary::GetQuestManager(GetWorld())->CompletedQuest.AddDynamic(this, &AQuestMarker::QuestUpdate);
	RefreshVisibility();
}

void AQuestMarker::RefreshVisibility()
{
	FQuestInfo Quest = UQuestLibrary::GetQuestManager(GetWorld())->GetQuest(QuestName);
	bool EqualProgress = (Quest.Progress == ShowAtProgress);
	bool Visibility = UQuestLibrary::GetQuestManager(GetWorld())->IsActiveQuest(Quest.QuestId) && EqualProgress;
	ParticleSystem->SetVisibility(Visibility);
}

void AQuestMarker::QuestUpdate(int32 Index)
{
	RefreshVisibility();
}