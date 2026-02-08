// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InteractionOverlay.generated.h"

UCLASS()
class INTERACTIONSYSTEM_API UInteractionOverlay : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetInteractionText(const FText& NewInteractionText) const;
	void SetGunNameText(const FText& NewGunNameText) const;
	void SetAmmoCountText(const FText& NewAmmoCountText) const;
	void SetGunInfoVisibility(ESlateVisibility NewVisibility) const;

private:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* InteractionText;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* GunNameText;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* AmmoCountText;
};
