// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionPrototype/InteractionActorComponent.h"

#include "Interactable.h"
#include "InteractionPrototypeCharacter.h"
#include "GameFramework/Character.h"

// Sets default values for this component's properties
UInteractionActorComponent::UInteractionActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInteractionActorComponent::BeginPlay()
{
	Super::BeginPlay();

	if (ACharacter* OwnerCharacter = Cast<ACharacter>(GetOwner()))
	{
		CachedCamera = OwnerCharacter->FindComponentByClass<UCameraComponent>();

		if (!CachedCamera)
		{
			UE_LOG(LogTemp, Warning, TEXT("[Interaction Component] No camera found on %s"), *OwnerCharacter->GetName());
		}
	}

	OnInteractableLookedAt.Broadcast(LookAtInteractableActor);
}


// Called every frame
void UInteractionActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor* NewLookAtInteractableActor = GetLookAtInteractableActor();

	if (NewLookAtInteractableActor != LookAtInteractableActor)
	{
		if (LookAtInteractableActor)
		{
			IInteractable::Execute_SetHighlighted(Cast<UObject>(LookAtInteractableActor), false);
		}

		if (NewLookAtInteractableActor)
		{
			IInteractable::Execute_SetHighlighted(Cast<UObject>(NewLookAtInteractableActor), true);
		}

		LookAtInteractableActor = NewLookAtInteractableActor;
		OnInteractableLookedAt.Broadcast(Cast<AActor>(LookAtInteractableActor));
	}
}

AActor* UInteractionActorComponent::GetLookAtInteractableActor() const
{
	FHitResult HitResult;

	const FVector Start = CachedCamera->GetComponentLocation();
	const FVector End = Start + CachedCamera->GetForwardVector() * MaxInteractionDistance;

	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(GetOwner());

	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, QueryParams);

	if (bHit)
	{
		AActor* HitActor = HitResult.GetActor();
		if (HitActor && HitActor->Implements<UInteractable>())
		{
			return HitActor;
		}
	}

	return nullptr;
}

void UInteractionActorComponent::Interact()
{
	if (!LookAtInteractableActor)
	{
		return;
	}

	IInteractable* LookAtInteractable = Cast<IInteractable>(LookAtInteractableActor);
	if (!LookAtInteractable)
	{
		return;
	}

	IInteractable::Execute_Interact(Cast<UObject>(LookAtInteractable), Cast<AInteractionPrototypeCharacter>(GetOwner()));
}
