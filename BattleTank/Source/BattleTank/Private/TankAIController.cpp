// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

#include "Tank.h"
#include "BattleTank/TankPlayerController.h"

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();

    ATank* PlayerTank = GetPlayerTank();

    if(!PlayerTank)
        UE_LOG(LogTemp, Warning, TEXT("TankAIController can't find player tank."));

    UE_LOG(LogTemp, Warning, TEXT("TankAIController found player's tank: %s"), *PlayerTank->GetName());
}

ATank* ATankAIController::GetControlledTank() const
{
    auto ControlledTank = Cast<ATank>(GetPawn());

    return ControlledTank;
}

ATank* ATankAIController::GetPlayerTank() const
{
    auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

    return Cast<ATank>(PlayerPawn);
}

void ATankAIController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    AimAtFirstPlayer();
}

void ATankAIController::AimAtFirstPlayer()
{
    ATank* ControlledTank = GetControlledTank();
    FVector PlayerLocation = GetPlayerTank()->GetActorLocation();
    ControlledTank->AimAt(PlayerLocation);
}
