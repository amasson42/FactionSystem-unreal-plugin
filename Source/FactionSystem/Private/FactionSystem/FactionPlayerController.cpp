// Copyright by amasson


#include "FactionSystem/FactionPlayerController.h"
#include "FactionSystem/FactionData.h"

FGenericTeamId AFactionPlayerController::GetGenericTeamId() const
{
	if (!IsValid(Faction))
    {
        return FGenericTeamId::NoTeam;
    }

    return Faction->TeamId;
}

void AFactionPlayerController::SetFactionData(UFactionData* FactionData)
{
    Faction = FactionData;
}
