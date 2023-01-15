// Fill out your copyright notice in the Description page of Project Settings.


#include "GreenPlatform.h"

#include "ColoredPlatform.h"


// Sets default values
AGreenPlatform::AGreenPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGreenPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGreenPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGreenPlatform::OnInteraction() {

	player->setJumpVelocity(1400.f);
	player->Jump();
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("join us"));

}


void AGreenPlatform::OnStopInteraction() {

	player->setJumpVelocity(700.f);

}
void AGreenPlatform::checkFunction() {
	player->setJumpVelocity(700.f);

}
