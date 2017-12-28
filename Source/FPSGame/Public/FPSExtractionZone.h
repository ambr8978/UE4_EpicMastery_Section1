// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSExtractionZone.generated.h"

class UDecalComponent;
class UBoxComponent;

UCLASS()
class FPSGAME_API AFPSExtractionZone : public AActor
{
	GENERATED_BODY()
	
public:	
	AFPSExtractionZone();
	
	UFUNCTION()
	void HandleOverlap(
		UPrimitiveComponent* OverlappedComponent, 
		AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex, 
		bool bFromSweep, 
		const FHitResult& SweepResult);

protected:
	UPROPERTY(VisibleAnywhere, Category="Components")
	UBoxComponent* OverlapComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UDecalComponent* DecalComp;

private:
	UPROPERTY(EditDefaultsOnly, Category="Sounds")
	USoundBase* ObjectiveMissingSound;

	void SetupOverlapComponent();
	void SetupDecalComponent();
};
