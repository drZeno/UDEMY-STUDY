// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class UDEMY1_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AItem();
	
	virtual void Tick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Sine Parameters");
	float Amplitude = 5.f;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Sine Parameters");
	float TimeConstant = 5.f;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Sine Parameters");
	float XSpeed = 50.f;

	UFUNCTION(BlueprintPure)
	float TransformedSin();

	UFUNCTION(BlueprintPure)
	float TransformedCos();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"));
	float RunningTime;

	UPROPERTY(VisibleAnywhere);
	UStaticMeshComponent* ItemMesh;
};


