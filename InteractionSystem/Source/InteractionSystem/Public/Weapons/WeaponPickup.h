// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/Pickup.h"
#include "WeaponPickup.generated.h"

UCLASS(Abstract)
class INTERACTIONSYSTEM_API AWeaponPickup : public APickup
{
	GENERATED_BODY()
protected:
	/** Data on the type of picked weapon and visuals of this pickup */
	UPROPERTY(EditAnywhere, Category="Pickup")
	FDataTableRowHandle WeaponType;
	/** Type to weapon to grant on pickup. Set from the weapon data table. */
	UPROPERTY(EditAnywhere, Category="Pickup")
	TSubclassOf<AWeapon> WeaponClass;
	
public:
	AWeaponPickup();
	
	UFUNCTION()
	virtual void OnPickup(AInteractionPrototypeCharacter* pickingCharacter) override;
protected:
	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
	               const FHitResult& SweepResult);
};
