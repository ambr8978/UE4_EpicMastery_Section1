// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FPSAIGuard.generated.h"

class UPawnSensingComponent;

//Enum values must be uint8 to be used in BP (lecture 29)
UENUM(BlueprintType)
enum class EAIState : uint8
{
	Idle,
	Suspicious,
	Alerted
};

UCLASS()
class FPSGAME_API AFPSAIGuard : public ACharacter
{
	GENERATED_BODY()

public:
	AFPSAIGuard();

	virtual void Tick(float DeltaTime) override;
protected:
	UPROPERTY(ReplicatedUsing=OnRep_GuardState)
	EAIState GuardState;

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UPawnSensingComponent* PawnSensingComp;

	//Parameters are in accordance with the OnSeePawn delegate 
	//To find definition of delegate, go to declaration of OnSeePawn,
	//then to the defintion of the FSeePawnDelegate
	UFUNCTION()
		void OnPawnSeen(APawn* PawnSeen);

	UFUNCTION()
		void OnPawnHeard(APawn* PawnHeard, const FVector& LocationNoiseWasHeard, float Volume);

	//This function will get called when guard state changes for clients only
	UFUNCTION()
	void OnRep_GuardState();

	//Apply rules to replicated values (GuardState in this case).
	//Specifically, we will specify that GuardState should be replicated for all clients.
	//This function is required in tandem with OnRep_GuardState for the replicated
	//GuardState to work across clients
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;

	void SetGuardState(EAIState NewState);

	UFUNCTION(BlueprintImplementableEvent, Category = "AI")
		void OnStateChanged(EAIState NewState);

protected:
	FRotator OriginalRotation;
	FTimerHandle ResetRotationTimer;

	UPROPERTY(EditInstanceOnly, Category = "AI")
		bool bPatrol;

	UPROPERTY(EditInstanceOnly, Category = "AI", meta = (EditCondition = "bPatrol"))
		AActor* FirstPatrolPoint;

	UPROPERTY(EditInstanceOnly, Category = "AI", meta = (EditCondition = "bPatrol"))
		AActor* SecondPatrolPoint;

	AActor* CurrentPatrolPoint;
	void MoveToNextPatrolPoint();

private:

	void SetupPawnSensingComponent();
	void SetPawnSensingComponentCallbacks();
	void StartPatrolIfEnabled();

	void SetActorToNewRotation(const FVector& NewLocationToRotateTowards);
	void StartResetOrientationTimer();

	void MoveToNextPatrolPointIfAtCurrentPatrolPoint();
	void StopMovement();

	UFUNCTION()
		void ResetRotationToOriginalRotation();
};
