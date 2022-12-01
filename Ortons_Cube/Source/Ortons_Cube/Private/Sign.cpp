// Fill out your copyright notice in the Description page of Project Settings.


#include "Sign.h"

// Sets default values
ASign::ASign()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASign::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASign::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (FVector3d::Dist(GetActorLocation(), GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation()) < 400) {

		player = Cast<AOrton>(GetWorld()->GetFirstPlayerController()->GetPawn());


		player->setInteractWarning(10);

		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("interact warning is "));


		if (player->getInteractDuration() > 0) {
			player->setInteractDuration(0.f);

			player->setSpeed(FVector(0.f, 0.f, 0.f));
			pressed = true;
			
		}
	}
}


bool ASign::getPressed() {
	return pressed;
}

void ASign::setPressed(bool newPressed) {
	pressed = newPressed;
}

FString ASign::getPageText(int pageNum) {
	switch (pageNum) {
	case 0:
		return page1Text;
		break;
	case 1:
		return page2Text;

		break;
	default:
		return page3Text;
		break;

	}
}

FString ASign::getPageTitle(int pageNum) {
	switch (pageNum) {
	case 0:
		return page1Title;
		break;
	case 1:
		return page2Title;

		break;
	default:
		return page3Title;
		break;

	}

}


