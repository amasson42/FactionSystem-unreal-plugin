// Copyright Amasson

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GenericTeamAgentInterface.h"
#include "FactionData.generated.h"


/**
 * 
 */
UCLASS()
class FACTIONSYSTEM_API UFactionData : public UDataAsset
{
	GENERATED_BODY()

public:

    /** Team ID */
    UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Team")
    FGenericTeamId TeamId;

    // TODO: Create relation system and use custom attitude solver
    // /** Attitude against others factions */
    // UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attitude")
    // TMap<UFactionData*, TEnumAsByte<ETeamAttitude::Type>> Attitudes;

    // /** Attitude against unknown factions */
    // UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attitude")
    // TEnumAsByte<ETeamAttitude::Type> DefaultAttitude = ETeamAttitude::Neutral;

};
