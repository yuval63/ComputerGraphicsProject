// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "ColoredPlatform.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "BlackPlatform.generated.h"

UCLASS()
class ORTONS_CUBE_API ABlackPlatform : public AColoredPlatform
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlackPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;






public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	virtual void OnInteraction() override;

};

