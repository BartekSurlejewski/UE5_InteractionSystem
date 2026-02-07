// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "Engine/StaticMesh.h"
#include "Pickup.generated.h"

class AInteractionPrototypeCharacter;
class USphereComponent;
class UPrimitiveComponent;
class AWeapon;

/**
 *  Simple shooter game weapon pickup
 */
UCLASS(abstract)
class INTERACTIONSYSTEM_API APickup : public AActor, public IInteractable
{
private:
	GENERATED_BODY()

protected:
	/** Collision sphere */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	USphereComponent* SphereCollision;

public:
	/** Constructor */
	APickup();
	
	virtual void Interact(AInteractionPrototypeCharacter* Interactor) override;
	virtual FText GetInteractionPrompt() const override;

protected:
	/** Native construction script */
	virtual void OnConstruction(const FTransform& Transform) override;

	/** Gameplay Initialization*/
	virtual void BeginPlay() override;
};
