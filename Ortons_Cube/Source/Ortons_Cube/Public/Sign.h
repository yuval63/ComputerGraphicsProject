// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include <string>
#include <vector>
#include "Orton.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sign.generated.h"


UCLASS()
class ORTONS_CUBE_API ASign : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASign();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//std::vector<FString> texts;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
		FString page1Text;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
	FString page2Text;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
	FString page3Text;



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
		FString page1Title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
		FString page2Title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
		FString page3Title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
	int numOfPages = 1;
	 
	AOrton* player;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NewStatus")
	bool pressed = false;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	bool getPressed();

	UFUNCTION(BlueprintCallable)
	void setPressed(bool newPressed);

	UFUNCTION(BlueprintCallable)
	FString getPageText(int pageNum);

		UFUNCTION(BlueprintCallable)
	FString getPageTitle(int pageNum);
};
