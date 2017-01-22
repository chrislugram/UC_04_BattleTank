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

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel* barrel, UTankTurrent* turret);

	void AimAt(FVector AimLocation, float LaunchSpeed);

	void MoveBarrelTowards(FVector AimDirection);

	void MoveTurrentTowards(FVector AimDirection);
protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringStatus firingStatus = EFiringStatus::AIMING;

private:
	// Sets default values for this component's properties
	UTankAimingComponent();

	UTankBarrel* Barrel = nullptr;
	UTankTurrent* Turret = nullptr;

	
};
