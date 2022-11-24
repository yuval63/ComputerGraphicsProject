// Fill out your copyright notice in the Description page of Project Settings.

#include "Orton.h"
#include "ColoredPlatform.h"

// Sets default values
AColoredPlatform::AColoredPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AColoredPlatform::BeginPlay()
{
	Super::BeginPlay();
	player = Cast<AOrton>(GetWorld()->GetFirstPlayerController()->GetPawn());
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Here!!"));

}

// Called every frame
void AColoredPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AColoredPlatform::OnInteraction() {}