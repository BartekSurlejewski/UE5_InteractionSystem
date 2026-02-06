// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/InteractionPrototype/InteractionPrototypePC.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"

void AInteractionPrototypePC::BeginPlay()
{
	Super::BeginPlay();

	if (!IsLocalPlayerController())
	{
		return;
	}
}

void AInteractionPrototypePC::SetupInputComponent()
{
	Super::SetupInputComponent();

	UE_LOG(LogTemp, Warning, TEXT("PC SetupInputComponent called"));
	// only add IMCs for local player controllers
	if (IsLocalPlayerController())
	{
		UE_LOG(LogTemp, Warning, TEXT("Is Local Player Controller"));
		// add the input mapping contexts
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			UE_LOG(LogTemp, Warning, TEXT("Got Enhanced Input Subsystem"));
			for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
			{
				Subsystem->AddMappingContext(CurrentContext, 0);
				UE_LOG(LogTemp, Warning, TEXT("Added mapping context: %s"), *CurrentContext->GetName());
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to get Enhanced Input Subsystem!"));
		}
	}
}

void AInteractionPrototypePC::OnBulletCountUpdated(int32 MagazineSize, int32 Bullets)
{
	return;
}
