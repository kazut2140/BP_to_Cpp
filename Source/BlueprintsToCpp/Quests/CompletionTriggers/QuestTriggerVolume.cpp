// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestTriggerVolume.h"
#include "Quests/QuestLibrary.h"

// Sets default values
AQuestTriggerVolume::AQuestTriggerVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));

	SetRootComponent(Root);
	Box->SetupAttachment(Root);
}

void AQuestTriggerVolume::BeginPlay()
{
	Super::BeginPlay();
	Box->OnComponentBeginOverlap.AddDynamic(this, &AQuestTriggerVolume::OnOverlapBegin);
}

void AQuestTriggerVolume::OnOverlapBegin
(
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult
)
{
	Cast<APawn>(OtherActor);
	
	if (bDoOnce)
	{
		UQuestLibrary::GetQuestManager(GetWorld())->CompleteQuest(QuestId, CompleteWholeQuest);
		bDoOnce = false;
	}
	
}