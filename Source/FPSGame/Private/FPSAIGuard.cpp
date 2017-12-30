// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSAIGuard.h"
#include "Perception/PawnSensingComponent.h"
#include "DrawDebugHelpers.h"

const float DEBUG_SPHERE_RADIUS = 32.0f;
const int DEBUG_SPHERE_NUM_SEGMENTS = 12;
const FColor DEBUG_SPHERE_COLOR_SEEN = FColor::Red;
const FColor DEBUG_SPHERE_COLOR_HEARD = FColor::Green;
const bool DEBUG_SPHERE_PERSISTENT_LINES = false;
const float DEBUG_SPHERE_LIFE_TIME_SEC = 10.0f;

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

	DrawDebugSphere(
		GetWorld(),
		PawnSeen->GetActorLocation(),
		DEBUG_SPHERE_RADIUS,
		DEBUG_SPHERE_NUM_SEGMENTS,
		DEBUG_SPHERE_COLOR_SEEN,
		DEBUG_SPHERE_PERSISTENT_LINES,
		DEBUG_SPHERE_LIFE_TIME_SEC);
}

void AFPSAIGuard::OnPawnHeard(APawn* PawnHeard, const FVector& Location, float Volume)
{
	DrawDebugSphere(
		GetWorld(),
		Location,
		DEBUG_SPHERE_RADIUS,
		DEBUG_SPHERE_NUM_SEGMENTS,
		DEBUG_SPHERE_COLOR_HEARD,
		DEBUG_SPHERE_PERSISTENT_LINES,
		DEBUG_SPHERE_LIFE_TIME_SEC);
}

void AFPSAIGuard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
