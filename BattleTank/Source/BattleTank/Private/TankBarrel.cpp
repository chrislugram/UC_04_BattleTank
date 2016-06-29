// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"

#pragma region METHODS
void UTankBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);									// Clamp the relative space, protection	

	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;	// Elevation change this frame
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;							// Calculating the new elevation

	RawNewElevation = FMath::Clamp(RawNewElevation, MinDegreesElevation, MaxDegreesElevation);	// Clamp the new elevation

	SetRelativeRotation(FRotator(RawNewElevation, 0, 0));										// Set the new rotation/elevation
}
#pragma endregion


