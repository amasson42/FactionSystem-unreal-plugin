// Copyright by amasson

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "FactionDataInterface.generated.h"

class UFactionData;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UFactionDataInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FACTIONSYSTEM_API IFactionDataInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
    virtual UFactionData* GetFactionData() const { return nullptr; }
	virtual void SetFactionData(UFactionData* FactionData) {}

};
