// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/InteractionPrototypeHUD.h"

#include "InteractionPrototypeCharacter.h"
#include "Blueprint/UserWidget.h"
#include "HUD/InteractionOverlay.h"

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
			// PlayerCharacter.
		}
	}
}
