// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "InteractionPrototypeHUD.generated.h"

class UInteractionOverlay;

UCLASS()
class INTERACTIONSYSTEM_API AInteractionPrototypeHUD : public AHUD
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category = Interaction)
	TSubclassOf<UInteractionOverlay> OverlayClass;

	UInteractionOverlay* InteractionOverlay;

protected:
	virtual void BeginPlay() override;
};
