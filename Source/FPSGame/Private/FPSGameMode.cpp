// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FPSGameMode.h"
#include "FPSHUD.h"
#include "FPSCharacter.h"
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
}

void AFPSGameMode::CompleteMission(APawn* InstigatorPawn)
{
	if (InstigatorPawn)
	{
		//Passing nullptr for the PlayerController pointer disables input for whatever playercontroller
		//that owns the InstigatorPawn
		InstigatorPawn->DisableInput(nullptr);
		AttemptToSetNewViewTarget(Cast<APlayerController>(InstigatorPawn->GetController()));
	}

	OnMissionCompleted(InstigatorPawn);

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