// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionPrototype/InteractionPrototypeCharacter.h"

#include "Weapon.h"
#include "EnhancedInputComponent.h"
#include "Components/InputComponent.h"
#include "Components/PawnNoiseEmitterComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/World.h"
#include "Camera/CameraComponent.h"
#include "TimerManager.h"

AInteractionPrototypeCharacter::AInteractionPrototypeCharacter()
{
	// configure movement
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 600.0f, 0.0f);
}

void AInteractionPrototypeCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AInteractionPrototypeCharacter::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void AInteractionPrototypeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Firing
		EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Started, this, &AInteractionPrototypeCharacter::DoStartFiring);
		EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Completed, this, &AInteractionPrototypeCharacter::DoStopFiring);

		// Switch weapon
		EnhancedInputComponent->BindAction(SwitchWeaponAction, ETriggerEvent::Triggered, this, &AInteractionPrototypeCharacter::DoSwitchWeapon);
	}
}

void AInteractionPrototypeCharacter::DoStartFiring()
{
	if (CurrentWeapon)
	{
		CurrentWeapon->StartFiring();
	}
}

void AInteractionPrototypeCharacter::DoStopFiring()
{
	if (CurrentWeapon)
	{
		CurrentWeapon->StopFiring();
	}
}

void AInteractionPrototypeCharacter::DoSwitchWeapon()
{
	if (OwnedWeapons.Num() > 1)
	{
		// deactivate the old weapon
		CurrentWeapon->DeactivateWeapon();

		// find the index of the current weapon in the owned list
		int32 WeaponIndex = OwnedWeapons.Find(CurrentWeapon);

		// is this the last weapon?
		if (WeaponIndex == OwnedWeapons.Num() - 1)
		{
			// loop back to the beginning of the array
			WeaponIndex = 0;
		}
		else
		{
			// select the next weapon index
			++WeaponIndex;
		}

		// set the new weapon as current
		CurrentWeapon = OwnedWeapons[WeaponIndex];

		// activate the new weapon
		CurrentWeapon->ActivateWeapon();
	}
}

void AInteractionPrototypeCharacter::AttachWeaponMeshes(AWeapon* Weapon)
{
	const FAttachmentTransformRules AttachmentRule(EAttachmentRule::SnapToTarget, false);

	// attach the weapon actor
	Weapon->AttachToActor(this, AttachmentRule);

	// attach the weapon meshes
	Weapon->GetFirstPersonMesh()->AttachToComponent(GetFirstPersonMesh(), AttachmentRule, FirstPersonWeaponSocket);
	Weapon->GetThirdPersonMesh()->AttachToComponent(GetMesh(), AttachmentRule, FirstPersonWeaponSocket);
}

void AInteractionPrototypeCharacter::PlayFiringMontage(UAnimMontage* Montage)
{
}

void AInteractionPrototypeCharacter::AddWeaponRecoil(float Recoil)
{
	// apply the recoil as pitch input
	AddControllerPitchInput(Recoil);
}

void AInteractionPrototypeCharacter::UpdateWeaponHUD(int32 CurrentAmmo, int32 MagazineSize)
{
	// OnBulletCountUpdated.Broadcast(MagazineSize, CurrentAmmo);
}

FVector AInteractionPrototypeCharacter::GetWeaponTargetLocation()
{
	// trace ahead from the camera viewpoint
	FHitResult OutHit;

	const FVector Start = GetFirstPersonCameraComponent()->GetComponentLocation();
	const FVector End = Start + (GetFirstPersonCameraComponent()->GetForwardVector() * MaxAimDistance);

	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);

	GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_Visibility, QueryParams);

	// return either the impact point or the trace end
	return OutHit.bBlockingHit ? OutHit.ImpactPoint : OutHit.TraceEnd;
}

void AInteractionPrototypeCharacter::AddWeaponClass(const TSubclassOf<AWeapon>& WeaponClass)
{
	// do we already own this weapon?
	AWeapon* OwnedWeapon = FindWeaponOfType(WeaponClass);

	if (!OwnedWeapon)
	{
		// spawn the new weapon
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = this;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		SpawnParams.TransformScaleMethod = ESpawnActorScaleMethod::MultiplyWithRoot;

		AWeapon* AddedWeapon = GetWorld()->SpawnActor<AWeapon>(WeaponClass, GetActorTransform(), SpawnParams);

		if (AddedWeapon)
		{
			// add the weapon to the owned list
			OwnedWeapons.Add(AddedWeapon);

			// if we have an existing weapon, deactivate it
			if (CurrentWeapon)
			{
				CurrentWeapon->DeactivateWeapon();
			}

			// switch to the new weapon
			CurrentWeapon = AddedWeapon;
			CurrentWeapon->ActivateWeapon();
		}
	}
}

void AInteractionPrototypeCharacter::OnWeaponActivated(AWeapon* Weapon)
{
	// TODO: Add the OnBulletCountUpdated delegate
	// update the bullet counter
	// OnBulletCountUpdated.Broadcast(Weapon->GetMagazineSize(), Weapon->GetBulletCount());

	// set the character mesh AnimInstances
	GetFirstPersonMesh()->SetAnimInstanceClass(Weapon->GetFirstPersonAnimInstanceClass());
	// GetMesh()->SetAnimInstanceClass(Weapon->GetThirdPersonAnimInstanceClass());
}

void AInteractionPrototypeCharacter::OnWeaponDeactivated(AWeapon* Weapon)
{
	// unused
}

void AInteractionPrototypeCharacter::OnSemiWeaponRefire()
{
	// unused
}

AWeapon* AInteractionPrototypeCharacter::FindWeaponOfType(TSubclassOf<AWeapon> WeaponClass) const
{
	// check each owned weapon
	for (AWeapon* Weapon : OwnedWeapons)
	{
		if (Weapon->IsA(WeaponClass))
		{
			return Weapon;
		}
	}

	// weapon not found
	return nullptr;
}
