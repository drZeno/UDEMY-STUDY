// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/AmadeusAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Characters/Amadeus.h"
#include "Kismet/KismetMathLibrary.h"

void UAmadeusAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	AmadeusCharacter = Cast<AAmadeus>(TryGetPawnOwner());
	if (AmadeusCharacter)
	{
		AmadeusCharacterMovement = AmadeusCharacter->GetCharacterMovement();
	}
	
	
}

void UAmadeusAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if (AmadeusCharacterMovement)
	{
		
		GroundSpeed = UKismetMathLibrary::VSizeXY(AmadeusCharacterMovement->Velocity);
	}

	
}
