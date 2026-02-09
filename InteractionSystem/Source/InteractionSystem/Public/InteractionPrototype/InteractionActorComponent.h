// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractionActorComponent.generated.h"

class UCameraComponent;
class UInputAction;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteractableLookedAt, AActor*, LookedAtActor);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class INTERACTIONSYSTEM_API UInteractionActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UInteractionActorComponent();

	FOnInteractableLookedAt OnInteractableLookedAt;

protected:
	virtual void BeginPlay() override;
	FKey GetKeyForInputAction(UInputAction* InputAction) const;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	AActor* GetLookAtInteractableActor() const;
	void Interact();

	FKey GetCurrentInteractKey() const;

	void SetInteractInputAction(UInputAction* NewInteractInputAction)
	{
		if (NewInteractInputAction != InteractInputAction)
		{
			InteractInputKey = GetKeyForInputAction(NewInteractInputAction);
		}

		InteractInputAction = NewInteractInputAction;
	}

private:
	UPROPERTY(EditAnywhere, Category ="Pickup", meta = (ClampMin = 0, ClampMax = 100000, Units = "cm"))
	float MaxInteractionDistance = 300.0f;

	UPROPERTY()
	UCameraComponent* CachedCamera;
	AActor* LookAtInteractableActor;
	UInputAction* InteractInputAction;
	FKey InteractInputKey;
};
