// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class AUDIO_PROTOTYPE_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(Category = "Movement", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		bool leftToRight;

	UPROPERTY(Category = "Movement", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		float speedPerSecond;

	UPROPERTY(Category = "Movement", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		FVector holdPosition;

	UPROPERTY(Category = "Movement", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		FVector startPosition;

	UPROPERTY(Category = "Movement", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		float travleDistance;

	//Resets projectile to its default location
	//UFUNCTION(BlueprintCallable, Category = "Movement")
		

	UFUNCTION(BlueprintCallable, Category = "Movement")
		void StartProjectile();

private:

	float currentYPosition;
	bool isProjectileActive;
	void Reset();
};
