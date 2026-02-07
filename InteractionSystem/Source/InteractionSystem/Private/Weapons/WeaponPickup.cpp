#include "Weapons/WeaponPickup.h"

#include "InteractionPrototypeCharacter.h"
#include "WeaponHolder.h"
#include "Components/SphereComponent.h"

AWeaponPickup::AWeaponPickup()
{
	// subscribe to the collision overlap on the sphere
	SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &AWeaponPickup::OnOverlap);
}

void AWeaponPickup::OnPickup(AInteractionPrototypeCharacter* pickingCharacter)
{
	Super::OnPickup(pickingCharacter);

	pickingCharacter->AddWeaponClass(WeaponClass);

	// hide this mesh
	SetActorHiddenInGame(true);

	// disable collision
	SetActorEnableCollision(false);

	// disable ticking
	SetActorTickEnabled(false);

	// schedule the respawn
	GetWorld()->GetTimerManager().SetTimer(RespawnTimer, this, &AWeaponPickup::RespawnPickup, RespawnTime, false);
}

void AWeaponPickup::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                              const FHitResult& SweepResult)
{
	// have we collided against a weapon holder?
	if (AInteractionPrototypeCharacter* InteractionPrototypeCharacter = Cast<AInteractionPrototypeCharacter>(OtherActor))
	{
		OnPickup(InteractionPrototypeCharacter);
	}
}
