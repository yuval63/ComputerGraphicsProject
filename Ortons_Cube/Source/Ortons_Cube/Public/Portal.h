// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Orton.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Portal.generated.h"

UCLASS()
class ORTONS_CUBE_API APortal : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APortal();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
	FVector to = FVector(0.f);

	bool unlocked = false;
	
	UAnimSequence* Anim;

	int portalID = -1; // -1 is unlocked by default, 0-6 is special endings portal

		int fromRoomID = -1;
		
		int toRoomID = -1;


	AOrton* player;
};
