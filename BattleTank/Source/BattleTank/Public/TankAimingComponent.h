// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Enum for aiming states
UENUM()
enum class EFiringStatus : uint8
{
	RELOADING,
	AIMING,
	LOCKED
};

class UTankBarrel;
class UTankTurrent;
class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel* barrel, UTankTurrent* turret);

	void AimAt(FVector AimLocation);
	void MoveBarrelTowards(FVector AimDirection);
	void MoveTurrentTowards(FVector AimDirection);

	UFUNCTION(BlueprintCallable, Category = "Fire")
	void Fire();

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringStatus firingStatus = EFiringStatus::LOCKED;

	UPROPERTY(EditDefaultsOnly, Category = "Fire")
	float LaunchSpeed = 400000;

private:
	// Sets default values for this component's properties
	UTankAimingComponent();

	UTankBarrel* Barrel = nullptr;
	UTankTurrent* Turret = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Fire")
	float ReloadTimeSeconds = 3;

	double LastFireTime = 0;
};
