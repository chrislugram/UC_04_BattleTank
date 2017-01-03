// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	ATank* GetControlledTank() const;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Aim")
	float CrossHairXLocation;

	UPROPERTY(EditDefaultsOnly, Category = "Aim")
	float CrossHairYLocation;

	UPROPERTY(EditDefaultsOnly, Category = "Aim")
	float LineTraceRange;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& HitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
