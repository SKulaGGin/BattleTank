// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

#include "Tank.h"

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("TankAIController Begin Play"));
    GetControlledTank();
}

ATank* ATankAIController::GetControlledTank()
{
    auto ControlledTank = Cast<ATank>(GetPawn());

    if(!ControlledTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("TankAIController not posessing a tank"));
        return nullptr;
    }

    auto TankName = ControlledTank->GetName();

    UE_LOG(LogTemp, Warning, TEXT("TankAIController posessing: %s"), *TankName);

    return ControlledTank;
}