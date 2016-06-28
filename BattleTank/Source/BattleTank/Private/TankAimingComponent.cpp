// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"

#pragma region CONSTRUCTORS
// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}
#pragma endregion

#pragma region ENGINE
// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}
#pragma endregion

#pragma region METHODS
void UTankAimingComponent::AimAt(FVector AimLocation)
{
	UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s"), *(GetOwner()->GetName()), *AimLocation.ToString());
}
#pragma endregion

