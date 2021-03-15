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

ATank* ATankPlayerController::GetControlledTank() const
{
    ATank* ControlledTank = Cast<::ATank>(GetPawn());

    return ControlledTank;
}
