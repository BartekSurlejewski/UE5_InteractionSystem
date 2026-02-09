// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractionSystemCharacter.h"
#include "WeaponHolder.h"
#include "InteractionPrototypeCharacter.generated.h"

class UInteractionActorComponent;
class IInteractable;
class APickup;
class AWeaponPickup;
class AWeapon;
class UInputAction;
class UInputComponent;

// Note: For production, consider using GAS Attribute Sets or MVVM for better scalability
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBulletCountUpdated, int32, CurrentAmmo, int32, MagazineSize);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWeaponEquipped, AWeapon*, CurrentWeapon);

UCLASS()
class INTERACTIONSYSTEM_API AInteractionPrototypeCharacter : public AInteractionSystemCharacter, public IWeaponHolder
{
	GENERATED_BODY()

public:
	FOnBulletCountUpdated OnBulletCountUpdated;
	FOnWeaponEquipped OnWeaponEquipped;

protected:
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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Components)
	UInteractionActorComponent* InteractionComponent;

	/** Weapon currently equipped and ready to shoot with */
	TObjectPtr<AWeapon> CurrentWeapon;

public:
	AInteractionPrototypeCharacter();

	const TObjectPtr<AWeapon>& GetCurrentWeapon() const
	{
		return CurrentWeapon;
	}

protected:
	virtual void BeginPlay() override;

	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

public:
	UFUNCTION(BlueprintCallable, Category="Input")
	void DoStartFiring();

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
	IInteractable* GetLookAtInteractable() const;
};
