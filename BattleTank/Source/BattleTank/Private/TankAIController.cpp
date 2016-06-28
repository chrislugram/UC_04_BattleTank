// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

#pragma region ENGINE
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	// Example
	UE_LOG(LogTemp, Warning, TEXT("AIController Begin Play"));
	APawn* pawn = GetPawn();
	Tank = Cast<ATank>(pawn);

	// Find the player tank
	PlayerTank = GetPlayerTank();
	if (PlayerTank == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player tank not found"));
	}
}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	Tank->AimAt(PlayerTank->GetActorLocation());
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
