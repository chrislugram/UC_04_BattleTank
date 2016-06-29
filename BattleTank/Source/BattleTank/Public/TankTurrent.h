// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurrent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTurrent : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Rotate(float RelativeSpeed);
	
private:
	UPROPERTY(EditAnywhere, Category = "Turrent Movement")
		float MaxDegreesPerSecond = 10;

	UPROPERTY(EditAnywhere, Category = "Turrent Movement")
		float MaxDegreesRotation = 60;

	UPROPERTY(EditAnywhere, Category = "Turrent Movement")
		float MinDegreesRotation = -60;
};
