// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponing.generated.h"

class UTankBarrel; // Forward declaration

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankAimingComponing : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UTankAimingComponing();

	void SetBarrelReference(UTankBarrel* BarrelToSet);

public:
	void AimAt(FVector HitLocation, float LaunchSpeed);

	void MoveBarell(FVector AimDirection);

private:
	UTankBarrel* Barrel = nullptr;
};
