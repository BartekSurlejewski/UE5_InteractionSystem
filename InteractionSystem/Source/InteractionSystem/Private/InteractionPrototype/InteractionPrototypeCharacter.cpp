// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionPrototype/InteractionPrototypeCharacter.h"

#include "Weapon.h"
#include "EnhancedInputComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/World.h"
#include "Camera/CameraComponent.h"
#include "TimerManager.h"
#include "WeaponPickup.h"

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

		//Interact
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &AInteractionPrototypeCharacter::DoInteract);
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

void AInteractionPrototypeCharacter::PickupWeapon(const TSubclassOf<AWeapon>& WeaponClass, const FVector& PickupLocation)
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
		// if we have an existing weapon, deactivate it
		if (CurrentWeapon)
		{
			DropWeapon(PickupLocation);
			CurrentWeapon->DeactivateWeapon();
		}

		// switch to the new weapon
		CurrentWeapon = AddedWeapon;
		CurrentWeapon->ActivateWeapon();
	}
}

void AInteractionPrototypeCharacter::DropWeapon(const FVector& Location)
{
	TSubclassOf<AWeaponPickup> WeaponPickupClass = CurrentWeapon->GetWeaponPickupClass();

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	FVector SpawnLocation = GetActorLocation() + GetActorForwardVector() * 200.0f;
	FRotator SpawnRotation = FRotator::ZeroRotator;

	AWeaponPickup* SpawnedWeaponPickup = GetWorld()->SpawnActor<AWeaponPickup>(WeaponPickupClass, Location, SpawnRotation, SpawnParams);
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

void AInteractionPrototypeCharacter::DoInteract()
{
	APickup* LookAtPickup = GetLookAtPickup();
	if (!LookAtPickup)
	{
		return;
	}

	LookAtPickup->OnPickup(this);
}

APickup* AInteractionPrototypeCharacter::GetLookAtPickup() const
{
	FHitResult HitResult;

	const FVector Start = GetFirstPersonCameraComponent()->GetComponentLocation();
	const FVector End = Start + (GetFirstPersonCameraComponent()->GetForwardVector() * MaxPickupDistance);

	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);

	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, QueryParams);

	// Draw debug line
	DrawDebugLine(
		GetWorld(),
		Start,
		End,
		bHit ? FColor::Green : FColor::Red, // Green if hit, red if no hit
		false, // Persistent lines
		-1.0f, // Lifetime (-1 = one frame)
		0, // Depth priority
		0.5f // Thickness
	);

	// Draw debug sphere at hit location
	if (bHit)
	{
		DrawDebugSphere(
			GetWorld(),
			HitResult.ImpactPoint,
			10.0f, // Radius
			12, // Segments
			FColor::Yellow,
			false,
			-1.0f
		);
	}

	if (bHit)
	{
		return Cast<APickup>(HitResult.GetActor());
	}

	return nullptr;
}
