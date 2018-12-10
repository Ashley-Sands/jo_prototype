// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterCube.h"


// Sets default values
ACharacterCube::ACharacterCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACharacterCube::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacterCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

