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

	RunningTime += DeltaTime;

	float DeltaZ = Amplitude * FMath::Sin(RunningTime * TimeConstant);
	AddActorWorldOffset(FVector(0.f,0.f,DeltaZ));
	
	DRAW_SPHERE_SigleFrame(GetActorLocation());
	DRAW_VECTOR_SigleFrame(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 1000.f)
}

