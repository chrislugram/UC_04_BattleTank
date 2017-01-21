// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Public/TankBarrel.h"
#include "Public/TankTurrent.h"
#include "TankAimingComponent.h"

#pragma region CONSTRUCTORS
// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = false;
}
#pragma endregion

#pragma region METHODS
void UTankAimingComponent::Initialise(UTankBarrel* barrel, UTankTurrent* turret)
{
	Barrel = barrel;
	Turret = turret;
}

void UTankAimingComponent::AimAt(FVector AimLocation, float LaunchSpeed)
{
	if (!Barrel)
		return;

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	// Calculate de OutLauncVelocity
	bool result = UGameplayStatics::SuggestProjectileVelocity(
		this, OutLaunchVelocity, StartLocation, AimLocation, LaunchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if (result)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
		MoveTurrentTowards(AimDirection);
		//UE_LOG(LogTemp, Warning, TEXT("con solucion"));
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("sin solucion"));
	}
	
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	if (!Barrel || !Turret) { return; }

	auto BarrelRotation = Barrel->GetForwardVector().Rotation();	// Get current barrel rotation
	auto AimAsRotator = AimDirection.Rotation();					// Get new barrel rotation
	auto DeltaRotator = AimAsRotator - BarrelRotation;				// Delta between both rotations

	Barrel->Elevate(DeltaRotator.Pitch);
}

void UTankAimingComponent::MoveTurrentTowards(FVector AimDirection)
{
	if (!Barrel || !Turret) { return; }

	auto TurrenRotation = Turret->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - TurrenRotation;

	Turret->Rotate(DeltaRotator.Yaw);
}
#pragma endregion

