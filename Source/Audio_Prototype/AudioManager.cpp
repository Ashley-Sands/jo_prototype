// Fill out your copyright notice in the Description page of Project Settings.


#include "AudioManager.h"
#include "A_AudioCube.h"

// Sets default values
AAudioManager::AAudioManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	isPlayer = true;

	loopLength = 2;
	nextLoop = 0;
	switchPlayer = true;
	playedSwitchAudio = false;
}

// Called when the game starts or when spawned
void AAudioManager::BeginPlay()
{
	Super::BeginPlay();
	/*
	for (int i = 0; i < playerAudio.Num(); i++)
		playerAudio[i]->SetPlay(true);
		*/
	//nextLoop += loopLength;
	//switchPauseLength = 1.0f;
	switchPlayerTimer = 0.0f;
}

// Called every frame
void AAudioManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	playbackTime += DeltaTime;

	FString playbackTimeStr = FString::SanitizeFloat(playbackTime);
	GEngine->AddOnScreenDebugMessage(3, 0.2f, FColor::Green, "Manager");
	GEngine->AddOnScreenDebugMessage(4, 0.2f, FColor::Green, playbackTimeStr);

	FString psStr = FString::SanitizeFloat(nextLoop);
	GEngine->AddOnScreenDebugMessage(5, 0.2f, FColor::Black, psStr);

	if (switchPlayer)
	{

		if (!playedSwitchAudio)
		{
			switchAudio->SetPlay(true, true);
			playedSwitchAudio = true;
		}

		if (switchPlayerTimer < switchPauseLength)
		{
			switchPlayerTimer += DeltaTime;
		}
		else
		{
			SwitchPlayer();
			switchPlayer = false;
			switchPlayerTimer = 0.0f;
			playedSwitchAudio = false;
			//Change the active charater mesh.
			ChangeCharacter();
		}
	}

	if (playbackTime < nextLoop || switchPlayer) return;

	isPlayer = !isPlayer;

	int audioCount = 0;

	audioCount = playerAudio.Num();

	if (audioCount < bossAudio.Num())
		audioCount = bossAudio.Num();

	for (int i = 0; i < audioCount; i++) {

		if(!isPlayer && i < playerAudio.Num())
			playerAudio[i]->SetPlay(isPlayer);

		if (isPlayer && i < bossAudio.Num())
			bossAudio[i]->SetPlay(!isPlayer);

	}
	switchPlayer = true;
	//nextLoop += loopLength;

}


void AAudioManager::SwitchPlayer()
{

	int audioCount = 0;

	audioCount = playerAudio.Num();

	if (audioCount < bossAudio.Num())
		audioCount = bossAudio.Num();

	for (int i = 0; i < audioCount; i++) {

		if (isPlayer && i < playerAudio.Num())
			playerAudio[i]->SetPlay(isPlayer);

		if (!isPlayer && i < bossAudio.Num())
			bossAudio[i]->SetPlay(!isPlayer);

	}

	nextLoop += loopLength;

}
