// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSLaunchPad.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class ACharacter;
class UPrimitiveComponent;

UCLASS()
class FPSGAME_API AFPSLaunchPad : public AActor
{
	GENERATED_BODY()

public:
	AFPSLaunchPad();

protected:
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UBoxComponent* OverlapComp;

	//Total impulse added to the cahacter on overlap.  
	//Marked EditInstanceOnly to allow in-level editing of this property per instance.
	UPROPERTY(EditInstanceOnly, Category = "LaunchPad")
		float LaunchStrength;

	//Angle added on top of actor rotation to launch the character.
	UPROPERTY(EditInstanceOnly, Category = "LaunchPad")
		float LaunchPitchAngle;

	//Effect to play when activating launch pad
	UPROPERTY(EditDefaultsOnly, Category = "LaunchPad")
		UParticleSystem* ActiveLaunchPadEffect;

	UFUNCTION()
		void OverlapLaunchPad(
			UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult & SweepResult);

private:
	void SetupOverlapComponent();
	void SetOverlapComponentAsRootComponent();
	void SetupMeshComponent();
	void SetLaunchVariableDefaults();
	FVector GetDesiredLaunchVelocity();

	void LaunchCharacter(ACharacter* CharacterToLaunch, FVector LaunchVelocity);
	void LaunchComponent(UPrimitiveComponent* CompToLaunch, FVector LaunchVelocity);
};
