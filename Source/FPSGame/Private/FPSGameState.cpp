#include "FPSGameState.h"
#include "Runtime/Engine/Classes/Engine/World.h"

void AFPSGameState::MulticastOnMissionComplete_Implementation(APawn* InstigatorPawn, bool bMissionSuccess)
{
	DisableInputForAllPawns();
}

void AFPSGameState::DisableInputForAllPawns()
{
	for (FConstPawnIterator PawnItr = GetWorld()->GetPawnIterator(); PawnItr; PawnItr++)
	{
		APawn* Pawn = PawnItr->Get();

		if (Pawn && (Pawn->IsLocallyControlled()))
		{
			//Passing nullptr for the PlayerController pointer disables input for whatever playercontroller
			//that owns the InstigatorPawn
			Pawn->DisableInput(nullptr);
		}
	}
}