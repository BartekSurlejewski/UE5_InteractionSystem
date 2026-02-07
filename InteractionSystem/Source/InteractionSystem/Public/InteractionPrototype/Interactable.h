// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.generated.h"

class AInteractionPrototypeCharacter;
/**
 * 
 */
UINTERFACE(MinimalAPI)
class UInteractable : public UInterface
{
	GENERATED_BODY()
};

class INTERACTIONSYSTEM_API IInteractable
{
	GENERATED_BODY()

public:
	virtual void Interact(AInteractionPrototypeCharacter* Interactor) = 0;
	virtual FText GetInteractionPrompt() const = 0;
};
