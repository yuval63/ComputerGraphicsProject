// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Orton.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Coin.generated.h"

UCLASS()
class ORTONS_CUBE_API ACoin : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoin();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	
	AOrton* player;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
	int personalId = -1; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
	int room = -1; //Maybe will be used in the future to show the player how many coins it got in each room? Each coin's room would be changed according to its coordinates.
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
