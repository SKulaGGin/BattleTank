// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

#include "Tank.h"
#include "BattleTank/TankPlayerController.h"

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
    ATank* ControlledTank = Cast<ATank>(GetPawn());
    if(PlayerTank)
    {
        ControlledTank->AimAt(PlayerTank->GetActorLocation());
        ControlledTank->Fire(); // TODO limit firing rate
    }
}
