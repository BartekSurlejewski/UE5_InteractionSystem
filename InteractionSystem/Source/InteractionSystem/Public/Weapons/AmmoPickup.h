// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "AmmoPickup.generated.h"

UCLASS()
class INTERACTIONSYSTEM_API AAmmoPickup : public AActor, public IInteractable
{
	GENERATED_BODY()

public:
	//~Begin IInteractable interface
	virtual void Interact_Implementation(AInteractionPrototypeCharacter* Interactor) override;
	virtual FText GetInteractionPrompt() const override;
	virtual void SetHighlighted_Implementation(bool bHighlight) override;
	//~End IInteractable interface
};
