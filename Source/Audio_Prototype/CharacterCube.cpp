// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterCube.h"


// Sets default values
ACharacterCube::ACharacterCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	isActive = false;

}

// Called when the game starts or when spawned
void ACharacterCube::BeginPlay()
{
	Super::BeginPlay();
	ChangeCharacter();
}

// Called every frame
void ACharacterCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Set the player to change materals.
void ACharacterCube::SetSwitch(bool active)
{

	isActive = active;

	ChangeCharacter();

}

bool ACharacterCube::GetIsActive()
{
	return isActive; 
}

