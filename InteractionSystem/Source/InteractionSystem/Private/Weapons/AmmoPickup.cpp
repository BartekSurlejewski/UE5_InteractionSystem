// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/AmmoPickup.h"

#include "InteractionPrototypeCharacter.h"
#include "Weapon.h"

void AAmmoPickup::Interact(AInteractionPrototypeCharacter* Interactor)
{
	Super::Interact(Interactor);

	if (AWeapon* weapon = Interactor->GetCurrentWeapon())
	{
		weapon->ResupplyBullets();
	}
}

FText AAmmoPickup::GetInteractionPrompt() const
{
	return FText::FromString("Resupply Ammo");
}
