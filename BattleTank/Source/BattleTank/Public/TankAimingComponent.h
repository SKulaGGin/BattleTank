// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UTankAimingComponent();

	// TODO add SetTurretReference

	void AimAt(FVector HitLocation, float LaunchSpeed);
	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);


private:
	UStaticMeshComponent* Barrel = nullptr;

	void MoveBarrel(FVector AimDirection);
};