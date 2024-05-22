// Copyright Amasson

#include "FactionSystem/FactionSystemLibrary.h"


ETeamAttitude::Type UFactionSystemLibrary::GetAttitudeBetweenActors(AActor* Actor, AActor* OtherActor)
{
    if (!IsValid(Actor) || !IsValid(OtherActor))
    {
        return ETeamAttitude::Neutral;
    }

    return FGenericTeamId::GetAttitude(Actor, OtherActor);
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
