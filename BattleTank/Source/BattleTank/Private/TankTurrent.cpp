// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurrent.h"

#pragma region METHODS
void UTankTurrent::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);									// Clamp the relative space, protection	

	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;	// Rotation change this frame
	auto NewRotation = RelativeRotation.Yaw + RotationChange;							// Calculating the new rotation

	NewRotation = FMath::Clamp(NewRotation, MinDegreesRotation, MaxDegreesRotation);	// Clamp the new rotation

	SetRelativeRotation(FRotator(0, NewRotation, 0));
}
#pragma endregion


