// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
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
class INTERACTIONSYSTEM_API APickup : public AActor
{
	GENERATED_BODY()

protected:
	/** Collision sphere */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	USphereComponent* SphereCollision;

	/** Time to wait before respawning this pickup */
	UPROPERTY(EditAnywhere, Category="Pickup", meta = (ClampMin = 0, ClampMax = 120, Units = "s"))
	float RespawnTime = 4.0f;

	/** Timer to respawn the pickup */
	FTimerHandle RespawnTimer;

public:
	/** Constructor */
	APickup();

	virtual void OnPickup(AInteractionPrototypeCharacter* pickingCharacter);

protected:
	/** Native construction script */
	virtual void OnConstruction(const FTransform& Transform) override;

	/** Gameplay Initialization*/
	virtual void BeginPlay() override;

	/** Gameplay cleanup */
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
