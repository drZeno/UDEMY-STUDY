// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Amadeus.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Animation/AnimInstanceProxy.h"
#include "Animation/AnimMontage.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Items/Item.h"
#include "Weapons/Weapon.h"



// Sets default values
AAmadeus::AAmadeus()
{
	PrimaryActorTick.bCanEverTick = true;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent()); // important
	SpringArm->SocketOffset = FVector(-60, 0, 0); // можно сместить камеру в бок лево-право через Y
	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
	ViewCamera->SetupAttachment(SpringArm);
	SpringArm->TargetArmLength = 150.f;
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	
}

//Подключение игроку Subsystem для управления Enhanced Input
void AAmadeus::BeginPlay()
{
	Super::BeginPlay();
	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	if (PlayerController)
	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
		if (Subsystem)
		{
			Subsystem->AddMappingContext(BirdContext,0);
		}
	}
	
}
//Enhanced input action mapping кнопки
void AAmadeus::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAmadeus::MoveRightForward);
		EnhancedInputComponent->BindAction(FreeLook, ETriggerEvent::Triggered, this, &AAmadeus::Look);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &AAmadeus::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &AAmadeus::StopJumping);
		EnhancedInputComponent->BindAction(Interact, ETriggerEvent::Started, this, &AAmadeus::PickupItem);
		EnhancedInputComponent->BindAction(MeleeAttack, ETriggerEvent::Started, this, &AAmadeus::MAttack);
	}
}

// Получение Y X для управления пешкой 
void AAmadeus::MoveRightForward(const FInputActionValue& Value)
{
	auto MovementVector = Value.Get<FVector2D>();
	if (Controller)
	{
		AddMovementInput(GetActorForwardVector(), MovementVector.X);
		AddMovementInput(GetActorRightVector(), MovementVector.Y);
	}
}

// Смотреть мышкой
void AAmadeus::Look(const FInputActionValue& Value)
{
	auto LookAxisValue = Value.Get<FVector2D>();
	if (GetController())
	{
		AddControllerYawInput(LookAxisValue.X);
		AddControllerPitchInput(LookAxisValue.Y);
	}
}

//Поднятие предмета при нажатии E
void AAmadeus::PickupItem(const FInputActionValue& Value)
{
	AWeapon* OverlappingWeapon = Cast<AWeapon>(OverlappingItem);
	if (OverlappingWeapon)
	{
		OverlappingWeapon->Equip(GetMesh(), FName("RightHandSocket"));
		CharacterState = ECharacterState::ECS_EquippedOneHandedWeapon;
	}
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, TEXT("E Pressed!"));
	}
}

void AAmadeus::MAttack(const FInputActionValue& Value)
{
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	if (AnimInstance && AttackMontage)
	{
		AnimInstance->Montage_Play(AttackMontage);
		int32 Selection = FMath::RandRange(0, 1);
		FName SectionName = FName();
		switch (Selection)
		{
			case 0:
				SectionName = FName("Attack1");
				break;
			case 1:
			    SectionName = FName("Attack2");
				break;
			default:
				break;
		}
		AnimInstance->Montage_JumpToSection(SectionName, AttackMontage);
	}
}


void AAmadeus::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



