// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "Projectile.h"

#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "TankBarrel.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::Fire()
{
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	if(Barrel && isReloaded)
	{
	    AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(
		    ProjectileBlueprint,
		    Barrel->GetSocketLocation("Projectile"),
		    Barrel->GetSocketRotation("Projectile")
		    );

	    Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}



