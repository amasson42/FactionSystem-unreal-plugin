// Copyright by amasson


#include "FactionSystem/Pawn/FactionCharacter.h"
#include "FactionSystem/FactionData.h"
#include "FactionSystem/FactionDataInterface.h"


void AFactionCharacter::BeginPlay()
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

FGenericTeamId AFactionCharacter::GetGenericTeamId() const
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
