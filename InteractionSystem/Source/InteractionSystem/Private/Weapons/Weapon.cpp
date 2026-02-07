// Copyright Epic Games, Inc. All Rights Reserved.


#include "Weapon.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/World.h"
#include "Projectile.h"
#include "WeaponHolder.h"
#include "Components/SceneComponent.h"
#include "TimerManager.h"
#include "Animation/AnimInstance.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Pawn.h"

AWeapon::AWeapon()
{
	PrimaryActorTick.bCanEverTick = true;

	// create the root
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	// create the first person mesh
	FirstPersonMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("First Person Mesh"));
	FirstPersonMesh->SetupAttachment(RootComponent);

	FirstPersonMesh->SetCollisionProfileName(FName("NoCollision"));
	FirstPersonMesh->SetFirstPersonPrimitiveType(EFirstPersonPrimitiveType::FirstPerson);
	FirstPersonMesh->bOnlyOwnerSee = true;

	// create the third person mesh
	ThirdPersonMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Third Person Mesh"));
	ThirdPersonMesh->SetupAttachment(RootComponent);

	ThirdPersonMesh->SetCollisionProfileName(FName("NoCollision"));
	ThirdPersonMesh->SetFirstPersonPrimitiveType(EFirstPersonPrimitiveType::WorldSpaceRepresentation);
	ThirdPersonMesh->bOwnerNoSee = true;
}

void AWeapon::BeginPlay()
{
	Super::BeginPlay();

	// subscribe to the owner's destroyed delegate
	GetOwner()->OnDestroyed.AddDynamic(this, &AWeapon::OnOwnerDestroyed);

	// cast the weapon owner
	WeaponOwner = Cast<IWeaponHolder>(GetOwner());
	PawnOwner = Cast<APawn>(GetOwner());

	// fill the first ammo clip
	CurrentBullets = MagazineSize;

	// attach the meshes to the owner
	WeaponOwner->AttachWeaponMeshes(this);
}

void AWeapon::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	// clear the refire timer
	GetWorld()->GetTimerManager().ClearTimer(RefireTimer);
}

void AWeapon::OnOwnerDestroyed(AActor* DestroyedActor)
{
	// ensure this weapon is destroyed when the owner is destroyed
	Destroy();
}

void AWeapon::ActivateWeapon()
{
	// unhide this weapon
	SetActorHiddenInGame(false);

	// notify the owner
	WeaponOwner->OnWeaponActivated(this);
}

void AWeapon::DeactivateWeapon()
{
	// ensure we're no longer firing this weapon while deactivated
	StopFiring();

	// hide the weapon
	SetActorHiddenInGame(true);

	// notify the owner
	WeaponOwner->OnWeaponDeactivated(this);
}

void AWeapon::StartFiring()
{
	// raise the firing flag
	bIsFiring = true;

	// check how much time has passed since we last shot
	// this may be under the refire rate if the weapon shoots slow enough and the player is spamming the trigger
	const float TimeSinceLastShot = GetWorld()->GetTimeSeconds() - TimeOfLastShot;

	if (TimeSinceLastShot > RefireRate)
	{
		// fire the weapon right away
		Fire();
	}
	else
	{
		// if we're full auto, schedule the next shot
		if (bFullAuto)
		{
			GetWorld()->GetTimerManager().SetTimer(RefireTimer, this, &AWeapon::Fire, TimeSinceLastShot, false);
		}
	}
}

void AWeapon::StopFiring()
{
	// lower the firing flag
	bIsFiring = false;

	// clear the refire timer
	GetWorld()->GetTimerManager().ClearTimer(RefireTimer);
}

void AWeapon::ResupplyBullets()
{
	SetCurrentBullets(MagazineSize);
}

void AWeapon::Fire()
{
	// ensure the player still wants to fire. They may have let go of the trigger
	if (!bIsFiring)
	{
		return;
	}

	// fire a projectile at the target
	FireProjectile(WeaponOwner->GetWeaponTargetLocation());

	// update the time of our last shot
	TimeOfLastShot = GetWorld()->GetTimeSeconds();

	// make noise so the AI perception system can hear us
	MakeNoise(ShotLoudness, PawnOwner, PawnOwner->GetActorLocation(), ShotNoiseRange, ShotNoiseTag);

	// are we full auto?
	if (bFullAuto)
	{
		// schedule the next shot
		GetWorld()->GetTimerManager().SetTimer(RefireTimer, this, &AWeapon::Fire, RefireRate, false);
	}
	else
	{
		// for semi-auto weapons, schedule the cooldown notification
		GetWorld()->GetTimerManager().SetTimer(RefireTimer, this, &AWeapon::FireCooldownExpired, RefireRate, false);
	}
}

void AWeapon::FireCooldownExpired()
{
	// notify the owner
	WeaponOwner->OnSemiWeaponRefire();
}

void AWeapon::FireProjectile(const FVector& TargetLocation)
{
	// if the clip is depleted, we can't shoot
	if (CurrentBullets <= 0)
	{
		UE_LOG(LogTemp, Log, TEXT("Weapon magazine is empty"));
		return;
	}

	// get the projectile transform
	FTransform ProjectileTransform = CalculateProjectileSpawnTransform(TargetLocation);

	// spawn the projectile
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SpawnParams.TransformScaleMethod = ESpawnActorScaleMethod::OverrideRootScale;
	SpawnParams.Owner = GetOwner();
	SpawnParams.Instigator = PawnOwner;

	AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, ProjectileTransform, SpawnParams);

	// play the firing montage
	WeaponOwner->PlayFiringMontage(FiringMontage);

	// add recoil
	WeaponOwner->AddWeaponRecoil(FiringRecoil);

	// consume bullets
	SetCurrentBullets(CurrentBullets - 1);
}

FTransform AWeapon::CalculateProjectileSpawnTransform(const FVector& TargetLocation) const
{
	// find the muzzle location
	const FVector MuzzleLoc = FirstPersonMesh->GetSocketLocation(MuzzleSocketName);

	// calculate the spawn location ahead of the muzzle
	const FVector SpawnLoc = MuzzleLoc + ((TargetLocation - MuzzleLoc).GetSafeNormal() * MuzzleOffset);

	// find the aim rotation vector while applying some variance to the target 
	const FRotator AimRot = UKismetMathLibrary::FindLookAtRotation(SpawnLoc, TargetLocation + (UKismetMathLibrary::RandomUnitVector() * AimVariance));

	// return the built transform
	return FTransform(AimRot, SpawnLoc, FVector::OneVector);
}

void AWeapon::SetCurrentBullets(int newBulletsCount)
{
	CurrentBullets = FMath::Clamp(newBulletsCount, 0, MagazineSize);

	// update the weapon HUD
	WeaponOwner->UpdateWeaponHUD(CurrentBullets, MagazineSize);
}

const TSubclassOf<UAnimInstance>& AWeapon::GetFirstPersonAnimInstanceClass() const
{
	return FirstPersonAnimInstanceClass;
}

const TSubclassOf<UAnimInstance>& AWeapon::GetThirdPersonAnimInstanceClass() const
{
	return ThirdPersonAnimInstanceClass;
}
