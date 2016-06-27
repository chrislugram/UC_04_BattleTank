// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"


#pragma region ENGINE
void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
	APawn* pawn = GetPawn();
	ATank* tankPawn = Cast<ATank>(pawn);
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}
#pragma endregion

#pragma region METHODS
void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank())
		return;

	// Get world location if linetrace through crosshair
	// If it hits tne landscape
		// Tell controlled tank to aim at this point

}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
#pragma endregion
