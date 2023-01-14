// Fill out your copyright notice in the Description page of Project Settings.


#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

#include "OrtonEnding.h"
// Sets default values
AOrtonEnding::AOrtonEnding()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AOrtonEnding::BeginPlay()
{
	Super::BeginPlay();


	//get player controller at index 0
	controller = UGameplayStatics::GetPlayerController(this->GetWorld(), 0);





	// Red Ending Text
	text[0][0] = "After falling down so many times, and somehow returning... Orton managed to confuse the security door, allowing him to enter.";
	text[0][1] = "Inside, Orton found a big,red,glowing button, next to a big screen. The text on the screen explained that the cube is in a defensive mode of some sort";
	text[0][2] = "Orton decided to push the big,red,glowing button hoping to stop the cube's defensive mode, with a press of a button - Orton turned it off";
	text[0][3] = "Now with the cube defenses turned off, Orton was finally free to do as he pleased in the safe cube, hoping to understand more about where he is and why";

	// Orange Ending Text
	text[1][0] = "After so much time inside the cube, the portal just... opened. Orton not sure why or how but he decided to get inside";
	text[1][1] = "In this room, Orton found something he never thought he would find. A beautiful mustache near a clear mirror.";
	text[1][2] = "Orton decided to put the Mustache on as his species do not grow hair, he put it on and went to look in the mirror";
	text[1][3] = "In the mirror he saw a beautiful face, this may not help him deal with any obstacle in his journey, but at least he would look good while running and jumping for his life";

	// Yellow Ending Text
	text[2][0] = "After collecting all 300 coins (which were surprisingly light), the yellow portal opened - almost like it had a connection with the coins. Orton got inside";
	text[2][1] = "In the room, Orton found a chest full of gold coins like the one he found around the ship. This made Orton think - may the coins he found scattered around from this very room?";
	text[2][2] = "Orton decided to take the gold and use it, however without someone to sell it to - the gold worth noting... or does it?";
	text[2][3] = "Well, it really doesn't worth anything - at least for Orton. So he decided to build a cool statue with it.";

	// Green Ending Text
	text[3][0] = "After visiting every single room on that cube. This portal reacted, as if to guide Orton, Orton decided to get in after his long journey";
	text[3][1] = "In the dark room, Orton saw noting. He searched the room until he found a light switch. He was very confused as this was the only room so far he saw that was completely dark";
	text[3][2] = "After flipping the light switch, he saw a bed with a lady lying inside. The lady got up to Orton and asked him, if he slept walk again? It seems she cared a lot about him";
	text[3][3] = "Could this lady be his wife? Could it be this whole time the cube Orton was inside... was his own...? If so, why didn't he remembered any of this?";

	// Blue Ending Text
	text[4][0] = "After collecting all of the hidden gems around the cube. Orton hopes the portal would lead it to an explanation about the gems";
	text[4][1] = "Before him he saw 7 pedestals, with something writen on the middle one, explaning that the gems are actually the power source of the cube.";
	text[4][2] = "However, these pedestals are able to power the cube just as good as the other temples Orton found along its way.";
	text[4][3] = "Should Orton let the cube turn off and save itself from the danger of the cube? Or should it return the gems, in order to avoid the risks that come without the power...";

	// Purple Ending Text
	text[5][0] = "After Orton passed through every single portal, hoping to find one that would lead it outside of the cube, the cube itself opened a portal for Orton to try";
	text[5][1] = "Orton was confused at first but after entering the portal, Orton found himself in a room with an escape pod. He quickly took off his hat in order to wear his helmet";
	text[5][2] = "Orton entered the ship and launched himself to space, he was releaved finally escaping the cube but also... confused. What would he do now? Where would he land?";
	text[5][3] = "After a while traveling through space, Orton found himself on an empty planet. No one around. What would he do now? Is it really better than staying on the cube?";

	// White Ending Text
	text[6][0] = "After traveling through the cube, doing everything he could. Orton wasn't happy with any of the options he had. He wanted something... special";
	text[6][1] = "Why picking only one room, doing one task when you can do it all? Suddenly, a new portal opened. It wasn't like the others and Orton knew it";
	text[6][2] = "Orton decided to get into the portal. He just knew somehow that this would be the one true portal... The one that would give him everything he wanted";
	text[6][3] = "This portal allowed Orton to see the truth. Orton finally achieved the ULTIMATE ENDING!";


}

// Called every frame
void AOrtonEnding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Set control rotation of controller
			//Get this actors rotation
	controller->SetControlRotation(FRotator(0.0f,90.0f,0.0f));
}

// Called to bind functionality to input
void AOrtonEnding::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)

{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//	if (GEngine)
	//		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));

		PlayerInputComponent->BindAxis(TEXT("Move Forward / Backward"), this, &AOrtonEnding::Pressed);
		PlayerInputComponent->BindAxis(TEXT("Move Right / Left"), this, &AOrtonEnding::Pressed);
}

void AOrtonEnding::Pressed(float Value) {
	if (currentPageNum + Value > 0 && currentPageNum + Value < 4) {
		currentPageNum += Value;
	}
}





int AOrtonEnding::getCurrentEndingNum() {
	return currentEndingNum;
}

void AOrtonEnding::setCurrentEndingNum(int newPageNum) {
	currentEndingNum = newPageNum;
}


int AOrtonEnding::getCurrentPageNum() {
	return currentPageNum;
}

void AOrtonEnding::setCurrentPageNum(int newEndingNum) {
	currentPageNum = newEndingNum;
}



FString AOrtonEnding::getCurrentText1() {
	return text[currentEndingNum][currentPageNum];
}

void AOrtonEnding::setCurrentText1(FString newText) {
	text[currentEndingNum][currentPageNum] = newText;
}


FString AOrtonEnding::getCurrentText2(int currentPage) {
	return text[currentEndingNum][currentPage];
}

void AOrtonEnding::setCurrentText2(int currentPage, FString newText) {
	text[currentEndingNum][currentPage] = newText;

}

FString AOrtonEnding::getCurrentText3(int endingNum, int pageNum) {
	return text[endingNum][pageNum];
}

void AOrtonEnding::setCurrentText3(int endingNum, int pageNum, FString newText) {
	text[endingNum][pageNum] = newText;
}

