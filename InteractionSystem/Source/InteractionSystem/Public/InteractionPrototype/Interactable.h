// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.generated.h"

class AInteractionPrototypeCharacter;

UINTERFACE(MinimalAPI)
class UInteractable : public UInterface
{
	GENERATED_BODY()
};

class INTERACTIONSYSTEM_API IInteractable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Interaction)
	void Interact(AInteractionPrototypeCharacter* Interactor);
	virtual FText GetInteractionPrompt() const = 0;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Interaction)
	void SetHighlighted(bool bHighlight);

	virtual void Interact_Implementation(AInteractionPrototypeCharacter* Interactor) = 0;
	virtual void SetHighlighted_Implementation(bool bHighlight) {};
};
