// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine.h"
#include "Components/AudioComponent.h"

#include "A_AudioCube.generated.h"


UCLASS()
class AUDIO_PROTOTYPE_API AA_AudioCube : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AA_AudioCube();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Audio")
		void SetPlay(bool play, bool singlePlay = false);

	UPROPERTY(Category = "Audio Setup", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		float bpm;

	UPROPERTY(Category = "Audio Setup", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		float playbackSpeed;

	UPROPERTY(Category = "Audio Setup", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		float startBeat;

	UPROPERTY(Category = "Audio Source", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		USoundWave* AudioClips;

	UPROPERTY(Category = "Audio Source", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		UAudioComponent* AudioSource;

	UPROPERTY(Category = "Audio Setup", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		bool debug;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//FTimerHandle PlaybackTimer;
	
private:

	float beatLength;
	//void Playback();
	float playbackTime;
	float nextCueTime;
	bool isPlaying;

	void Stop();
	

};
