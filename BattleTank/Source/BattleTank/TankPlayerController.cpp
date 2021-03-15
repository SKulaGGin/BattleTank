// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
    ATank* ControlledTank = GetControlledTank();

    if(!ControlledTank)
        UE_LOG(LogTemp, Warning, TEXT("PlayerController not posessing a tank"));

    UE_LOG(LogTemp, Warning, TEXT("PlayerController posessing: %s"), *ControlledTank->GetName());
}

void ATankPlayerController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    AimTowardsCrosshair();
}



void ATankPlayerController::AimTowardsCrosshair()
{
    if(!GetControlledTank())
        return;

    
    FVector HitLocation;
    
    if(GetSightRayHitLocation(HitLocation))
    {
        UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
        
        
            // Tell controlled tank to aim at this point
    }

    
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
    // raycast through world where we aim with the crosshair
    
    // if we hit something, save hit location into the OutHitLocation out parameter and return true
    // if we don't hit something return false
    OutHitLocation = FVector(1.0);
    return true;
}

ATank* ATankPlayerController::GetControlledTank() const
{
    ATank* ControlledTank = Cast<::ATank>(GetPawn());

    return ControlledTank;
}
