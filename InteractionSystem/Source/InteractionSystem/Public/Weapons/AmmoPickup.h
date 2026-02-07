// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/Pickup.h"
#include "AmmoPickup.generated.h"

/**
 * 
 */
UCLASS()
class INTERACTIONSYSTEM_API AAmmoPickup : public APickup
{
	GENERATED_BODY()

public:
	//~Begin IInteractable interface
	virtual void Interact(AInteractionPrototypeCharacter* Interactor) override;
	virtual FText GetInteractionPrompt() const override;
	//~End IInteractable interface
};
