// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Orton.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ColoredPlatform.generated.h"

UCLASS()
class ORTONS_CUBE_API AColoredPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AColoredPlatform();

	virtual void OnInteraction();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	AOrton* player;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
