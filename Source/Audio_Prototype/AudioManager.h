// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AudioManager.generated.h"

class AA_AudioCube;
class ACharacterCube;

UCLASS()
class AUDIO_PROTOTYPE_API AAudioManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAudioManager();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(Category = "Audio", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		TArray<AA_AudioCube*> playerAudio;

	UPROPERTY(Category = "Audio", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		TArray<AA_AudioCube*> bossAudio;

	UPROPERTY(Category = "Audio", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		AA_AudioCube* switchAudio;

	UPROPERTY(Category = "Audio", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		float loopLength;

	UPROPERTY(Category = "Audio", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		float switchPauseLength;

	UPROPERTY(Category = "Character", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		ACharacterCube* playerCharacter;

	UPROPERTY(Category = "Character", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		ACharacterCube* bossCharacter;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	float playbackTime;
	float nextLoop;
	bool isPlayer;
	bool switchPlayer;
	float switchPlayerTimer;
	void SwitchPlayer();
	
	bool playedSwitchAudio;
	
	int currentProjectile;
	
};
