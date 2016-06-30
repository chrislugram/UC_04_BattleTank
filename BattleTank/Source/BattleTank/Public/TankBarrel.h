// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// -1 is max downward speed, and +1 min
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = "Barrel Movement")
	float MaxDegreesPerSecond = 5;

	UPROPERTY(EditDefaultsOnly, Category = "Barrel Movement")
	float MaxDegreesElevation = 40;

	UPROPERTY(EditDefaultsOnly, Category = "Barrel Movement")
	float MinDegreesElevation = 0;
};
