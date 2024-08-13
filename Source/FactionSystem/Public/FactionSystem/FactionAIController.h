// Copyright by amasson

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GenericTeamAgentInterface.h"
#include "FactionDataInterface.h"
#include "FactionAIController.generated.h"

/**
 * 
 */
UCLASS()
class FACTIONSYSTEM_API AFactionAIController : public AAIController, public IFactionDataInterface
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
    TObjectPtr<class UFactionData> Faction;
};
