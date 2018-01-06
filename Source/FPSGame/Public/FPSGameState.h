#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "FPSGameState.generated.h"

UCLASS()
class FPSGAME_API AFPSGameState : public AGameStateBase
{
	GENERATED_BODY()
public:
	/*
	NetMulticast: If this function is called from server, it will be replicated across all clients and the server
	Reliable: This function is guaranteed to execute on the server
	*/
	UFUNCTION(NetMulticast, Reliable)
	void MulticastOnMissionComplete(APawn* InstiagtorPawn, bool bMissionSuccess);	

	void DisableInputForAllPawns();
};
