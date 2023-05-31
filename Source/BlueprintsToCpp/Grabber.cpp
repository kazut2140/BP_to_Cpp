// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Quests/CompletionTriggers/QuestTriggerPickup.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// �f�o�b�O���O�̕\��
	//UE_LOG(LogTemp, Warning, TEXT("Grabber Constructor"));
}


void UGrabber::Grab()
{
	AActor* HitActor;
	UPrimitiveComponent* HitComponent;
	if (TraceForPhysicsBodies(HitActor, HitComponent))
	{
		HitComponent->SetSimulatePhysics(true);
		GetPhysicsComponent()->GrabComponentAtLocationWithRotation(
			HitComponent,
			NAME_None,
			HitComponent->GetCenterOfMass(),
			FRotator());
		NotifyQuestActor(HitActor);
	}
}

void UGrabber::Release()
{
	GetPhysicsComponent()->ReleaseComponent();
}

// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// �f�o�b�O���O�̕\��
	//UE_LOG(LogTemp, Warning, TEXT("Grabber BeginPlay"));
	
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	GetPhysicsComponent()->SetTargetLocationAndRotation(GetHoldLocation(), GetComponentRotation());

	// �f�o�b�O���O�̕\��
	//UE_LOG(LogTemp, Warning, TEXT("Grabber TickComponent"));
}

FVector UGrabber::GetMaxGrabLocation() const
{
	
	// GetWorldLocation
	return GetComponentLocation() + UKismetMathLibrary::GetForwardVector(GetComponentRotation()) * MaxGrabDistance;
}

FVector UGrabber::GetHoldLocation() const
{
	return GetComponentLocation() + GetComponentRotation().Vector() * HoldDistance;
}

UPhysicsHandleComponent* UGrabber::GetPhysicsComponent() const
{
	return GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
}

bool UGrabber::TraceForPhysicsBodies(AActor*& HitActor, UPrimitiveComponent*& HitComponent)
{
	TArray<TEnumAsByte<EObjectTypeQuery>> Types = { EObjectTypeQuery::ObjectTypeQuery4 };
	TArray<AActor*> Ignores;

	FHitResult HitResult;

	bool IsHit =  UKismetSystemLibrary::SphereTraceSingleForObjects(
		GetOwner(),
		GetComponentLocation(),
		GetMaxGrabLocation(),
		GrabRadius,
		Types,
		false,
		Ignores,
		EDrawDebugTrace::None,
		HitResult,
		true);

	HitActor = &*HitResult.Actor;
	HitComponent = &*HitResult.Component;


	return IsHit;
}

//void UGrabber::NotifyQuestActor(AActor* Actor)
//{
//	UActorComponent* ActorNewComp = Actor->GetComponentByClass(UQuestTriggerPickup::StaticClass());
//	if (IsValid(ActorNewComp))
//	{
//		UQuestTriggerPickup* QuestTriggerPickup = Cast<UQuestTriggerPickup>(ActorNewComp);
//		QuestTriggerPickup->Pickup();
//	}
//}

//bool UGrabber::TraceForPhysicsBodies_Implementation(AActor*& HitActor, UPrimitiveComponent*& HitComponent)
//{
//	return false;
//}

