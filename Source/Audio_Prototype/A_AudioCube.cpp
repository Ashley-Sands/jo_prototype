// Fill out your copyright notice in the Description page of Project Settings.

#include "A_AudioCube.h"
#include "Components/AudioComponent.h"


// Sets default values
AA_AudioCube::AA_AudioCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bpm = 140.0f;
	playbackTime = 0.0f;
	isPlaying = false;
	AudioSource = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio Source"));
}

// Called when the game starts or when spawned
void AA_AudioCube::BeginPlay()
{
	Super::BeginPlay();
	
		AudioSource->Sound = AudioClips;
		
		beatLength = (60.0f / bpm);
		nextCueTime = beatLength * startBeat;
		beatLength *= (1.0 / playbackSpeed);
		
		//debug = false;

		//GetWorldTimerManager().SetTimer(PlaybackTimer, this, &AA_AudioCube::Playback, startWait, false);
}

// Called every frame
void AA_AudioCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	playbackTime += DeltaTime;

	if (debug) {
		FString playbackTimeHeaderStr = "Playback Position";
		FString playbackTimeStr = FString::SanitizeFloat(playbackTime);

		GEngine->AddOnScreenDebugMessage(1, 0.2f, FColor::Red, playbackTimeHeaderStr);
		GEngine->AddOnScreenDebugMessage(0, 0.2f, FColor::Red, playbackTimeStr);

		FString psStr = FString::SanitizeFloat(nextCueTime);
		GEngine->AddOnScreenDebugMessage(2, 0.2f, FColor::Blue, psStr);
	}

	if (playbackTime >= nextCueTime) 
	{

		if (isPlaying) {
			AudioSource->Play(0);// playbackTime - nextCueTime);

			nextCueTime += beatLength;
		}
	}

}

void AA_AudioCube::SetPlay(bool play, bool singlePlay)
{
	if (singlePlay)
	{
		AudioSource->Play(0);
		return;
	}
	else
	{
		isPlaying = play;
	}

	if (!isPlaying)
		Stop();
	else {
		nextCueTime = playbackTime + ((60.0f / bpm) * startBeat);
		if (debug) 
		{
			FString playbackTimeStr = FString::SanitizeFloat(playbackTime);
			FString beatLengthStr = FString::SanitizeFloat(playbackTime);
			FString startBeatStr = FString::SanitizeFloat(playbackTime);
			FString sbblStr = FString::SanitizeFloat(playbackTime * startBeat);
			FString cueStr = FString::SanitizeFloat(nextCueTime);

			GEngine->AddOnScreenDebugMessage(10, 25.0f, FColor::Red, "pb: " + playbackTimeStr + " beatLength: " + beatLengthStr + " startBeat: " + startBeatStr + " sb*bl: " + sbblStr + " cueTime: " + cueStr);
		}
	}
}

void AA_AudioCube::Stop()
{
	AudioSource->Stop();
}
/*
void AA_AudioCube::Playback() {

	//AudioSource->Play();

	//GetWorldTimerManager().SetTimer(PlaybackTimer, this, &AA_AudioCube::Playback, beatLength, false);

}*/