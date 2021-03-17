// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

#include "Tank.h"

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
    auto ControlledTank = GetControlledTank();
    if(!ControlledTank)
        return;

    FVector HitLocation;
    bool IsRayHitLocationSuccessful = GetSightRayHitLocation(HitLocation);
    if(IsRayHitLocationSuccessful)
    {
        ControlledTank->AimAt(HitLocation);
    }
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{

    // Find the crosshair position
    int32 ViewPortSizeX, ViewPortSizeY;
    GetViewportSize(ViewPortSizeX, ViewPortSizeY);
    FVector2D ScreenLocation{ ViewPortSizeX * CrosshairXLocation, ViewPortSizeY * CrosshairYLocation };

    // "De-project" the screen position of the crosshair to a world direction.
    FVector LookDirection{};
    bool IsGetLookDirectionSuccessful = GetLookDirection(ScreenLocation, LookDirection);
    if(IsGetLookDirectionSuccessful) {
        // Line-trace along that look direction, and see what we hit(up to max range)
        GetLookVectorHitLocation(LookDirection, OutHitLocation);
    }

    
    return IsGetLookDirectionSuccessful;
}

bool ATankPlayerController::GetLookVectorHitLocation(const FVector& LookDirection, FVector& OutHitLocation) const
{
    FHitResult HitResult;
    FVector StartLocation = PlayerCameraManager->GetCameraLocation();
    FVector End = StartLocation + LookDirection * LineTraceRange;

    bool IsHitFound = GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, End, ECC_Visibility);

    if(IsHitFound)
        OutHitLocation = HitResult.Location;
    else
        OutHitLocation = FVector(0);
    
    
    return IsHitFound;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
    FVector CameraWorldLocation{};
    bool IsDeprojectionSuccess = DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);

    return IsDeprojectionSuccess;
}

ATank* ATankPlayerController::GetControlledTank() const
{
    ATank* ControlledTank = Cast<::ATank>(GetPawn());

    return ControlledTank;
}
