// Copyright 2017 JimmyTwoGuys.  All rights reserved. Unreal and Unreal Engine are registered tradmarks of Epic Games and are being used under theie EULA.

#pragma once

#include "BattleTank.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent)) 
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downward speed, +1 is max upward speed
	void Elevate(float RelativeSpeed);
	
	private:
	UPROPERTY(EditAnywhere, Category = "Setup")
		float MaxDegreesPerSecond = 7.5; // Starting default

	UPROPERTY(EditAnywhere, Category = "Setup")
		float MaxElevationDegrees = 40; // Starting default
	
	UPROPERTY(EditAnywhere, Category = "Setup")
		float MinElevationDegrees = -1; // Starting default

};
