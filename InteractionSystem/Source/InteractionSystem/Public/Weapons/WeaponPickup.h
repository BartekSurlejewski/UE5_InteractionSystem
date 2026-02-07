// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/Pickup.h"
#include "WeaponPickup.generated.h"

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
	TSubclassOf<AWeapon> WeaponClass;

	// Weapon pickup class to spawn when throwing a weapon away
	UPROPERTY(EditAnywhere)
	TSubclassOf<AWeaponPickup> WeaponPickupClass;
};

UCLASS(Abstract)
class INTERACTIONSYSTEM_API AWeaponPickup : public APickup
{
	GENERATED_BODY()
	/** Weapon pickup mesh. Its mesh asset is set from the weapon data table */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Mesh;

protected:
	/** Data on the type of picked weapon and visuals of this pickup */
	UPROPERTY(EditAnywhere, Category="Pickup")
	FDataTableRowHandle WeaponType;
	/** Type to weapon to grant on pickup. Set from the weapon data table. */
	UPROPERTY(EditAnywhere, Category="Pickup")
	TSubclassOf<AWeapon> WeaponClass;
	/** Type to weapon to grant on pickup. Set from the weapon data table. */
	UPROPERTY(EditAnywhere, Category="Pickup")
	TSubclassOf<AWeaponPickup> WeaponPickupClass;

public:
	AWeaponPickup();

	UFUNCTION()
	virtual void OnPickup(AInteractionPrototypeCharacter* pickingCharacter) override;

protected:
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;
};
