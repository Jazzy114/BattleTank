// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Turret.h"

void UTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange; // Rotation isn't clamped because the turret goes all the way around
	SetRelativeRotation(FRotator(0, Rotation, 0)); // Yaw value = Rotation
}