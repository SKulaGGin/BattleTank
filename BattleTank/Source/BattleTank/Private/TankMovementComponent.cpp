// Copyright Better Games


#include "TankMovementComponent.h"

#include "TankTrack.h"

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
    LeftTrack = LeftTrackToSet;
    RightTrack = RightTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
    FVector TankForwardDirection = GetOwner()->GetActorForwardVector().GetSafeNormal();
    FVector AIForwardIntention = MoveVelocity.GetSafeNormal();

    float ForwardThrow = FVector::DotProduct(TankForwardDirection, AIForwardIntention);
    auto RightThrow = FVector::CrossProduct(TankForwardDirection, AIForwardIntention).Z;

    IntendMoveForward(ForwardThrow);
    IntendTurnRight(RightThrow);
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
    if(!LeftTrack || !RightTrack)
        return;

    LeftTrack->SetThrottle(Throw);
    RightTrack->SetThrottle(Throw);
    // TODO prevent double speed due to dual control use
}


void UTankMovementComponent::IntendTurnRight(float Throw)
{
    if(!LeftTrack || !RightTrack)
        return;

    LeftTrack->SetThrottle(Throw);
    RightTrack->SetThrottle(-Throw);
    // TODO prevent double speed due to dual control use
}
