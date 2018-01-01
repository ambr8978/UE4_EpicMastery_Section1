// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSAIGuard.h"
#include "Perception/PawnSensingComponent.h"
#include "DrawDebugHelpers.h"
#include "TimerManager.h"
#include "FPSGameMode.h"

const float DEBUG_SPHERE_RADIUS = 32.0f;
const int DEBUG_SPHERE_NUM_SEGMENTS = 12;
const FColor DEBUG_SPHERE_COLOR_SEEN = FColor::Red;
const FColor DEBUG_SPHERE_COLOR_HEARD = FColor::Green;
const bool DEBUG_SPHERE_PERSISTENT_LINES = false;
const float DEBUG_SPHERE_LIFE_TIME_SEC = 10.0f;

const float RESET_ROTATION_TIMER_SEC = 3.0f;

AFPSAIGuard::AFPSAIGuard()
{
	PrimaryActorTick.bCanEverTick = true;
	SetupPawnSensingComponent();
}

void AFPSAIGuard::SetupPawnSensingComponent()
{
	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));
}

void AFPSAIGuard::BeginPlay()
{
	Super::BeginPlay();
	SetPawnSensingComponentCallbacks();
	OriginalRotation = GetActorRotation();
}

void AFPSAIGuard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFPSAIGuard::SetPawnSensingComponentCallbacks()
{
	PawnSensingComp->OnSeePawn.AddDynamic(this, &AFPSAIGuard::OnPawnSeen);
	PawnSensingComp->OnHearNoise.AddDynamic(this, &AFPSAIGuard::OnPawnHeard);
}

void AFPSAIGuard::OnPawnSeen(APawn* PawnSeen)
{
	if (PawnSeen == nullptr)
	{
		return;
	}

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
	SetActorRotation(OriginalRotation);
}