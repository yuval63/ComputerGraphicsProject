// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Orton.generated.h"
//#include "Components/InputComponent.h"

//#include "Camera/CameraComponent.h"

# define NumOfPortals 54

UCLASS()
class ORTONS_CUBE_API AOrton : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AOrton();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	// Called every frame
	UFUNCTION(BlueprintCallable)
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
		bool getEndingMessage(int endingNum);

	UFUNCTION(BlueprintCallable)
		void setEndingMessage(int endingNum, bool newEndingMessagestate);



	UFUNCTION(BlueprintCallable)
	float getInteractDuration();

	void setInteractDuration(int newVal);

	UFUNCTION(BlueprintCallable)
	int getInteractWarning();
	void setInteractWarning(int newVal);

	UFUNCTION(BlueprintCallable)
		bool getGem(int gemNum);
	UFUNCTION(BlueprintCallable)
	void setGem(int gemNum,bool gotOrNot);

	UFUNCTION(BlueprintCallable)
	int getGemAmount();


	UFUNCTION(BlueprintCallable)
	int getCoins();
	UFUNCTION(BlueprintCallable)
	void setCoins(int newCoins);

	UFUNCTION(BlueprintCallable)
		void addCoin();

	UFUNCTION(BlueprintCallable)
	FVector getCheckPoint();
	void setCheckPoint(FVector newCheckPoint);

	UFUNCTION(BlueprintCallable)
	bool getEndingUnlocked(int num);

	UFUNCTION(BlueprintCallable)
	bool getRoomVisited(int ind);
	void setRoomVisited(int ind,bool visited);

	UFUNCTION(BlueprintCallable)
	int getTotalRoomsVisited();

	UFUNCTION(BlueprintCallable)
	int getCurrentRoomID();
	void setCurrentRoomID(int newRoomID);

	UFUNCTION(BlueprintCallable)
	bool getVisitedPortal(int ind);
	void setVsitedPortal(int ind, bool visited);

	UFUNCTION(BlueprintCallable)
	int getTotalPortalsVisited();

	UFUNCTION(BlueprintCallable)
		int getDeathsInRoom(int ind);
	void setDeathsInRoom(int ind, int amount);
	


	UFUNCTION(BlueprintCallable)
	void kill();

	UFUNCTION(BlueprintCallable)
	void checkEndings();


	UFUNCTION(BlueprintCallable)
	int getTotalDeaths();

	UFUNCTION(BlueprintCallable)
		int getCoinsInRoom(int roomID);

	UFUNCTION(BlueprintCallable)
		void setCoinsInRoom(int roomID,int newCoinInRooms);

	void MoveForward(float Value);
	void MoveRight(float Value);
	void Interact();

	FVector getSpeed();
	void setSpeed(FVector newSpeed);

	float getJumpVelocity();

	void setJumpVelocity(float newVelocity);

	void forceJump(float jumpHeight);

	void AddNewMovementInput(FVector newMovement);
	FVector getVelocty();
	FVector getLatestMovement();

	/**
	UFUNCTION(BlueprintCallable)
	bool getSlide();

	UFUNCTION(BlueprintCallable)
	void setSlide(bool doesSlide);
	
	UFUNCTION(BlueprintCallable)
	bool anotherGetterForSlide();
	**/
	//private:
protected:


	void giveEndingOne();

	FVector latestMovement = FVector(0.f, 0.f, 0.0f);
	FVector checkPoint = FVector(0.f, 0.f, 1130.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
		bool test = false;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
	bool shouldKill = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
		bool slides = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
	int coins = 0;
	int coinsInRoom[27] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0 };
	bool gems[7] = { false,false,false,false,false,false,false };

	bool endingUnlocked[7] = { false,false,false,false,false,false,false };

	bool showEndingMessage[7] = { false,false,false,false,false,false,false };

	bool roomsVisited[27] = { false,false,false,false,false,false,false ,false,false,false,false,false,false,false,false,false ,false,false ,false,false,false,false,false,false,false ,false,false };
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
	int currentRoom = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
	int totalDeaths = 0;

	int deathsInRoom[27] = { 0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0 };

	bool portalVisited[NumOfPortals] = { false }; // there's 1 middle with 6 portals, 8 3d corners woth 3 portals, 6 sides with 5 portals and 12 2d corners with 4 portals, but each portal has 2 sides so need to devide by 2  

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
		int interactDuration = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
		int showInteractWarning = 0;


	UAnimSequence* Anim;

	APlayerController* apc;

	//UPROPERTY(EditAnywhere)
	//	TSubclassOf<class UinteractWidget> playerHUDClass;

	//UPROPERTY()
	//	UinteractWidget* interactWidget;


	bool ShowInteract = false;
	//UUserWidget* interact;

	//TSubclassOf<class UUserWidget> interactWidgetClass;

	//void RotateRight(float Value);
	//void RotateUp(float Value);

/**
	UPROPERTY()
		UCameraComponent* cam;
		**/
		/**
		UFUNCTION()
			void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	**/
};
