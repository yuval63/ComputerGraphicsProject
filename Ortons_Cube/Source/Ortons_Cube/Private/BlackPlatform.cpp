// Fill out your copyright notice in the Description page of Project Settings.

#include "BlackPlatform.h"


#include "ColoredPlatform.h"


// Sets default values
ABlackPlatform::ABlackPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABlackPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABlackPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABlackPlatform::OnInteraction() {
	player->kill();
}
