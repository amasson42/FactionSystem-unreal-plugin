// Copyright by amasson


#include "FactionSystem/Pawn/FactionPawn.h"


void AFactionPawn::BeginPlay()
{
	Super::BeginPlay();
	
	if (IsValid(FactionOverride))
	{
		if (IFactionDataInterface* FactionInterface = Cast<IFactionDataInterface>(GetController()))
		{
			FactionInterface->SetFactionData(FactionOverride);
		}
	}
}

FGenericTeamId AFactionPawn::GetGenericTeamId() const
{
	if (IGenericTeamAgentInterface* TeamAgentController = Cast<IGenericTeamAgentInterface>(GetController()))
	{
		return TeamAgentController->GetGenericTeamId();
	}
	else if (IsValid(FactionOverride))
	{
		return FactionOverride->TeamId.GetId();
	}
	return FGenericTeamId::NoTeam;
}
