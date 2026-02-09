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
#include "InteractionActorComponent.h"
#include "WeaponPickup.h"

AInteractionPrototypeCharacter::AInteractionPrototypeCharacter()
{
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 600.0f, 0.0f);

	InteractionComponent = CreateDefaultSubobject<UInteractionActorComponent>(TEXT("InteractionComponent"));
}

void AInteractionPrototypeCharacter::BeginPlay()
{
	Super::BeginPlay();

	OnWeaponEquipped.Broadcast(CurrentWeapon);
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

	InteractionComponent->SetInteractInputAction(InteractAction);
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
	OnBulletCountUpdated.Broadcast(CurrentAmmo, MagazineSize);
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
	// update the bullet counter
	OnWeaponEquipped.Broadcast(CurrentWeapon);
	OnBulletCountUpdated.Broadcast(Weapon->GetMagazineSize(), Weapon->GetBulletCount());

	GetFirstPersonMesh()->SetAnimInstanceClass(Weapon->GetFirstPersonAnimInstanceClass());
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
	if (!InteractionComponent)
	{
		return;
	}

	InteractionComponent->Interact();
}
