// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankPlayerController.h"


#pragma region ENGINE
void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	aimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(aimingComponent)) { return; }
	FoundAimingComponent(aimingComponent);
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
	if (!ensure(aimingComponent)) { return; }

	FVector HitLocation; // out parameter
	if (GetSightRayHitLocation(HitLocation))
	{
		aimingComponent->AimAt(HitLocation);
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

	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		if (GetLookVectorHitLocation(LookDirection, HitLocation))
		{
			//GetControlledTank()->AimAt(HitLocation);
		}
	}

	return true;
}

// Line-trace along the look direction, and see what we hit
bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	FVector CameraLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = CameraLocation + (LookDirection * LineTraceRange);
	
	bool result = GetWorld()->LineTraceSingleByChannel(HitResult, CameraLocation, EndLocation, ECollisionChannel::ECC_Visibility);

	if (result)
		HitLocation = HitResult.Location;

	return result;
}

// "De-project" the screen position of the crosshair to a world direction
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;
	bool resultDeproject = DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection
	);

	return resultDeproject;
}
#pragma endregion
