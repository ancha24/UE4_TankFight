// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "TankAimingComponing.h"

UTankAimingComponing::UTankAimingComponing()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankAimingComponing::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponing::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel)
	{
		return;
	}

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, HitLocation, LaunchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace);

	if (bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		auto TankName = GetOwner()->GetName();

		MoveBarell(AimDirection);
		//UE_LOG(LogTemp, Warning, TEXT("Aiming at %s"), *TankName, *AimDirection.ToString());
	}
}

void UTankAimingComponing::MoveBarell(FVector AimDirection)
{
	/*auto BarrelRotation = Barrel->GetForwardVector().Rotation;
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotation;*/

	//UE_LOG(LogTemp, Warning, TEXT("Aiming as rotator : %s"), *AimAsRotator.ToString());

	Barrel->Elevate(5);
}

