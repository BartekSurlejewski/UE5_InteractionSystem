// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/InteractionPrototypeHUD.h"

#include "InteractionActorComponent.h"
#include "InteractionPrototypeCharacter.h"
#include "Weapon.h"
#include "Blueprint/UserWidget.h"
#include "HUD/InteractionOverlay.h"
#include "Kismet/GameplayStatics.h"

void AInteractionPrototypeHUD::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetWorld();
	if (World)
	{
		APlayerController* PlayerController = World->GetFirstPlayerController();

		if (PlayerController && OverlayClass)
		{
			InteractionOverlay = CreateWidget<UInteractionOverlay>(PlayerController, OverlayClass);
			InteractionOverlay->AddToViewport();
		}

		AInteractionPrototypeCharacter* PlayerCharacter = Cast<AInteractionPrototypeCharacter>(PlayerController->GetPawn());
		if (PlayerCharacter)
		{
			if (UInteractionActorComponent* InteractionComponent = PlayerCharacter->FindComponentByClass<UInteractionActorComponent>())
			{
				InteractionComponent->OnInteractableLookedAt.AddDynamic(this, &AInteractionPrototypeHUD::OnInteractableLookedAt);
			}
			PlayerCharacter->OnBulletCountUpdated.AddDynamic(this, &AInteractionPrototypeHUD::OnBulletCountChanged);
			PlayerCharacter->OnWeaponEquipped.AddDynamic(this, &AInteractionPrototypeHUD::OnWeaponEquipped);
		}
	}
}

void AInteractionPrototypeHUD::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (AInteractionPrototypeCharacter* PlayerCharacter = Cast<AInteractionPrototypeCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)))
	{
		if (UInteractionActorComponent* InteractionComponent = PlayerCharacter->FindComponentByClass<UInteractionActorComponent>())
		{
			InteractionComponent->OnInteractableLookedAt.RemoveDynamic(this, &AInteractionPrototypeHUD::OnInteractableLookedAt);
		}
		PlayerCharacter->OnBulletCountUpdated.RemoveDynamic(this, &AInteractionPrototypeHUD::OnBulletCountChanged);
		PlayerCharacter->OnWeaponEquipped.RemoveDynamic(this, &AInteractionPrototypeHUD::OnWeaponEquipped);
	}
}

void AInteractionPrototypeHUD::OnInteractableLookedAt(AActor* LookedAtActor)
{
	if (!LookedAtActor || !LookedAtActor->Implements<UInteractable>())
	{
		InteractionOverlay->SetInteractionText(FText::FromString(""));
		return;
	}

	IInteractable* InteractableActor = Cast<IInteractable>(LookedAtActor);
	if (InteractableActor)
	{
		InteractionOverlay->SetInteractionText(FText::Format(INVTEXT("[E] {0}"), InteractableActor->GetInteractionPrompt()));
	}
}

void AInteractionPrototypeHUD::OnBulletCountChanged(int CurrentAmmo, int MagazineSize)
{
	InteractionOverlay->SetAmmoCountText(FText::Format(FText::FromString("{0}/{1}"), CurrentAmmo, MagazineSize));
}

void AInteractionPrototypeHUD::OnWeaponEquipped(AWeapon* Weapon)
{
	if (!Weapon)
	{
		InteractionOverlay->SetGunInfoVisibility(ESlateVisibility::Hidden);
		return;
	}

	InteractionOverlay->SetGunInfoVisibility(ESlateVisibility::Visible);
	InteractionOverlay->SetGunNameText(Weapon->GetDisplayName());
}
