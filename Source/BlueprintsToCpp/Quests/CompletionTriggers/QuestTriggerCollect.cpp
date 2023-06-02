// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestTriggerCollect.h"
#include "Quests/QuestLibrary.h"

// Sets default values
AQuestTriggerCollect::AQuestTriggerCollect()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	
	SetRootComponent(Root);
	Sphere->SetupAttachment(Root);
	//Sphere->OnComponentBeginOverlap.AddDynamic(this, &AQuestTriggerCollect::OnOverlapBegin);
}

void AQuestTriggerCollect::BeginPlay()
{
	Super::BeginPlay();
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AQuestTriggerCollect::OnOverlapBegin);
}

void AQuestTriggerCollect::OnOverlapBegin
	(
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult
	)
{
	if (IsCorrectItem(OtherActor) && HasNotSeenItem(OtherActor))
	{
		MarkItemSeen(OtherActor);
		NotifyQuestComplete();
	}
}

bool AQuestTriggerCollect::IsCorrectItem(AActor* Item)
{
	return Item->ActorHasTag(ItemTag);
}

bool AQuestTriggerCollect::HasNotSeenItem(AActor* ItemToFind)
{
	return !SeenItems.Contains(ItemToFind);
}

void AQuestTriggerCollect::MarkItemSeen(AActor* NewItem)
{
	SeenItems.Add(NewItem);
}

void AQuestTriggerCollect::NotifyQuestComplete()
{
	UQuestLibrary::GetQuestManager(GetWorld())->CompleteQuest(QuestId, false);
	//GetQuestManager()->CompleteQuest(QuestId, false);
}