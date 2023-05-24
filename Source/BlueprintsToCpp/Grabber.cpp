// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// �f�o�b�O���O�̕\��
	UE_LOG(LogTemp, Warning, TEXT("Grabber Constructor"));
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// �f�o�b�O���O�̕\��
	UE_LOG(LogTemp, Warning, TEXT("Grabber BeginPlay"));
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// �f�o�b�O���O�̕\��
	UE_LOG(LogTemp, Warning, TEXT("Grabber TickComponent"));
}

FVector UGrabber::GetMaxGrabLocation() const
{
	
	// GetWorldLocation
	return GetComponentLocation() + UKismetMathLibrary::GetForwardVector(GetComponentRotation()) * MaxGrabDistance;
}