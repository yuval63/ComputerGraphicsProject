// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ColoredPlatform.h"


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RedPlatform.generated.h"

UCLASS()
class ORTONS_CUBE_API ARedPlatform : public AColoredPlatform
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARedPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		virtual void OnInteraction() override;


	float count = 0; // a loop that changes the stage of the block


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
		float heatSpeed = 7.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
		float startDelay = 0.0f;

	FRotator originalRotation;
};
