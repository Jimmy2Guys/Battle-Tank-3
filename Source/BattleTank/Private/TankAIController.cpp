// Copyright 2017 JimmyTwoGuys.  All rights reserved. Unreal and Unreal Engine are registered tradmarks of Epic Games and are being used under theie EULA.

#include "TankAIController.h"
#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "GameFramework/Actor.h"
// Depends on movement component via pathfinding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }

	// Move towards the player
	MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius is in cm

											   // Aim towards the player
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	if (AimingComponent->GetFireingState() ==EFiringState::Locked)
	{
		AimingComponent->Fire(); //TODO limit Firing rate
	}

}


