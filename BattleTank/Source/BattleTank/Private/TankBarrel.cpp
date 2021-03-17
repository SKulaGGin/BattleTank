// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"
#include "GenericPlatform/GenericPlatformMath.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
    RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.0f, 1.0f);

    // Move the barrel the right amount this frame
    // Given a max elevation speed, and the frame time
    float ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;

    FRotator RelativeRotationLocal = GetRelativeRotation();

    RelativeRotationLocal.Pitch = FMath::Clamp(RelativeRotationLocal.Pitch + ElevationChange, MinElevationDegrees, MaxElevationDegrees);

    SetRelativeRotation(RelativeRotationLocal);
}
