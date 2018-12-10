// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	speedPerSecond = 5;

}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	currentYPosition = startPosition.Y;
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (leftToRight)
		currentYPosition += (speedPerSecond * DeltaTime);
	else
		currentYPosition -= (speedPerSecond * DeltaTime);

	FVector newPosition = startPosition;
	newPosition.Y = currentYPosition;

	SetActorLocation(newPosition);

}

