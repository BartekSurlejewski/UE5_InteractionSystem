// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractionSystemPlayerController.h"
#include "InteractionPrototypePC.generated.h"


UCLASS(Abstract)
class INTERACTIONSYSTEM_API AInteractionPrototypePC : public APlayerController
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Input|Input Mappings")
	TArray<UInputMappingContext*> DefaultMappingContexts;

protected:
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;
};
