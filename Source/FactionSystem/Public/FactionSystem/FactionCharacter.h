// Copyright by amasson

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GenericTeamAgentInterface.h"
#include "FactionCharacter.generated.h"

UCLASS()
class FACTIONSYSTEM_API AFactionCharacter : public ACharacter, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:

	virtual FGenericTeamId GetGenericTeamId() const override;

protected:

	virtual void BeginPlay() override;

	/**
	 * FactionData asset that will override the controller faction.
	 */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Faction", meta = (AllowPrivateAccess = "true"))
    TObjectPtr<class UFactionData> FactionOverride;

};
