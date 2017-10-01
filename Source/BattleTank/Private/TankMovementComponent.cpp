// Copyright 2017 JimmyTwoGuys.  All rights reserved. Unreal and Unreal Engine are registered tradmarks of Epic Games and are being used under theie EULA.

#include "TankMovementComponent.h"
#include "TankTrack.h"
#include "Math/Vector.h"


void UTankMovementComponent::Initialize(UTankTrack *LeftTrackToSet, UTankTrack *RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveFoward(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!ensure(LeftTrack || RightTrack)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

//************************************
// Method:    RequestDirectMove
// FullName:  UTankMovementComponent::RequestDirectMove
// Access:    virtual public 
// Returns:   void
// Qualifier:
// Parameter: const FVector & MoveVelocity
// Parameter: bool bForceMaxSpeed
//************************************
void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	// No need to call Super as we are replacing the functionality

	auto TankFoward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AiFowardIntention = MoveVelocity.GetSafeNormal();

	float FowardThrow = (FVector::DotProduct(TankFoward, AiFowardIntention));
	IntendMoveFoward(FowardThrow);

	auto RightThrow = FVector::CrossProduct(TankFoward, AiFowardIntention).Z;
	
	IntendTurnRight(RightThrow);
}
