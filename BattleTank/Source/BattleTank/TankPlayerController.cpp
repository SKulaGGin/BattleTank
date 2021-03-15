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
        // UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *HitLocation.ToString());
        // Tell controlled tank to aim at this point
    }

    
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
    // Find the crosshair position
    // "De-project" the screen position of the crosshair to a world direction.
    // Line-trace along that look direction, and see what we hit(up to max range)

    int32 ViewPortSizeX, ViewPortSizeY;
    GetViewportSize(ViewPortSizeX, ViewPortSizeY);

    FVector2D ScreenLocation{ ViewPortSizeX * CrosshairXLocation, ViewPortSizeY * CrosshairYLocation };

    UE_LOG(LogTemp, Warning, TEXT("Screen location: %s"), *ScreenLocation.ToString());

    OutHitLocation = FVector(1.0);
    return true;
}

ATank* ATankPlayerController::GetControlledTank() const
{
    ATank* ControlledTank = Cast<::ATank>(GetPawn());

    return ControlledTank;
}
