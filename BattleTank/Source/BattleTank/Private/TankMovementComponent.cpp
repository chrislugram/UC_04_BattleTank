// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"


#pragma region METHODS
void UTankMovementComponent::Initialise(UTankTrack* Left, UTankTrack* Right)
{
	LeftTrack = Left;
	RightTrack = Right;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (LeftTrack == nullptr || RightTrack == nullptr)
		return;

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
	// TODO: Prevent double-speed due to dual control use
}

void UTankMovementComponent::IntendRotate(float Throw)
{
	if (LeftTrack == nullptr || RightTrack == nullptr)
		return;

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
	// TODO: Prevent double-speed due to dual control use
}
#pragma endregion

