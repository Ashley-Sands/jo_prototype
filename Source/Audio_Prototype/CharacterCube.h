// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CharacterCube.generated.h"

UCLASS()
class AUDIO_PROTOTYPE_API ACharacterCube : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACharacterCube();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Audio")
		void SetSwitch(bool active);

	UFUNCTION(BlueprintImplementableEvent, Category = "Character")		//Called via blue print
		bool IsActive();
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Character")		//Called via blue print
		void ChangeCharacter();	


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


private:

	bool isActive;

};
