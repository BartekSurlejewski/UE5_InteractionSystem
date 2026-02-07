// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractionSystemCharacter.h"
#include "WeaponHolder.h"
#include "InteractionPrototypeCharacter.generated.h"

class APickup;
class AWeaponPickup;
class AWeapon;
class UInputAction;
class UInputComponent;

UCLASS()
class INTERACTIONSYSTEM_API AInteractionPrototypeCharacter : public AInteractionSystemCharacter, public IWeaponHolder
{
	GENERATED_BODY()

protected:
	/** Fire weapon input action */
	UPROPERTY(EditAnywhere, Category ="Input")
	UInputAction* FireAction;
	UPROPERTY(EditDefaultsOnly, Category ="Input")
	UInputAction* InteractAction;

	/** Name of the first person mesh weapon socket */
	UPROPERTY(EditAnywhere, Category ="Weapons")
	FName FirstPersonWeaponSocket = FName("HandGrip_R");
	/** Max distance to use for aim traces */
	UPROPERTY(EditAnywhere, Category ="Aim", meta = (ClampMin = 0, ClampMax = 100000, Units = "cm"))
	float MaxAimDistance = 10000.0f;

	UPROPERTY(EditAnywhere, Category ="Pickup", meta = (ClampMin = 0, ClampMax = 100000, Units = "cm"))
	float MaxPickupDistance = 300.0f;

	/** Weapon currently equipped and ready to shoot with */
	TObjectPtr<AWeapon> CurrentWeapon;

public:
	/** Constructor */
	AInteractionPrototypeCharacter();

protected:
	/** Gameplay initialization */
	virtual void BeginPlay() override;

	/** Gameplay cleanup */
	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;

	/** Set up input action bindings */
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

public:
	/** Handles start firing input */
	UFUNCTION(BlueprintCallable, Category="Input")
	void DoStartFiring();

	/** Handles stop firing input */
	UFUNCTION(BlueprintCallable, Category="Input")
	void DoStopFiring();

public:
	//~Begin IShooterWeaponHolder interface

	/** Attaches a weapon's meshes to the owner */
	virtual void AttachWeaponMeshes(AWeapon* Weapon) override;

	/** Plays the firing montage for the weapon */
	virtual void PlayFiringMontage(UAnimMontage* Montage) override;

	/** Applies weapon recoil to the owner */
	virtual void AddWeaponRecoil(float Recoil) override;

	/** Updates the weapon's HUD with the current ammo count */
	virtual void UpdateWeaponHUD(int32 CurrentAmmo, int32 MagazineSize) override;

	/** Calculates and returns the aim location for the weapon */
	virtual FVector GetWeaponTargetLocation() override;

	/** Gives a weapon of this class to the owner */
	virtual void PickupWeapon(const TSubclassOf<AWeapon>& WeaponClass, const FVector& PickupLocation) override;

	virtual void DropWeapon(const FVector& Location);

	/** Activates the passed weapon */
	virtual void OnWeaponActivated(AWeapon* Weapon) override;

	/** Deactivates the passed weapon */
	virtual void OnWeaponDeactivated(AWeapon* Weapon) override;

	/** Notifies the owner that the weapon cooldown has expired and it's ready to shoot again */
	virtual void OnSemiWeaponRefire() override;

	//~End IShooterWeaponHolder interface

protected:
	void DoInteract();
	APickup* GetLookAtPickup() const;
};
