// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"


#pragma region METHODS
void UTankTrack::SetThrottle(float Throttle)
{
	UE_LOG(LogTemp, Warning, TEXT(" %s move %f "), *GetName(), Throttle)

	// TODO clamp actual throttle value
}
#pragma endregion

