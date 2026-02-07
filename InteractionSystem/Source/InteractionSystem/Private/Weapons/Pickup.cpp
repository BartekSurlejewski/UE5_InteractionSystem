// Copyright Epic Games, Inc. All Rights Reserved.


#include "Pickup.h"
#include "Components/SceneComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "WeaponHolder.h"
#include "Weapon.h"
#include "Engine/World.h"
#include "TimerManager.h"

APickup::APickup()
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
}

void APickup::Interact(AInteractionPrototypeCharacter* Interactor)
{
}

FText APickup::GetInteractionPrompt() const
{
	return FText();
}

void APickup::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
}

void APickup::BeginPlay()
{
	Super::BeginPlay();
}
