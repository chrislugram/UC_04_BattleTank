// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

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

private:
	UPROPERTY(VisibleAnywhere, Category = "Setup")
	UTankBarrel* Barrel = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Setup")
	UTankTurrent* Turrent = nullptr;
};
