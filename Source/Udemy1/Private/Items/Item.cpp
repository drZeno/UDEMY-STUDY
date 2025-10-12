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

float AItem::TransformedSin()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float AItem::TransformedCos()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;

	//float DeltaZ = Amplitude * FMath::Sin(RunningTime * TimeConstant);
	AddActorWorldOffset(FVector(RunningTime,TransformedCos(),TransformedSin()));
	
	DRAW_SPHERE_SingleFrame(GetActorLocation());
	DRAW_VECTOR_SigleFrame(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 1000.f)
}

