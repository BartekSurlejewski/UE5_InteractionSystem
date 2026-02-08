// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "GameFramework/HUD.h"
#include "InteractionPrototypeHUD.generated.h"

class AWeapon;
class UInteractionOverlay;

UCLASS()
class INTERACTIONSYSTEM_API AInteractionPrototypeHUD : public AHUD
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category = Interaction)
	TSubclassOf<UInteractionOverlay> OverlayClass;

	UInteractionOverlay* InteractionOverlay;
	FDelegateHandle InteractableLookedAtDelegateHandle;

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UFUNCTION()
	void OnInteractableLookedAt(AActor* LookedAtActor);
	UFUNCTION()
	void OnBulletCountChanged(int CurrentAmmo, int MagazineSize);
	UFUNCTION()
	void OnWeaponEquipped(AWeapon* Weapon);
};
