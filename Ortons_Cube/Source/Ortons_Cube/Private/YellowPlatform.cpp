// Fill out your copyright notice in the Description page of Project Settings.


#include "YellowPlatform.h"

// Sets default values
AYellowPlatform::AYellowPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AYellowPlatform::BeginPlay()
{
	Super::BeginPlay();

	direction.Normalize();
	originalLocation = GetActorLocation();
	startDelay *= 60;

}

// Called every frame
void AYellowPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//if (GEngine) {
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("LOCATION: %f,%f,%f"), GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z));
	//}

	if (startDelay > 0) {
		startDelay--;
	}
	else {

		if (FVector3d::Dist(originalLocation, GetActorLocation()) > range) {
			direction.X = -1.0f * direction.X;
			direction.Y = -1.0f * direction.Y;
			direction.Z = -1.0f * direction.Z;

		}
		FVector3d newLocation = FVector3d(0.0f);

		newLocation.X = GetActorLocation().X + (direction.X * velocity);
		newLocation.Y = GetActorLocation().Y + (direction.Y * velocity);
		newLocation.Z = GetActorLocation().Z + (direction.Z * velocity);


		SetActorLocation(newLocation);
	}
}
// Only for killer pushers
void AYellowPlatform::OnInteraction() {

	player->kill();
}