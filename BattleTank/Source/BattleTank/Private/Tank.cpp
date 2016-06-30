// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "Tank.h"

#pragma region CONSTRUCTORS
// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Setup TankAimingComponent
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Tank Aiming Component"));

	// Setup TankAimingComponent
	TankMovementComponent = CreateDefaultSubobject<UTankMovementComponent>(FName("Tank Movement Component"));
}
#pragma endregion

#pragma region ENGINE
// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
}
#pragma endregion

#pragma region METHODS
void ATank::Fire()
{
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeSeconds;

	if (Barrel && isReloaded)
	{
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);

		Projectile->LaunchProjectile(LaunchSpeed);

		LastFireTime = FPlatformTime::Seconds();
	}
}

void ATank::AimAt(FVector AimLocation)
{
	TankAimingComponent->AimAt(AimLocation, LaunchSpeed);
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSetup)
{
	TankAimingComponent->SetBarrelReference(BarrelToSetup);
	Barrel = BarrelToSetup;
}

void ATank::SetTurrentReference(UTankTurrent* TurrentToSetup)
{
	TankAimingComponent->SetTurrentReference(TurrentToSetup);
}
#pragma endregion

