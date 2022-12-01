// Fill out your copyright notice in the Description page of Project Settings.


#include "Orton.h"
//#include "MyGameInstance.h"
//#include "Blueprint/UserWidget.h"
//#include "interactWidget.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AOrton::AOrton()
{



	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	for (int i = 0; i < NumOfPortals; i++) {
		portalVisited[i] = false;
	}

}

// Called when the game starts or when spawned
void AOrton::BeginPlay()
{
	Super::BeginPlay();
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->MaxWalkSpeed = 1200.f;
	GetCharacterMovement()->AirControl = 1.f;
 

	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle,this,&AOrton::giveEndingOne, 1.f , false, 3600.0f); // 60 sec * 30 min = 1,800

	roomsVisited[0] = true;

	/**
	interact = nullptr;
	static ConstructorHelpers::FClassFinder<UUserWidget> interactionWidget(TEXT(""));

	if (!ensure(interactionWidget.Class != nullptr)) return;

	interactWidgetClass = interactionWidget.Class;

	interact = CreateWidget<UUserWidget>(GetWorld()->GetGameInstance(), interactWidgetClass);
	**/
}

void AOrton::EndPlay(const EEndPlayReason::Type EndPlayReason) {
/**
	if (interact != nullptr) {
		interact = nullptr;
	}
	**/
	Super::EndPlay(EndPlayReason);

}


// Called every frame
void AOrton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);



	if (shouldKill) {
		shouldKill = false;
		kill();
	}




	// Works! printing the character current location
	/**
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("LOCATION: %f,%f,%f"), GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation().X, GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation().Y, GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation().Z));
	}
	**/
	if (interactDuration > 0) {
		interactDuration--;

	}


	/**
	if (showInteractWarning > 0) {

		showInteractWarning--;

		if (showInteractWarning > 0 && interactDuration == 0 && interact != nullptr && ShowInteract == false) {

			interact->AddToViewport();
			ShowInteract = true;
		}
		else {
			interact->AddToViewport();
			ShowInteract = false;
		}
		**/
		//MyGameInstance.
		/**
		if (showInteractWarning > 0 && interact == 0 && interactWidget == nullptr) {

			apc = GetWorld()->GetFirstPlayerController();
			check(apc);


			interactWidget = CreateWidget<UinteractWidget>(apc, playerHUDClass);
			check(interactWidget);
			interactWidget->AddToPlayerScreen();
		}
		else {
			if (interactWidget != nullptr) {
				interactWidget->RemoveFromParent();
				interactWidget = nullptr;
			}
		}
		**/
	//}
	if (showInteractWarning > 0) {
		showInteractWarning -- ;
	}
	if (showInteractWarning < 0) {
		showInteractWarning = 0;
	}
	if (interactDuration < 0) {
		interactDuration = 0;
	}



}




/**
void AOrton::RotateRight(float Value) {

	AddActorLocalRotation(FRotator(0, Value, 0));
}
**/

// Called to bind functionality to input
void AOrton::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//	if (GEngine)
	//		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
	PlayerInputComponent->BindAxis(TEXT("Move Forward / Backward"), this, &AOrton::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("Move Right / Left"), this, &AOrton::MoveRight);

		PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &AOrton::Jump);
	
	PlayerInputComponent->BindAction(TEXT("Interact"), IE_Pressed, this, &AOrton::Interact);



	PlayerInputComponent->BindAxis(TEXT("Turn Right / Left Gamepad"), this, &AOrton::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("Turn Right / Left Mouse"), this, &AOrton::AddControllerYawInput);


	PlayerInputComponent->BindAxis(TEXT("Look Up / Down Gamepad"), this, &AOrton::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("Look Up / Down Mouse"), this, &AOrton::AddControllerPitchInput);

	//PlayerInputComponent->BindAxis(TEXT("Turn Right / Left Gamepad"), this, &AOrton::RotateRight);
	//PlayerInputComponent->BindAxis(TEXT("Turn Right / Left Mouse"), this, &AOrton::RotateRight);


}


void AOrton::MoveForward(float Value) {
	AddMovementInput(GetActorForwardVector() * Value);

	//static ConstructorHelpers::FObjectFinder<UAnimSequence> anim(TEXT("AnimSequence'/Game/Mannequin/Animations/ThirdPersonJump_Start.ThirdPersonJump_Start'"));
	//Anim = anim.Object;
}


void AOrton::MoveRight(float Value) {
	AddMovementInput(GetActorRightVector() * Value);

}

void AOrton::AddNewMovementInput(FVector newMovement) {
	AddMovementInput(newMovement);
}



void AOrton::Interact() {
	interactDuration = 5;
}


float AOrton::getInteractDuration() {
	return interactDuration;
}

void AOrton::setInteractDuration(int newVal) {
	interactDuration = newVal;
}

int AOrton::getInteractWarning() {
	return showInteractWarning;
}
void AOrton::setInteractWarning(int newVal) {
	showInteractWarning = newVal;
}

int AOrton::getGem(int gemNum) {
	return gems[gemNum];
}
void AOrton::setGem(int gemNum, bool gotOrNot) {
	gems[gemNum] = gotOrNot;
	if (getGemAmount() == 7) {
		endingUnlocked[4] = true;
		checkEndings();
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Ending 4"));
	}
}


int AOrton::getCoins() {
	return coins;
}
void AOrton::setCoins(int newCoins) {
	coins = newCoins;
}
void AOrton::addCoin() {
	coins++;
	if (coins == 300) {
		endingUnlocked[2] = true;
		checkEndings();
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Ending 2"));

	}
}

FVector AOrton::getCheckPoint() {
	return checkPoint;
}
void AOrton::setCheckPoint(FVector newCheckPoint) {
	checkPoint = newCheckPoint;
}

int AOrton::getGemAmount() {
	int count = 0;

	
	for (int i = 0; i < (sizeof(gems) / sizeof(*gems)); i++) {
		if (gems[i] == true) {
			count++;
		}
	}
	return count;
}



int AOrton::getCurrentRoomID() {
	return currentRoom;
}
void AOrton::setCurrentRoomID(int newRoomID) {
	roomsVisited[currentRoom] = true;
	currentRoom = newRoomID;
	roomsVisited[currentRoom] = true;

	if (endingUnlocked[3] == false) {
		bool visitedAllrooms = true;
		for (int i = 0; i < 27; i++) {
			if (roomsVisited[i] == false) {
				visitedAllrooms = false;
			}
		}
		if (visitedAllrooms == true) {
			endingUnlocked[3] = true;
			checkEndings();
		}
	}
}

bool AOrton::getVisitedPortal(int ind) {
	return portalVisited[ind];
}
void AOrton::setVsitedPortal(int ind, bool visited) {
	portalVisited[ind] = visited;

	if (endingUnlocked[5] == false) {
		bool deserveEndingFive = true;

		for (int i = 0; i < NumOfPortals; i++) {
			if (portalVisited[i] == false) {
				deserveEndingFive = false;
			}
		}
		if (deserveEndingFive == true) {
			endingUnlocked[5] = true;
			checkEndings();
		}
	}
}


int AOrton::getTotalPortalsVisited() {

	int count = 0;
	for (int i = 0; i < NumOfPortals; i++) {
		if (portalVisited[i] == true) {
			count++;
		}
	}
	return count;
}



void AOrton::kill() {



	if (totalDeaths < 99999) {
		totalDeaths++;
	}


	GetWorld()->GetFirstPlayerController()->GetPawn()->SetActorLocation(checkPoint);
	setSpeed(FVector(0.f, 0.f, 0.f));
	
	if (deathsInRoom[currentRoom] < 99999) {
		deathsInRoom[currentRoom]++;
	}

	/**
	if (endingUnlocked[0] == false) {
		//if (currentRoom < 5) {
		//}

		bool diedEnough = true;
		for (int i = 0; i < 27; i++) {
			if (deathsInRoom[i] < 5) {
				diedEnough = false;
			}
		}
		if (diedEnough == true) {
		**/
	if (totalDeaths >= 100) {
			endingUnlocked[0] = true;
			checkEndings();
		}


}

int AOrton::getEndingUnlocked(int num) {
	return endingUnlocked[num];
}

bool AOrton::getRoomVisited(int ind) {
	if (ind >= 0 && ind < 27) {
		return roomsVisited[ind];
	}
	else {
		return false;
	}
}
void AOrton::setRoomVisited(int ind, bool visited) {
	roomsVisited[ind] = visited;
}

int AOrton::getTotalRoomsVisited() {
	int count = 0;
	for (int i = 0; i < 27; i++) {
		if (roomsVisited[i] == true) {
			count++;
		}
	}
	return count;
}


int AOrton::getTotalDeaths() {
	return totalDeaths;
}


int AOrton::getDeathsInRoom(int ind) {
	if (ind >= 0 && ind < 27) {
		return deathsInRoom[ind];
	}
	else {
		return 0;
	}
}
void AOrton::setDeathsInRoom(int ind, int amount) {
	if (ind >= 0 && ind < 27) {
		deathsInRoom[ind] = amount;
	}
}


void AOrton::checkEndings() {
	bool secretEndingUnlocked = true;
	for (int i = 0; i < 6; i++) {
		if (endingUnlocked[i] == false) {
			secretEndingUnlocked = false;
		}
	}

	if (secretEndingUnlocked == true) {
		endingUnlocked[6] = true;
	}
}



void AOrton::giveEndingOne() {

	/**
	if (GEngine) {
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Ending One")));
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Ending One"));

	}
	endingUnlocked[1] = true;
	**/
	checkEndings();
}

FVector AOrton::getSpeed() {
	return GetCharacterMovement()->Velocity;
}
void AOrton::setSpeed(FVector newSpeed) {
	GetCharacterMovement()->Velocity = newSpeed;
}
float AOrton::getJumpVelocity() {
	return GetCharacterMovement()->JumpZVelocity;
}

void AOrton::setJumpVelocity(float newVelocity) {
	GetCharacterMovement()->JumpZVelocity = newVelocity;
}

void AOrton::forceJump(float jumpHeight) {
	GetCharacterMovement()->Velocity.Z = jumpHeight;
}


/**
void AOrton::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

{
	UE_LOG(LogTemp, Warning, TEXT("Activated"));

}
**/