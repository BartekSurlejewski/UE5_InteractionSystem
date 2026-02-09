#include "Weapons/WeaponPickup.h"

#include "InteractionPrototypeCharacter.h"
#include "Components/SphereComponent.h"

AWeaponPickup::AWeaponPickup()
{
	PrimaryActorTick.bCanEverTick = true;

	// create the root
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	// create the collision sphere
	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collision"));
	SphereCollision->SetupAttachment(RootComponent);

	SphereCollision->SetRelativeLocation(FVector(0.0f, 0.0f, 84.0f));
	SphereCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereCollision->SetCollisionObjectType(ECC_WorldStatic);
	SphereCollision->SetCollisionResponseToAllChannels(ECR_Ignore);
	SphereCollision->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	SphereCollision->bFillCollisionUnderneathForNavmesh = true;

	// create the mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(SphereCollision);

	Mesh->SetCollisionProfileName(FName("NoCollision"));
}

void AWeaponPickup::Interact_Implementation(AInteractionPrototypeCharacter* Interactor)
{
	Interactor->PickupWeapon(WeaponClass, GetActorLocation());

	// hide this mesh
	SetActorHiddenInGame(true);

	// disable collision
	SetActorEnableCollision(false);

	// disable ticking
	SetActorTickEnabled(false);
}

FText AWeaponPickup::GetInteractionPrompt() const
{
	return InteractPrompt;
}

void AWeaponPickup::SetHighlighted_Implementation(bool bHighlight)
{
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
		Mesh->SetStaticMesh(WeaponData->StaticMesh.LoadSynchronous());
		InteractPrompt = WeaponData->InteractPrompt;
		WeaponClass = WeaponData->WeaponClass;
		WeaponPickupClass = WeaponData->WeaponPickupClass;
	}
}
