// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/AmmoPickup.h"

#include "InteractionPrototypeCharacter.h"
#include "Weapon.h"

void AAmmoPickup::Interact_Implementation(AInteractionPrototypeCharacter* Interactor)
{
	if (AWeapon* weapon = Interactor->GetCurrentWeapon())
	{
		weapon->ResupplyBullets();
	}
}

FText AAmmoPickup::GetInteractionPrompt() const
{
	return FText::FromString("Resupply Ammo");
}

void AAmmoPickup::SetHighlighted_Implementation(bool bHighlight)
{
	IInteractable::SetHighlighted_Implementation(bHighlight);
}
