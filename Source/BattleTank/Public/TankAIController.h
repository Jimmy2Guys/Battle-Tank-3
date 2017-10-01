// Copyright 2017 JimmyTwoGuys.  All rights reserved. Unreal and Unreal Engine are registered tradmarks of Epic Games and are being used under theie EULA.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GameFramework/Actor.h"
#include "TankAIController.generated.h"

/**
 * 
 */

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController

{
	GENERATED_BODY()

private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
	// How close the AI tank can get
	float AcceptanceRadius = 6000;  // TODO Set a good Default

	
};
