// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectileLauncher.h"
#include "Projectile.h"

// Sets default values
AProjectileLauncher::AProjectileLauncher()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	currentProjectile = 0;
	currentLaunchTime = 0;
	timeToWait = 0;
	isActive = false;

}

// Called when the game starts or when spawned
void AProjectileLauncher::BeginPlay()
{
	Super::BeginPlay();

	if (launchLength.Num() > 0)
		timeToWait = launchLength[0];
	
}

// Called every frame
void AProjectileLauncher::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(debug)
		GEngine->AddOnScreenDebugMessage(8, 0.2f, FColor::Orange, isActive? "true":"false");

	if (!isActive || timeToWait < 0) return;

	timeToWait -= DeltaTime;

	if (timeToWait <= 0) {
		LaunchProjectile();
		currentLaunchTime++;
		if (currentLaunchTime < launchLength.Num())
			timeToWait += launchLength[currentLaunchTime];
	}

}

void AProjectileLauncher::SetLauncherActive(bool active)
{
	if (debug) {
		FString a = active ? "true" : "false";
		GEngine->AddOnScreenDebugMessage(12, 10.0f, FColor::Orange, "CAlled" + a);
	}
	isActive = active;

	if (!active) return;

	currentLaunchTime = 0;
	timeToWait = launchLength[0];
}

void AProjectileLauncher::LaunchProjectile()
{

	projectiles[currentProjectile]->StartProjectile();

	currentProjectile++;

	if (currentProjectile >= projectiles.Num())
		currentProjectile = 0;

}