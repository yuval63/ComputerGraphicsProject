// Fill out your copyright notice in the Description page of Project Settings.

#include "ColoredPlatform.h"

#include "BluePlatform.h"

// Sets default values
ABluePlatform::ABluePlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABluePlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABluePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABluePlatform::OnInteraction() {
 
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Here?"));

	player->SetActorRotation(GetActorRotation());
	player->MoveForward(1.f);
}
