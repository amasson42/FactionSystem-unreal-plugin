// Copyright Amasson

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GenericTeamAgentInterface.h"
#include "FactionSystemLibrary.generated.h"


/**
 *
 */
UCLASS()
class FACTIONSYSTEM_API UFactionSystemLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "FactionSystemLibrary|Relation")
    static ETeamAttitude::Type GetAttitudeBetweenActors(AActor* Actor, AActor* OtherActor);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "FactionSystemLibrary|Relation")
    static bool AreActorsFriendly(AActor* Actor, AActor* OtherActor);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "FactionSystemLibrary|Relation")
    static bool AreActorsNeutral(AActor* Actor, AActor* OtherActor);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "FactionSystemLibrary|Relation")
    static bool AreActorsHostile(AActor* Actor, AActor* OtherActor);

};
