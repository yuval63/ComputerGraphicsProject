// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <string>

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "OrtonEnding.generated.h"

UCLASS()
class ORTONS_CUBE_API AOrtonEnding : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AOrtonEnding();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
		void Pressed(float Value);




	UFUNCTION(BlueprintCallable)
	int getCurrentPageNum();

	UFUNCTION(BlueprintCallable)
	void setCurrentPageNum(int newPageNum);

	UFUNCTION(BlueprintCallable)
		int getCurrentEndingNum();

	UFUNCTION(BlueprintCallable)
		void setCurrentEndingNum(int newPageNum);

	UFUNCTION(BlueprintCallable)
		FString getCurrentText1();

	UFUNCTION(BlueprintCallable)
	void setCurrentText1(FString newText);


	UFUNCTION(BlueprintCallable)
		FString getCurrentText2(int currentPage);

	UFUNCTION(BlueprintCallable)
	void setCurrentText2(int currentPage,FString newText);

	UFUNCTION(BlueprintCallable)
		FString getCurrentText3(int endingNum,int pageNum);

	UFUNCTION(BlueprintCallable)
	void setCurrentText3(int endingNum, int pageNum,FString newText);




	FString text[7][4];

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
		int currentEndingNum = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
		int currentPageNum = 0;


	APlayerController* controller;
};
