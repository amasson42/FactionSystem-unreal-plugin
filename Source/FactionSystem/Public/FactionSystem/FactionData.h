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

    UFactionData();

    void PostLoad() override;

    /** Team ID. Pick a different one for each Faction Data */
    UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Team")
    FGenericTeamId TeamId;

    /** Attitude against others factions */
    UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attitude")
    TMap<UFactionData*, TEnumAsByte<ETeamAttitude::Type>> Attitudes;

    /** Attitude against unknown factions */
    UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attitude")
    TEnumAsByte<ETeamAttitude::Type> DefaultAttitude = ETeamAttitude::Neutral;

    UFUNCTION(BlueprintCallable, Category = "Attitude")
    void SetAttitudeTowardFaction(UFactionData* OtherFaction, TEnumAsByte<ETeamAttitude::Type> Attitude);

};
