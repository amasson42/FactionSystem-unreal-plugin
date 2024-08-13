// Copyright by amasson

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GenericTeamAgentInterface.h"
#include "FactionDataInterface.h"
#include "FactionPlayerController.generated.h"

class UFactionData;

/**
 * 
 */
UCLASS()
class FACTIONSYSTEM_API AFactionPlayerController : public APlayerController, public IGenericTeamAgentInterface, public IFactionDataInterface
{
	GENERATED_BODY()
	
public:

    /** Faction System */

    virtual FGenericTeamId GetGenericTeamId() const override;
    virtual UFactionData* GetFactionData() const override { return Faction; }
    virtual void SetFactionData(UFactionData* FactionData) override;

protected:

    /** Faction System */

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Faction", meta = (AllowPrivateAccess = "true"))
    TObjectPtr<UFactionData> Faction;
};
