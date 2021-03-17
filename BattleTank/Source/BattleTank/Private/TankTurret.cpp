// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
    RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.0f, 1.0f);

    float RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
    FRotator RelativeRotationLocal = GetRelativeRotation();

    RelativeRotationLocal.Yaw += RotationChange;
    SetRelativeRotation(RelativeRotationLocal);
}
