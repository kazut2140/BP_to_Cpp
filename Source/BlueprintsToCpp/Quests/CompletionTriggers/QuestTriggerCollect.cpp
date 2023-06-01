// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestTriggerCollect.h"

// Sets default values
AQuestTriggerCollect::AQuestTriggerCollect()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	
	SetRootComponent(Root);
	Sphere->SetupAttachment(Root);
	/*Sphere->OnComponentBeginOverlap.AddDynamic(this, &AQuestTriggerCollect::OnOverlapBegin);*/
}

void AQuestTriggerCollect::NotifyQuestComplete()
{
	GetQuestManager()->CompleteQuest(QuestId, false);
}

//void AQuestTriggerCollect::OnOverlapBegin
//	(
//	UPrimitiveComponent* OverlappedComp,
//	AActor* OtherActor,
//	UPrimitiveComponent* OtherComp,
//	int32 OtherBodyIndex,
//	bool bFromSweep,
//	const FHitResult& SweepResult
//	)
//{
//
//
//}