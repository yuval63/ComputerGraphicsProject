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
		if (portalID != -1) {
			unlocked = true;
		}
		else {
			if (player->getEndingUnlocked(portalID)) {
				unlocked = true;
			}
		}
	}


	if (FVector3d::Dist(GetActorLocation(), GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation()) < 700) {

		player = Cast<AOrton>(GetWorld()->GetFirstPlayerController()->GetPawn());


		player->setInteractWarning(10);

		float xDist = GetActorLocation().X - player->GetActorLocation().X;
		if (xDist < 0.0f) {
			xDist *= -1.0f;
		}
		float yDist = GetActorLocation().Y - player->GetActorLocation().Y;
		if (yDist < 0.0f) {
			yDist *= -1.0f;
		}

		if (xDist > yDist) {
			if ( player->GetActorLocation().X - GetActorLocation().X > 0.0f) {
				player->setCheckPoint(FVector(GetActorLocation().X + 300.0f, GetActorLocation().Y, GetActorLocation().Z));
			}
			else {
				player->setCheckPoint(FVector(GetActorLocation().X - 300.0f, GetActorLocation().Y, GetActorLocation().Z));

			}
		}
		else {
			if (xDist < yDist) {
				if (player->GetActorLocation().Y - GetActorLocation().Y > 0.0f) {
					player->setCheckPoint(FVector(GetActorLocation().X , GetActorLocation().Y + 300.0f, GetActorLocation().Z));
				}
				else {
					player->setCheckPoint(FVector(GetActorLocation().X , GetActorLocation().Y - 300.0f, GetActorLocation().Z));

				}
			}
			else {
				if (player->GetActorLocation().X - GetActorLocation().X > 0.0f) {
					if (player->GetActorLocation().Y - GetActorLocation().Y > 0.0f) {
						player->setCheckPoint(FVector(GetActorLocation().X + 300.0f, GetActorLocation().Y + 300.0f, GetActorLocation().Z));
					}
					else {
						player->setCheckPoint(FVector(GetActorLocation().X + 300.0f, GetActorLocation().Y - 300.0f, GetActorLocation().Z));

					}
				}
				else {
					if (player->GetActorLocation().Y - GetActorLocation().Y > 0.0f) {
						player->setCheckPoint(FVector(GetActorLocation().X - 300.0f, GetActorLocation().Y + 300.0f, GetActorLocation().Z));
					}
					else {
						player->setCheckPoint(FVector(GetActorLocation().X - 300.0f, GetActorLocation().Y - 300.0f, GetActorLocation().Z));

					}
				}
			}
		}


		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("interact warning is "));

		if (unlocked) {
			if (player->getInteractDuration() > 0) {
				player->setInteractDuration(0.f);
				GetWorld()->GetFirstPlayerController()->GetPawn()->SetActorLocation(to);
				player->setCheckPoint(to);
				player->setCurrentRoomID(toRoomID);
				player->setSpeed(FVector(0.f,0.f,0.f));
				player->setVsitedPortal(portalID, true);


			//	if (GEngine) {
			//		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("LOCATION: %f,%f,%f"), to.X, to.Y, to.Z));
				//}
			}
		}
	}




}

