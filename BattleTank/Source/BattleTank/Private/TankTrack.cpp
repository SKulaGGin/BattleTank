// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"

void UTankTrack::SetThrottle(float ThrottleToSet)
{
    Throttle = FMath::Clamp(ThrottleToSet, -1.0f, 1.0f);

    UE_LOG(LogTemp, Warning, TEXT("%s setting throttle value: %f"), *GetName(), Throttle);
}
