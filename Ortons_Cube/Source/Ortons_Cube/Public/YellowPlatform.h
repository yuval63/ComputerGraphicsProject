// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ColoredPlatform.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "YellowPlatform.generated.h"

UCLASS()
class ORTONS_CUBE_API AYellowPlatform : public AColoredPlatform
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AYellowPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

		FVector originalLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
		float velocity = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
		FVector direction = FVector(1.0f, 0.0f, 0.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
		float range = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
		float startDelay = 0.0f;
};
