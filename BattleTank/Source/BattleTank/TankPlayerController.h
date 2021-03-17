// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
     ATank* GetControlledTank() const;

    virtual void BeginPlay() override;
    virtual void Tick(float DeltaSeconds) override;
    UPROPERTY(EditAnywhere);
    float CrosshairXLocation = 0.5;
    UPROPERTY(EditAnywhere);
    float CrosshairYLocation = 0.3333;
private:
    void AimTowardsCrosshair();
    // Return an OUT parameter, true if hit landscape
    bool GetSightRayHitLocation(FVector& OutHitLocation) const;

    UPROPERTY(EditAnywhere)
    float LineTraceRange = 1000000; // 10km

    bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
    bool GetLookVectorHitLocation(const FVector& LookDirection, FVector& OutHitLocation) const;
};
