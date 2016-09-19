// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurrent;
class UTankAimingComponent;
class UTankMovementComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	void AimAt(FVector AimLocation);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetBarrelReference(UTankBarrel* BarrelToSetup);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetTurrentReference(UTankTurrent* TurrentToSetup);

	UFUNCTION(BlueprintCallable, Category = "Fire")
	void Fire();

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Aiming")
	UTankAimingComponent* TankAimingComponent = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	UTankMovementComponent* TankMovementComponent = nullptr;

private:

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Fire")
	float LaunchSpeed = 100000;

	UPROPERTY(EditDefaultsOnly, Category = "Fire")
	float ReloadTimeSeconds = 3;

	double LastFireTime = 0;

	UTankBarrel* Barrel = nullptr;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

};
