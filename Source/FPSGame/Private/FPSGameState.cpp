#include "FPSGameState.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "FPSPlayerController.h"

void AFPSGameState::MulticastOnMissionComplete_Implementation(APawn* InstigatorPawn, bool bMissionSuccess)
{
	CallMissionCompleteForAllPlayerControllers(InstigatorPawn, bMissionSuccess);
}

void AFPSGameState::CallMissionCompleteForAllPlayerControllers(APawn* InstigatorPawn, bool bMissionSuccess)
{
	for (FConstPlayerControllerIterator PlayerControllerItr = GetWorld()->GetPlayerControllerIterator();
		PlayerControllerItr;
		PlayerControllerItr++)
	{
		AFPSPlayerController* PlayerController = Cast<AFPSPlayerController>(PlayerControllerItr->Get());
		{
			if (PlayerController && PlayerController->IsLocalController())
			{
				PlayerController->OnMissionCompleted(InstigatorPawn, bMissionSuccess);
				DisablePlayerControllerPawnInput(PlayerController);
			}
		}
	}
}

void AFPSGameState::DisablePlayerControllerPawnInput(AFPSPlayerController* PlayerController)
{
	APawn* LocalPawn = PlayerController->GetPawn();
	if (LocalPawn)
	{
		LocalPawn->DisableInput(PlayerController);
	}
}