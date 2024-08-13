// Copyright Amasson

#include "FactionSystem/FactionSystemLibrary.h"
#include "FactionSystem/FactionData.h"
#include "FactionSystem/FactionDataInterface.h"


static AController* _FindController(AActor* Actor)
{
    if (APawn* AsPawn = Cast<APawn>(Actor))
    {
        return AsPawn->GetController();
    }
    else
    {
        return Cast<AController>(Actor);
    }
}

ETeamAttitude::Type UFactionSystemLibrary::GetAttitudeBetweenActors(AActor* Actor, AActor* OtherActor)
{
    AController* Controller = _FindController(Actor);
    AController* OtherController = _FindController(OtherActor);

    if (!IsValid(Controller) || !IsValid(OtherController))
    {
        return ETeamAttitude::Neutral;
    }

    return FGenericTeamId::GetAttitude(Controller, OtherController);
}

bool UFactionSystemLibrary::AreActorsFriendly(AActor* Actor, AActor* OtherActor)
{
    return GetAttitudeBetweenActors(Actor, OtherActor) == ETeamAttitude::Friendly;
}

bool UFactionSystemLibrary::AreActorsNeutral(AActor* Actor, AActor* OtherActor)
{
    return GetAttitudeBetweenActors(Actor, OtherActor) == ETeamAttitude::Neutral;
}

bool UFactionSystemLibrary::AreActorsHostile(AActor* Actor, AActor* OtherActor)
{
    return GetAttitudeBetweenActors(Actor, OtherActor) == ETeamAttitude::Hostile;
}

UFactionData* UFactionSystemLibrary::GetActorFactionData(AActor* Actor)
{
    if (IFactionDataInterface* FactionInterface = Cast<IFactionDataInterface>(Actor))
    {
        return FactionInterface->GetFactionData();
    }
    else if (APawn *AsPawn = Cast<APawn>(Actor))
    {
        return GetActorFactionData(AsPawn->GetController());
    }
    return nullptr;
}

void UFactionSystemLibrary::SetAttitudeBetweenFactions(UFactionData* Faction, UFactionData* OtherFaction, ETeamAttitude::Type Attitude)
{
    if (!IsValid(Faction))
        return;

    Faction->SetAttitudeTowardFaction(OtherFaction, Attitude);
}
