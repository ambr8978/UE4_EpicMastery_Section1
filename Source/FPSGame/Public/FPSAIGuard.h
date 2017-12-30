// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FPSAIGuard.generated.h"

class UPawnSensingComponent;

UCLASS()
class FPSGAME_API AFPSAIGuard : public ACharacter
{
	GENERATED_BODY()

public:
	AFPSAIGuard();

	virtual void Tick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UPawnSensingComponent* PawnSensingComp;

	//Parameters are in accordance with the OnSeePawn delegate 
	//To find definition of delegate, go to declaration of OnSeePawn,
	//then to the defintion of the FSeePawnDelegate
	UFUNCTION()
	void OnPawnSeen(APawn* PawnSeen);

	UFUNCTION()
	void OnPawnHeard(APawn* PawnHeard, const FVector& Location, float Volume);
private:
	void SetupPawnSensingComponent();
	void SetPawnSensingComponentCallbacks();
};
