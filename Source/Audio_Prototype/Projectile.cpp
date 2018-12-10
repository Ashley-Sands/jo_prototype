// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	speedPerSecond = 5;
	isProjectileActive = false;

}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();

	// Set start position
	currentYPosition = startPosition.Y;
	SetActorLocation(startPosition);
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// move object in the correct direction
	if (leftToRight)
		currentYPosition += (speedPerSecond * DeltaTime);
	else
		currentYPosition -= (speedPerSecond * DeltaTime);

	if (!isProjectileActive) return;

	FVector newPosition = startPosition;
	newPosition.Y = currentYPosition;
	
	if (abs(startPosition.Y - currentYPosition) < travleDistance)
		SetActorLocation(newPosition);
	else
		Reset();

}

void AProjectile::Reset()
{
	isProjectileActive = false;
	SetActorLocation(startPosition);

}

void AProjectile::StartProjectile()
{
	isProjectileActive = true;
}