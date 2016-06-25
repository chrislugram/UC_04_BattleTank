// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

#pragma region ENGINE
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("AIController Begin Play"));
	APawn* pawn = GetPawn();

	UE_LOG(LogTemp, Warning, TEXT("Name pawn: %s"), *(pawn->GetName()));

	ATank* tankPawn = Cast<ATank>(pawn);
	UE_LOG(LogTemp, Warning, TEXT("Name pawn: %s"), *(tankPawn->GetName()));
}
#pragma endregion

#pragma region METHODS
ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
#pragma endregion
