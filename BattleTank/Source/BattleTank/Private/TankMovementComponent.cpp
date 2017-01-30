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
	if (!ensure(LeftTrack && RightTrack)) { return; }

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
	// TODO: Prevent double-speed due to dual control use
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
	// TODO: Prevent double-speed due to dual control use
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	FVector TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	FVector AIForwardIntention = MoveVelocity.GetSafeNormal();

	float ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	IntendMoveForward(ForwardThrow);

	FVector RightThrow = FVector::CrossProduct(TankForward, AIForwardIntention);
	IntendTurnRight(RightThrow.Z);
	
	//UE_LOG(LogTemp, Warning, TEXT("Tank %s, velocity: %s"), *(GetOwner()->GetName()), *MoveVelocity.GetSafeNormal().ToString());
}
#pragma endregion

