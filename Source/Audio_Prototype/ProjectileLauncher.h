// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileLauncher.generated.h"

class AProjectile;

UCLASS()
class AUDIO_PROTOTYPE_API AProjectileLauncher : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectileLauncher();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(Category = "Projectiles", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		TArray<AProjectile> projectiles;

	UPROPERTY(Category = "Character", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		TArray<float> launchLength;

	UFUNCTION(BlueprintCallable, Category = "Audio")
		void SetLauncherActive(bool active);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	void LaunchProjectile();

	int currentProjectile;
	int currentLaunchTime;

	float timeToWait;

	bool isActive;
	
};
