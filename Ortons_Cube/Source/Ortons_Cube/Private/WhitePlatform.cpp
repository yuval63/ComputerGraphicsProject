// Fill out your copyright notice in the Description page of Project Settings.


#include "WhitePlatform.h"

// Sets default values
AWhitePlatform::AWhitePlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWhitePlatform::BeginPlay()
{
	Super::BeginPlay();
	flightDuration = maxFlightDuration;
}

// Called every frame
void AWhitePlatform::Tick(float DeltaTime)
{


	Super::Tick(DeltaTime);
	if (flightDuration > 0.0f) {
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("fly: %f"), flightDuration));
		flightDuration-= 0.1;
		player->AddNewMovementInput(FVector(0.0f, 0.f, flightSpeed));
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("fly: %f"), flightDuration));
	}
}

void AWhitePlatform::OnInteraction() {
	FVector currentActorLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	flightDuration = maxFlightDuration;
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("should in theory go %f"), flightSpeed));

	GetWorld()->GetFirstPlayerController()->GetPawn()->SetActorLocation(FVector(currentActorLocation.X, currentActorLocation.Y, currentActorLocation.Z + flightSpeed));
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("fly: %f"), flightDuration));


}