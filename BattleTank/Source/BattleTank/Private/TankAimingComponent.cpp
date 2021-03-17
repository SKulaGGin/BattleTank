// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"


#include "TankBarrel.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true; // TODO Should this really tick?
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if(!Barrel)
		return;

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

    bool HaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
        this,
        OutLaunchVelocity,
        StartLocation,
        HitLocation,
        LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
    );
	if(HaveAimSolution)
	{
		FVector AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f aim solution found %s"), Time, *AimDirection.ToString());
	}
	else
	{
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f aim solution not found"), Time);
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	if(!Barrel)
		return;

	// Work-out difference between current barrel rotation and AimDirection
    FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->Elevate(5);
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

