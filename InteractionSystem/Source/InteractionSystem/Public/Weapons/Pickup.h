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
 *  Holds information about a type of weapon pickup
 */
USTRUCT(BlueprintType)
struct FWeaponTableRow : public FTableRowBase
{
	GENERATED_BODY()

	/** Mesh to display on the pickup */
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UStaticMesh> StaticMesh;

	/** Weapon class to grant on pickup */
	UPROPERTY(EditAnywhere)
	TSubclassOf<AWeapon> WeaponToSpawn;
};

/**
 *  Simple shooter game weapon pickup
 */
UCLASS(abstract)
class INTERACTIONSYSTEM_API APickup : public AActor
{
	GENERATED_BODY()

	/** Weapon pickup mesh. Its mesh asset is set from the weapon data table */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Mesh;

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

protected:
	/** Called when it's time to respawn this pickup */
	void RespawnPickup();

	/** Passes control to Blueprint to animate the pickup respawn. Should end by calling FinishRespawn */
	UFUNCTION(BlueprintImplementableEvent, Category="Pickup", meta = (DisplayName = "OnRespawn"))
	void BP_OnRespawn();

	/** Enables this pickup after respawning */
	UFUNCTION(BlueprintCallable, Category="Pickup")
	void FinishRespawn();
};
