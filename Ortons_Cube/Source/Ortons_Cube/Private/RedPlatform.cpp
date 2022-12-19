// Fill out your copyright notice in the Description page of Project Settings.


#include "RedPlatform.h"
#include "DrawDebugHelpers.h"
#include "Components/BoxComponent.h"
// Sets default values
ARedPlatform::ARedPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void ARedPlatform::BeginPlay()
{
	Super::BeginPlay();
	SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
	originalRotation = GetActorRotation();
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("rotationnnn %f , %f, %f"), GetActorRotation().Roll, GetActorRotation().Yaw, GetActorRotation().Pitch));


	startDelay *= 60;
}

// Called every frame
void ARedPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

			//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("what is count %f"),count));


	if (startDelay > 0) {
		startDelay--;
	}
	else {

		float min = 0.0f, max = 20.0f;
		int difference = max - min;
		if (count < max) {
			//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Black, TEXT("Cold"));
			SetActorRotation(FRotator(originalRotation.Pitch, originalRotation.Yaw, originalRotation.Roll));

		}
		else {
			min = max;
			max = 30.f;
			if (count >= min && count < max) {
				difference = max - min;
				//stage = 1; // warming up
				//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Orange, TEXT("Worming up"));
				if (difference != 0.0f) {
					switch (mode) {
					case 0:
						if (positiveSpin) {
							SetActorRotation(FRotator(originalRotation.Pitch + 180.0f * ((count - min) / difference), originalRotation.Yaw, originalRotation.Roll));
						}
						else {
							SetActorRotation(FRotator(originalRotation.Pitch - 180.0f * ((count - min) / difference), originalRotation.Yaw, originalRotation.Roll));
						}
						break;
					case 1:
						if (positiveSpin) {
							SetActorRotation(FRotator(originalRotation.Pitch, originalRotation.Yaw + 180.0f * ((count - min) / difference), originalRotation.Roll));
						}
						else {
							SetActorRotation(FRotator(originalRotation.Pitch, originalRotation.Yaw - 180.0f * ((count - min) / difference), originalRotation.Roll));
						}
						break;
					case 2:
						if (positiveSpin) {
							SetActorRotation(FRotator(originalRotation.Pitch, originalRotation.Yaw, originalRotation.Roll + 180.0f * ((count - min) / difference)));
						}
						else {
							SetActorRotation(FRotator(originalRotation.Pitch, originalRotation.Yaw, originalRotation.Roll - 180.0f * ((count - min) / difference)));
						}
						break;
					}
				}
			}
			else {
				min = max;
				max = 50.f;
				difference = max - min;
				if (count >= min && count < max) {
					//stage = 2; // hot (deadly...)
					//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("HOT"));
					switch (mode) {
					case 0:
						if (positiveSpin) {
							SetActorRotation(FRotator(originalRotation.Pitch + 180.0f, originalRotation.Yaw, originalRotation.Roll));
						}
						else {
							SetActorRotation(FRotator(originalRotation.Pitch - 180.0f, originalRotation.Yaw, originalRotation.Roll));
						}
						break;
					case 1:
						if (positiveSpin) {
							SetActorRotation(FRotator(originalRotation.Pitch, originalRotation.Yaw + 180.0f, originalRotation.Roll));
						}
						else {
							SetActorRotation(FRotator(originalRotation.Pitch, originalRotation.Yaw - 180.0f, originalRotation.Roll));
						}
						break;
					case 2:
						if (positiveSpin) {
							SetActorRotation(FRotator(originalRotation.Pitch, originalRotation.Yaw, originalRotation.Roll + 180.0f));
						}
						else {
							SetActorRotation(FRotator(originalRotation.Pitch, originalRotation.Yaw, originalRotation.Roll - 180.0f));
						}
						break;
					}

				}
				else {
					min = max;
					max = 60.0f;
					difference = max - min;
					if (count >= min) {
						//	stage = 3; // cooling down
						//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Cooling Down"));
						if (difference != 0.0f) {
							switch (mode) {
							case 0:
								if (positiveSpin) {
									SetActorRotation(FRotator(originalRotation.Pitch + (180.f + (180.0f * ((count - min) / difference))), originalRotation.Yaw, originalRotation.Roll));
								}
								else {
									SetActorRotation(FRotator(originalRotation.Pitch - (180.f + (180.0f * ((count - min) / difference))), originalRotation.Yaw, originalRotation.Roll));
								}
								break;
							case 1:
								if (positiveSpin) {
									SetActorRotation(FRotator(originalRotation.Pitch, originalRotation.Yaw + (180.f + (180.0f * ((count - min) / difference))), originalRotation.Roll));
								}
								else {
									SetActorRotation(FRotator(originalRotation.Pitch, originalRotation.Yaw - (180.f + (180.0f * ((count - min) / difference))), originalRotation.Roll));
								}
								break;
							case 2:
								if (positiveSpin) {
									SetActorRotation(FRotator(originalRotation.Pitch, originalRotation.Yaw, originalRotation.Roll + (180.f + (180.0f * ((count - min) / difference)))));
								}
								else {
									SetActorRotation(FRotator(originalRotation.Pitch, originalRotation.Yaw, originalRotation.Roll - (180.f + (180.0f * ((count - min) / difference)))));
								}
								break;
							}
						}

					}
				}
			}
		}


		count += (heatSpeed / 60.0f);

		if (count > 60) {
			count = 0;
		}
	}
}
	

void ARedPlatform::OnInteraction() {

		player->kill();
}
