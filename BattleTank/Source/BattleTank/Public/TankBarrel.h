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
	void Elevate(float DegreesPerSecond);

private:
	UPROPERTY(EditAnywhere, Category = "Barrel Movement")
	float MaxDegreesPerSecond = 20;

	UPROPERTY(EditAnywhere, Category = "Barrel Movement")
	float MaxDegreesElevation = 40;

	UPROPERTY(EditAnywhere, Category = "Barrel Movement")
	float MinDegreesElevation = 0;
};
