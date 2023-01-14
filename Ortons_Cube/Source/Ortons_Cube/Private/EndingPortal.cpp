// Fill out your copyright notice in the Description page of Project Settings.


#include "EndingPortal.h"

// Sets default values
AEndingPortal::AEndingPortal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEndingPortal::BeginPlay()
{
	Super::BeginPlay();
	player = Cast<AOrton>(GetWorld()->GetFirstPlayerController()->GetPawn());
	unlockedPosition = GetActorLocation();

	SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z + 200000.0));
}

// Called every frame
void AEndingPortal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);



	if (player->getEndingUnlocked(id)) {
		if (unlocked != false) {
			SetActorLocation(unlockedPosition);
		}
		unlocked = true;
	}

	if (unlocked) {
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
				if (player->GetActorLocation().X - GetActorLocation().X > 0.0f) {
					player->setCheckPoint(FVector(GetActorLocation().X + 300.0f, GetActorLocation().Y, GetActorLocation().Z));
				}
				else {
					player->setCheckPoint(FVector(GetActorLocation().X - 300.0f, GetActorLocation().Y, GetActorLocation().Z));

				}
			}
			else {
				if (xDist < yDist) {
					if (player->GetActorLocation().Y - GetActorLocation().Y > 0.0f) {
						player->setCheckPoint(FVector(GetActorLocation().X, GetActorLocation().Y + 300.0f, GetActorLocation().Z));
					}
					else {
						player->setCheckPoint(FVector(GetActorLocation().X, GetActorLocation().Y - 300.0f, GetActorLocation().Z));

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
					teleport = true;
				}
			}

		}
	}
}

