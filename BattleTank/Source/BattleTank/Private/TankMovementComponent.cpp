// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"


#pragma region METHODS
void UTankMovementComponent::Initialise(UTankTrack* Left, UTankTrack* Right)
{
	if (Left == nullptr || Right == nullptr)
		return;

	LeftTrack = Left;
	RightTrack = Right;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT(" Intend move forward throw %f"), Throw);
	
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
	// TODO: Prevent double-speed due to dual control use
}

void UTankMovementComponent::IntendRotate(float Rotate)
{
	UE_LOG(LogTemp, Warning, TEXT(" Intend rotate  %f"), Rotate);
}
#pragma endregion

