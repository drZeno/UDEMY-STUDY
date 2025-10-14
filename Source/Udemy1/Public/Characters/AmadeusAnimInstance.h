// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AmadeusAnimInstance.generated.h"

UCLASS()
class UDEMY1_API UAmadeusAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

	public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite)
	class AAmadeus* AmadeusCharacter;
	
	UPROPERTY(BlueprintReadWrite)
	class UCharacterMovementComponent* AmadeusCharacterMovement;

	UPROPERTY(BlueprintReadWrite, Category = Movement)
	float GroundSpeed;
	
};
