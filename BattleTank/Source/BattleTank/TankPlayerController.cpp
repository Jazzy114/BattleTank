// Fill out your copyright notice in the Description page of Project Settings.

#define OUT
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if(!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerController does not possess a tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController is possessing: %s."), *(ControlledTank->GetName()));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}


ATank* ATankPlayerController::GetControlledTank() const // Const means nothing about the state of class changes

{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // Out parameter
	if (GetSightRayHitLocation(HitLocation)) // Has "side-effect", is going to line trace
	{
		// UE_LOG(LogTemp, Warning, TEXT("Look direction: %s."), *HitLocation.ToString()) // . instead of -> or * because HitLocation() is a variable/member, not pointer
		// TODO Tell controlled tank to aim at this point
	}
}

// Get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s"), *ScreenLocation.ToString());

	// "De-project" the screen position of the crosshair tto a world direction
	// Line-trace along that look direction and see what we hit (up to max range)
	return true;
}


