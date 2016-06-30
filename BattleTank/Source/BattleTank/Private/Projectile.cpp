// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Projectile.h"

#pragma region CONSTRUCTORS
// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Movement"));
	ProjectileMovement->bAutoActivate = false;
}
#pragma endregion

#pragma region ENGINE
// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}
#pragma endregion

#pragma region METHODS
void AProjectile::LaunchProjectile(float LaunchSpeed)
{
	UE_LOG(LogTemp, Warning, TEXT("Projectile launched!!!"));
	ProjectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * LaunchSpeed);
	ProjectileMovement->Activate();
}
#pragma endregion

