// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ShooterBulletCounterUI.h"
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

	/** Type of bullet counter UI widget to spawn */
	UPROPERTY(EditAnywhere, Category="Shooter|UI")
	TSubclassOf<UShooterBulletCounterUI> BulletCounterUIClass;

protected:
	/** Gameplay Initialization */
	virtual void BeginPlay() override;

	/** Initialize input bindings */
	virtual void SetupInputComponent() override;

	/** Called when the bullet count on the possessed pawn is updated */
	UFUNCTION()
	void OnBulletCountUpdated(int32 MagazineSize, int32 Bullets);
};
