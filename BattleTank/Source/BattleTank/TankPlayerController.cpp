// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"


#pragma region ENGINE
void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
	APawn* pawn = GetPawn();
	
	UE_LOG(LogTemp, Warning, TEXT("Name pawn: %s"), *(pawn->GetName()));

	ATank* tankPawn = Cast<ATank>(pawn);
	UE_LOG(LogTemp, Warning, TEXT("Name pawn: %s"), *(tankPawn->GetName()));
}
#pragma endregion

#pragma region METHODS
ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
#pragma endregion
