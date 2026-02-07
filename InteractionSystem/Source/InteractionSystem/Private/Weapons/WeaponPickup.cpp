#include "Weapons/WeaponPickup.h"

#include "InteractionPrototypeCharacter.h"
#include "Components/SphereComponent.h"

AWeaponPickup::AWeaponPickup()
{
	// create the mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(SphereCollision);

	Mesh->SetCollisionProfileName(FName("NoCollision"));
}

void AWeaponPickup::OnPickup(AInteractionPrototypeCharacter* pickingCharacter)
{
	Super::OnPickup(pickingCharacter);

	pickingCharacter->PickupWeapon(WeaponClass, GetActorLocation());

	// hide this mesh
	SetActorHiddenInGame(true);

	// disable collision
	SetActorEnableCollision(false);

	// disable ticking
	SetActorTickEnabled(false);
}

void AWeaponPickup::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	if (FWeaponTableRow* WeaponData = WeaponType.GetRow<FWeaponTableRow>(FString()))
	{
		// set the mesh
		Mesh->SetStaticMesh(WeaponData->StaticMesh.LoadSynchronous());
	}
}

void AWeaponPickup::BeginPlay()
{
	Super::BeginPlay();

	if (FWeaponTableRow* WeaponData = WeaponType.GetRow<FWeaponTableRow>(FString()))
	{
		// copy the weapon class
		WeaponClass = WeaponData->WeaponClass;
	}
}
