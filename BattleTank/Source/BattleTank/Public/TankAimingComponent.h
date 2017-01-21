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
	// Sets default values for this component's properties
	UTankAimingComponent();

	void AimAt(FVector AimLocation, float LaunchSpeed);

	void SetBarrelReference(UTankBarrel* BarrelToSetup);

	void SetTurrentReference(UTankTurrent* TurrentToSetup);

	void MoveBarrelTowards(FVector AimDirection);

	void MoveTurrentTowards(FVector AimDirection);
protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringStatus firingStatus = EFiringStatus::RELOADING;

private:
	UPROPERTY(VisibleAnywhere, Category = "Setup")
	UTankBarrel* Barrel = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Setup")
	UTankTurrent* Turrent = nullptr;

	
};
