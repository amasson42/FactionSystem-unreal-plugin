// Copyright Amasson


#include "FactionSystem/FactionData.h"

static uint8 _TeamAttitudes[256][256];
static bool _TeamAttitudesInitialized = false;

static void _InitializeTeamAttitudes()
{
    if (_TeamAttitudesInitialized)
        return;

    for (int i = 0; i < 256; ++i)
    {
        for (int j = 0; j < 256; ++j)
        {
            _TeamAttitudes[i][j] = static_cast<uint8>(ETeamAttitude::Neutral);
        }
    }
    _TeamAttitudesInitialized = true;
}

ETeamAttitude::Type FactionSystemAttitudeSolver(FGenericTeamId TeamId, FGenericTeamId OtherTeamId)
{
    return static_cast<ETeamAttitude::Type>(_TeamAttitudes[TeamId.GetId()][OtherTeamId.GetId()]);
}

UFactionData::UFactionData()
{

}

void UFactionData::PostLoad()
{
    Super::PostLoad();

    _InitializeTeamAttitudes();
    for (int i = 0; i < 256; ++i)
    {
        _TeamAttitudes[TeamId.GetId()][i] = static_cast<uint8>(DefaultAttitude);
    }
    for (auto& Attitude : Attitudes)
    {
        if (!IsValid(Attitude.Key))
            continue;

        _TeamAttitudes[TeamId.GetId()][Attitude.Key->TeamId.GetId()] = static_cast<uint8>(Attitude.Value);
    }
    FGenericTeamId::SetAttitudeSolver(FactionSystemAttitudeSolver);
}

void UFactionData::SetAttitudeTowardFaction(UFactionData* OtherFaction, TEnumAsByte<ETeamAttitude::Type> Attitude)
{
    if (!IsValid(OtherFaction))
        return;

    _TeamAttitudes[TeamId.GetId()][OtherFaction->TeamId.GetId()] = static_cast<uint8>(Attitude);
}
