// Fill out your copyright notice in the Description page of Project Settings.

#include "DrawDebugHelpers.h"
#include "FPSAIGuard.h"
#include "FPSGameMode.h"
#include "AI/Navigation/NavigationSystem.h"
#include "Perception/PawnSensingComponent.h"
#include "TimerManager.h"

const float DEBUG_SPHERE_RADIUS = 32.0f;
const int DEBUG_SPHERE_NUM_SEGMENTS = 12;
const FColor DEBUG_SPHERE_COLOR_SEEN = FColor::Red;
const FColor DEBUG_SPHERE_COLOR_HEARD = FColor::Green;
const bool DEBUG_SPHERE_PERSISTENT_LINES = false;
const float DEBUG_SPHERE_LIFE_TIME_SEC = 10.0f;

const float RESET_ROTATION_TIMER_SEC = 3.0f;

const int ACCEPTABLE_MIN_DISTANCE_FROM_PATROL_POINT = 50;

AFPSAIGuard::AFPSAIGuard()
{
	PrimaryActorTick.bCanEverTick = true;
	CurrentPatrolPoint = nullptr;
	GuardState = EAIState::Idle;
	SetupPawnSensingComponent();
}

void AFPSAIGuard::SetupPawnSensingComponent()
{
	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));
}

void AFPSAIGuard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveToNextPatrolPointIfAtCurrentPatrolPoint();
}

void AFPSAIGuard::BeginPlay()
{
	Super::BeginPlay();
	SetPawnSensingComponentCallbacks();
	OriginalRotation = GetActorRotation();
	StartPatrolIfEnabled();
}

void AFPSAIGuard::SetPawnSensingComponentCallbacks()
{
	PawnSensingComp->OnSeePawn.AddDynamic(this, &AFPSAIGuard::OnPawnSeen);
	PawnSensingComp->OnHearNoise.AddDynamic(this, &AFPSAIGuard::OnPawnHeard);
}

void AFPSAIGuard::StartPatrolIfEnabled()
{
	if (bPatrol)
	{
		MoveToNextPatrolPoint();
	}
}

void AFPSAIGuard::OnPawnSeen(APawn* PawnSeen)
{
	if (PawnSeen == nullptr)
	{
		return;
	}

	SetGuardState(EAIState::Alerted);
	StopMovement();

	//TODO this code is duplicated from FPS Extraction Zone.  This code should
	//be contained in a small helper class or something
	AFPSGameMode* GameMode = Cast<AFPSGameMode>(GetWorld()->GetAuthGameMode());
	if (GameMode)
	{
		GameMode->CompleteMission(PawnSeen, false);
	}

	DrawDebugSphere(
		GetWorld(),
		PawnSeen->GetActorLocation(),
		DEBUG_SPHERE_RADIUS,
		DEBUG_SPHERE_NUM_SEGMENTS,
		DEBUG_SPHERE_COLOR_SEEN,
		DEBUG_SPHERE_PERSISTENT_LINES,
		DEBUG_SPHERE_LIFE_TIME_SEC);
}

void AFPSAIGuard::OnPawnHeard(APawn* PawnHeard, const FVector& LocationNoiseWasHeard, float Volume)
{
	if (GuardState == EAIState::Alerted)
	{
		return;
	}

	SetGuardState(EAIState::Suspicious);
	StopMovement();

	DrawDebugSphere(
		GetWorld(),
		LocationNoiseWasHeard,
		DEBUG_SPHERE_RADIUS,
		DEBUG_SPHERE_NUM_SEGMENTS,
		DEBUG_SPHERE_COLOR_HEARD,
		DEBUG_SPHERE_PERSISTENT_LINES,
		DEBUG_SPHERE_LIFE_TIME_SEC);

	SetActorToNewRotation(LocationNoiseWasHeard);
	StartResetOrientationTimer();
}

void AFPSAIGuard::SetActorToNewRotation(const FVector& NewLocationToRotateTowards)
{
	FVector Direction = NewLocationToRotateTowards - GetActorLocation();
	Direction.Normalize();

	FRotator RotationLookingAtNoiseHeard = FRotationMatrix::MakeFromX(Direction).Rotator();
	//Nullify any changes in pitch and roll so that we don't rotate the guard akwardly
	RotationLookingAtNoiseHeard.Pitch = 0.0f;
	RotationLookingAtNoiseHeard.Roll = 0.0f;

	SetActorRotation(RotationLookingAtNoiseHeard);
}

void AFPSAIGuard::StartResetOrientationTimer()
{
	GetWorldTimerManager().ClearTimer(ResetRotationTimer);

	GetWorldTimerManager().SetTimer(
		ResetRotationTimer,
		this,
		&AFPSAIGuard::ResetRotationToOriginalRotation,
		RESET_ROTATION_TIMER_SEC);
}

void AFPSAIGuard::ResetRotationToOriginalRotation()
{
	if (GuardState == EAIState::Alerted)
	{
		return;
	}

	SetGuardState(EAIState::Idle);
	SetActorRotation(OriginalRotation);

	StartPatrolIfEnabled();
}

void AFPSAIGuard::SetGuardState(EAIState NewState)
{
	if (GuardState != NewState)
	{
		GuardState = NewState;
		OnStateChanged(GuardState);
	}
}

void AFPSAIGuard::MoveToNextPatrolPoint()
{
	if ((CurrentPatrolPoint == nullptr) || (CurrentPatrolPoint == SecondPatrolPoint))
	{
		CurrentPatrolPoint = FirstPatrolPoint;
	}
	else
	{
		CurrentPatrolPoint = SecondPatrolPoint;
	}

	UNavigationSystem::SimpleMoveToActor(GetController(), CurrentPatrolPoint);
}

void AFPSAIGuard::MoveToNextPatrolPointIfAtCurrentPatrolPoint()
{
	if (CurrentPatrolPoint)
	{
		FVector Delta = GetActorLocation() - CurrentPatrolPoint->GetActorLocation();
		float DistanceToCurrentPatrolPoint = Delta.Size();

		if (DistanceToCurrentPatrolPoint < ACCEPTABLE_MIN_DISTANCE_FROM_PATROL_POINT)
		{
			MoveToNextPatrolPoint();
		}
	}
}

void AFPSAIGuard::StopMovement()
{
	AController* Controller = GetController();
	if (Controller)
	{
		Controller->StopMovement();
	}
}