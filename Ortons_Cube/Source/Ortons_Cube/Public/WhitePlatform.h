// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ColoredPlatform.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WhitePlatform.generated.h"

UCLASS()
class ORTONS_CUBE_API AWhitePlatform : public AColoredPlatform
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWhitePlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		virtual void OnInteraction() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
		float flightDuration = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
	float flightSpeed = 50.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
	float maxFlightDuration = 50.0;
};
