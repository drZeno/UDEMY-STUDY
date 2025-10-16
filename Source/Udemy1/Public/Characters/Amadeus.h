// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/Character.h"
#include "CharactersType.h"
#include "Amadeus.generated.h"


class UInputAction;
class UInputMappingContext;
class UAnimInstance;
class UAnimMontage;
class UCameraComponent;
class USpringArmComponent;
class AItem;


UCLASS()
class UDEMY1_API AAmadeus : public ACharacter
{
	GENERATED_BODY()
public:
	// Sets default values for this character's properties
	AAmadeus(); // конструктор
	virtual void Tick(float DeltaTime) override; // метод класса
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Input")
	UInputMappingContext* BirdContext;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Input")
	UInputAction* FreeLook;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	UInputAction* JumpAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	UInputAction* Interact;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	UInputAction* MeleeAttack;
	
	void MoveRightForward(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void PickupItem(const FInputActionValue& Value);
	void MAttack(const FInputActionValue& Value);
	
	ECharacterState CharacterState = ECharacterState::ECS_Unequipped;
	
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm; // компонент класса 

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* ViewCamera;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Items")
	AItem* OverlappingItem;

//Animation Montages
	UPROPERTY(EditDefaultsOnly, Category="Montages")
	UAnimMontage* AttackMontage;
	
public:
	FORCEINLINE void SetOverlappingItem(AItem* Item) {OverlappingItem = Item;}
	FORCEINLINE ECharacterState GetCharacterState() const {return CharacterState;}
	

};
