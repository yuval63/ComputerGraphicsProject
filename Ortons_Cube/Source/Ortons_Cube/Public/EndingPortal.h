// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Orton.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EndingPortal.generated.h"

UCLASS()
class ORTONS_CUBE_API AEndingPortal : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEndingPortal();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
		int id = 0; // 7 ids, 1 for each ending. 0 = red, 1 = orange, 2 = yellow, 3 = green , 4 = blue, 5 = purple, 6  = white
	bool unlocked = false; // Only if the player completed the fitting ending (for id = ending num, unlocked only if ending[ending num] = true)

	AOrton* player;

	FVector unlockedPosition = FVector(0.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
	bool teleport = false;
};
