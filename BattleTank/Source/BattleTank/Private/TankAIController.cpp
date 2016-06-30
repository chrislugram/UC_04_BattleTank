// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Public/Tank.h"
#include "TankAIController.h"

#pragma region ENGINE
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	Tank = GetControlledTank();
	PlayerTank = GetPlayerTank();

	UE_LOG(LogTemp, Warning, TEXT("I'm %s, and aim to %s "), *Tank->GetName(), *PlayerTank->GetName());
}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// Aim
	Tank->AimAt(PlayerTank->GetActorLocation());

	// Fire
	Tank->Fire();
}
#pragma endregion

#pragma region METHODS
ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	APlayerController* playerController = GetWorld()->GetFirstPlayerController();
	if (playerController == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerController NOT FOUND"));
		return nullptr;
	}

	APawn* pawnPossesed = playerController->GetPawn();
	if (pawnPossesed == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Pawn possesed NOT FOUND"));
		return nullptr;
	}

	ATank* playerTank = Cast<ATank>(pawnPossesed);
	if (playerTank == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Cast to ATank error"));
		return nullptr;
	}

	return playerTank;
}
#pragma endregion
