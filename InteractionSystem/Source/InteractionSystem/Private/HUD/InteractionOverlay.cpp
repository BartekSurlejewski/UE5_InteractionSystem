// Fill out your copyright notice in the Description page of Project Settings.

#include "HUD/InteractionOverlay.h"
#include "Components/TextBlock.h"

void UInteractionOverlay::SetInteractionText(const FText& NewInteractionText) const
{
	InteractionText->SetText(NewInteractionText);
}

void UInteractionOverlay::SetGunNameText(const FText& NewGunNameText) const
{
	GunNameText->SetText(NewGunNameText);
}

void UInteractionOverlay::SetAmmoCountText(const FText& NewAmmoCountText) const
{
	GunNameText->SetText(NewAmmoCountText);
}
