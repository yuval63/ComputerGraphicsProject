// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ColoredPlatform.h"
#include "YellowPlatform.generated.h"

/**
 * 
 */
UCLASS()
class ORTONS_CUBE_API AYellowPlatform : public AColoredPlatform
{
	GENERATED_BODY()
	
public:

	FVector originalLocation;
	float velocity;
	FVector direction;
	float range;
};
