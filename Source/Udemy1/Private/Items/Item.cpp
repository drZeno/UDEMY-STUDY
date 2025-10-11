// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"
#include "Udemy1/DebugAura.h"



AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;

}
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float MovementRate = 500.f;
	float RotationRate = 45.f;

	// if you want spin arround your-self
	//AddActorLocalOffset(FVector(MovementRate * DeltaTime, 0, 0));
	//AddActorLocalRotation(FRotator(0, RotationRate * DeltaTime, 0));


	//if you want move forward and spin by yourself.
	AddActorWorldOffset(FVector(0, RotationRate * DeltaTime, 0));
	AddActorWorldRotation(FRotator(0, RotationRate * DeltaTime, 0));
	DRAW_SPHERE_SigleFrame(GetActorLocation());
	DRAW_VECTOR_SigleFrame(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 1000.f)
}

