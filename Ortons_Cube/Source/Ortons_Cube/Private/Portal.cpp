// Fill out your copyright notice in the Description page of Project Settings.


#include "Portal.h"
#include "Orton.h"

// Sets default values
APortal::APortal()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APortal::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APortal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	//Check if should be unlocked.
	player = Cast<AOrton>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (unlocked == false) {
		if (portalKind == -1) {
			unlocked = true;
		}
		else {
			if (player->getEndingUnlocked(portalKind)) {
				unlocked = true;
			}
		}
	}


	if (FVector3d::Dist(GetActorLocation(), GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation()) < 700) {

		player = Cast<AOrton>(GetWorld()->GetFirstPlayerController()->GetPawn());


		player->setInteractWarning(10);

		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("interact warning is "));

		if (unlocked) {
			if (player->getInteractDuration() > 0) {
				player->setInteractDuration(0.f);
				GetWorld()->GetFirstPlayerController()->GetPawn()->SetActorLocation(to);
				player->setCheckPoint(to);
				player->setCurrentRoomID(toRoomID);
				player->setSpeed(FVector(0.f,0.f,0.f));

				if (GEngine) {
					GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("LOCATION: %f,%f,%f"), to.X, to.Y, to.Z));
				}
			}
		}
	}




}

