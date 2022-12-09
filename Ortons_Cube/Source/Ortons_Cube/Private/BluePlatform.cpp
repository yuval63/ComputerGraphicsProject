// Fill out your copyright notice in the Description page of Project Settings.

#include "BluePlatform.h"


#include "ColoredPlatform.h"


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

	if (onPlatform) {
		OnInteraction();
	}
}

void ABluePlatform::OnInteraction() {

	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Here?!?!"));
	//player->GetActorRotation().Vector().
	//player->GetActorRotation().Yaw

	float x = player->getVelocty().X;
	float y = player->getVelocty().Y;
	float absX = x < 0.0 ? -x : x;
	float absY = y < 0.0 ? -y : y;

	FVector speedVec = FVector(0.0f, 0.0f, 0.0f);
	if (y == 0.0f && x == 0.0f) {
		x = 1.0f;
	}

	if (absX >= absY) {	// The player should go forward or backward

		if (x > 0.0f) {
			speedVec = FVector(speed, 0.0f, 0.f);


		}
		else {
			if (x < 0.0f) {
				speedVec = FVector(-speed, 0.0f, 0.f);
			}


		}
	}
	else { // The player should go left or right
		if (absY >= absX) {
			if (y > 0.0f) {
				speedVec = FVector(0.0f, speed, 0.f);

			}
			else {
				if (y < 0.0f) {
					speedVec = FVector(0.0f, -speed, 0.f);
				}
			}
		}
	}

	if (player->getVelocty().X != 0.0f && player->getVelocty().Y != 0.0f) {
		player->AddNewMovementInput(speedVec);
		if (player->getVelocty().X != 0.0f && player->getVelocty().Y != 0.0f) {
			player->AddNewMovementInput(speedVec);
			if (player->getVelocty().X != 0.0f && player->getVelocty().Y != 0.0f) {
				player->AddNewMovementInput(speedVec);
			}
		}
	}

	/**
	*
	if (currentRotation >= -135 && currentRotation <= -45) {
		//player->GetActorForwardVector() = FVector(1.0f, 0.0f, 0.0f);
		player->AddNewMovementInput(FVector(0.0f, -speed, 0.f));
		player->AddNewMovementInput(FVector(0.0f, -speed, 0.f));
		player->AddNewMovementInput(FVector(0.0f, -speed, 0.f));

		//player->SetActorLocation(FVector(player->GetActorLocation().X , player->GetActorLocation().Y - speed, player->GetActorLocation().Z));
	//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("one"));

		//GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation()
	}
	else {
		if (currentRotation >= -45 && currentRotation <= 45) {

			//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Purple, TEXT("two"));
			//player->SetActorLocation(FVector(player->GetActorLocation().X + speed , player->GetActorLocation().Y , player->GetActorLocation().Z));
			player->AddNewMovementInput(FVector(speed, 0.0f, 0.f));
			player->AddNewMovementInput(FVector(speed, 0.0f, 0.f));
			player->AddNewMovementInput(FVector(speed, 0.0f, 0.f));

		}
		else {
			if (currentRotation >= 45 && currentRotation <= 135) {

				//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("three"));
				//player->SetActorLocation(FVector(player->GetActorLocation().X , player->GetActorLocation().Y + speed, player->GetActorLocation().Z));
				player->AddNewMovementInput(FVector(0.0f, speed, 0.f));
				player->AddNewMovementInput(FVector(0.0f, speed, 0.f));
				player->AddNewMovementInput(FVector(0.0f, speed, 0.f));


			}
			else {
				if (currentRotation >= 135 || currentRotation <= -135) {

					//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("four"));
					//player->SetActorLocation(FVector(player->GetActorLocation().X - speed, player->GetActorLocation().Y, player->GetActorLocation().Z));
					player->AddNewMovementInput(FVector(-speed, 0.f, 0.f));
					player->AddNewMovementInput(FVector(-speed, 0.f, 0.f));
					player->AddNewMovementInput(FVector(-speed, 0.f, 0.f));

				}
			}
		}
	}
	**/

}
