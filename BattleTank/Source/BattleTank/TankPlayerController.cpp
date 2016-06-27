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

	FVector HitLocation; // out parameter

	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
		// TODO: Tell controlled tank to aim at this point
	}
}

// Get world location of linetrace, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	HitLocation = FVector(1.0, 1.0, 1.0);
	// Find the crosshair position
	int32 viewportSizeX, viewportSizeY;
	GetViewportSize(viewportSizeX, viewportSizeY);
	FVector2D ScreenLocation(viewportSizeX * CrossHairXLocation, viewportSizeY * CrossHairYLocation);

	UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %f, %f"), ScreenLocation.X, ScreenLocation.Y);

	// "De-project" the screen position of the crosshair to a world direction
	// Line-trace along the look direction, and see what we hit
	return true;
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
#pragma endregion
