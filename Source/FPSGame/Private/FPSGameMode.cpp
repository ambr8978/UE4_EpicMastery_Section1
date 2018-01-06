// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FPSGameMode.h"
#include "FPSHUD.h"
#include "FPSCharacter.h"
#include "FPSGameState.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

const float VIEW_BLEND_TIME_SECONDS = 0.5f;

AFPSGameMode::AFPSGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/BP_Player"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFPSHUD::StaticClass();

	// From what I understand, StaticClass creates a static instance of the calling class,
	// regardless of whether or not the class was implemented in a static way, so as 
	// to allow static, compile-time assignment.
	//
	// This allows us to assign the GameMode.GameStateClass variable to our 
	// FPSGameState implementation even though it hasn't been instantiated yet?
	GameStateClass = AFPSGameState::StaticClass();
}

void AFPSGameMode::CompleteMission(APawn* InstigatorPawn, bool bMissionSuccess)
{
	if (InstigatorPawn)
	{
		AttemptToSetNewViewTarget(Cast<APlayerController>(InstigatorPawn->GetController()));
		NotifyClientsOfMissionComplete(InstigatorPawn, bMissionSuccess);
	}

	OnMissionCompleted(InstigatorPawn, bMissionSuccess);

}

void AFPSGameMode::AttemptToSetNewViewTarget(APlayerController* PlayerController)
{
	if (SpectatingViewpointClass != nullptr)
	{
		AActor* NewViewTarget = GetNewViewTarget();
		if (NewViewTarget != nullptr)
		{
			SetNewViewTarget(NewViewTarget, PlayerController);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("SpectatingViewpointClass is nullptr. Please update GameMode class with valid subclass. Cannot change specating view target"));
	}
}

void AFPSGameMode::NotifyClientsOfMissionComplete(APawn* InstigatorPawn, bool bMissionSuccess)
{
	AFPSGameState* GameState = GetGameState<AFPSGameState>();
	if (GameState)
	{
		GameState->MulticastOnMissionComplete(InstigatorPawn, bMissionSuccess);
	}
}

AActor* AFPSGameMode::GetNewViewTarget()
{
	TArray<AActor*> SpectatingViewpointActors;
	UGameplayStatics::GetAllActorsOfClass(this, SpectatingViewpointClass, SpectatingViewpointActors);

	AActor* NewViewTarget = nullptr;
	if (SpectatingViewpointActors.Num() > 0)
	{
		NewViewTarget = SpectatingViewpointActors[0];
	}

	return NewViewTarget;
}

void AFPSGameMode::SetNewViewTarget(AActor* NewViewTarget, APlayerController* PlayerController)
{
	if (PlayerController)
	{
		PlayerController->SetViewTargetWithBlend(NewViewTarget, VIEW_BLEND_TIME_SECONDS, EViewTargetBlendFunction::VTBlend_Cubic);
	}
}