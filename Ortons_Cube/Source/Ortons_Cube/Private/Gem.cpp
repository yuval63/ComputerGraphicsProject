// Fill out your copyright notice in the Description page of Project Settings.


#include "Gem.h"
#include "Orton.h"

// Sets default values
AGem::AGem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (FVector3d::Dist(GetActorLocation(), GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation()) < 188) {
		player = Cast<AOrton>(GetWorld()->GetFirstPlayerController()->GetPawn());
		player->setGem(gemNumber, true);
		Destroy();

	}

}

