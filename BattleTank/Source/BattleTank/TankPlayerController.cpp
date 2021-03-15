// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
    GetControlledTank();
}

ATank* ATankPlayerController::GetControlledTank() const
{
    auto ControlledTank = Cast<::ATank>(GetPawn());

    if(!ControlledTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("PlayerController not posessing a tank"));
        return nullptr;
    }

    auto TankName = ControlledTank->GetName();

    UE_LOG(LogTemp, Warning, TEXT("PlayerController posessing: %s"), *TankName);

    return ControlledTank;
}
