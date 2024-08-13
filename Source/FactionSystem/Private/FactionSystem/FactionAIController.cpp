// Copyright by amasson


#include "FactionSystem/FactionAIController.h"
#include "FactionSystem/FactionData.h"

FGenericTeamId AFactionAIController::GetGenericTeamId() const
{
	if (!IsValid(Faction))
    {
        return FGenericTeamId::NoTeam;
    }

    return Faction->TeamId;
}

void AFactionAIController::SetFactionData(UFactionData* FactionData)
{
    Faction = FactionData;
}
