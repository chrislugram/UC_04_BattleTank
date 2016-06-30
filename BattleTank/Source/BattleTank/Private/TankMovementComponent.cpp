// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankMovementComponent.h"


#pragma region METHODS
void UTankMovementComponent::IntendMoveForward(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT(" Intend move fordward throw %f"), Throw);
}

void UTankMovementComponent::IntendRotate(float Rotate)
{
	UE_LOG(LogTemp, Warning, TEXT(" Intend rotate  %f"), Rotate);
}
#pragma endregion

