// Fill out your copyright notice in the Description page of Project Settings.


#include "OrangePlatform.h"

// Sets default values
AOrangePlatform::AOrangePlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AOrangePlatform::BeginPlay()
{
	Super::BeginPlay();
	
	originalLocation = GetActorLocation();
}

// Called every frame
void AOrangePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (drops) {
		/**
		if (GetActorLocation().Z < -57000) {
			drops = false;
			lifts = true;

		}
		//else {
		**/
			SetActorLocation(GetActorLocation() - FVector3d(0.0f, 0.0f, dropSpeed));

		//}

	}
	else {
		if (lifts) {
			/**
			if (FVector3d::Dist(originalLocation, GetActorLocation() + FVector3d(0.0f, 0.0f, liftSpeed)) < liftSpeed) {
				SetActorLocation(originalLocation);
				lifts = false;

			}
			else {
			**/
			if ((GetActorLocation() + FVector3d(0.0f, 0.0f, liftSpeed)).Z < originalLocation.Z) {
				SetActorLocation(GetActorLocation() + FVector3d(0.0f, 0.0f, liftSpeed));
			}
			else {
				SetActorLocation(originalLocation);
			}

			//}
		}
	}
}

