// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ColoredPlatform.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OrangePlatform.generated.h"

UCLASS()
class ORTONS_CUBE_API AOrangePlatform : public AColoredPlatform
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOrangePlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
		FVector originalLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
		float dropSpeed = 15.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
		float liftSpeed = 6.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
		float range = 10000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
		bool drops = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
		bool lifts = false;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
