// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractionSystemPlayerController.h"
#include "InteractionPrototypePC.generated.h"

// class UShooterBulletCounterUI;

UCLASS(Abstract)
class INTERACTIONSYSTEM_API AInteractionPrototypePC : public APlayerController
{
	GENERATED_BODY()

protected:
	/** Input mapping contexts for this player */
	UPROPERTY(EditAnywhere, Category="Input|Input Mappings")
	TArray<UInputMappingContext*> DefaultMappingContexts;

protected:
	/** Gameplay Initialization */
	virtual void BeginPlay() override;

	/** Initialize input bindings */
	virtual void SetupInputComponent() override;
};
