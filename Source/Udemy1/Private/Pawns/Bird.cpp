// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/Bird.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
ABird::ABird()
{

	PrimaryActorTick.bCanEverTick = true;

	//CollisionThings
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->SetCapsuleHalfHeight(20.f);
	Capsule->SetCapsuleRadius(15.f);
	RootComponent = Capsule;


	//SocketAndMeshThings
	BirdMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BirdMesh"));
	BirdMesh->SetupAttachment(GetRootComponent());

	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));
	Movement->UpdatedComponent = RootComponent; // 

	//CameraThings
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(Capsule);// SetupAttachment(RootComponent) Same
	SpringArm->TargetArmLength = 150.f;
	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
	ViewCamera->SetupAttachment(SpringArm);
	ViewCamera->AddWorldRotation(FRotator(-40.f, 0, 0));
	ViewCamera->AddWorldOffset(FVector(50, 0, 200));

	//PlayerController
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	

	//BirdMesh->SetupAttachment(GetRootComponent());
	//BirdMesh->SetupAttachment(RootComponent); PublicFunction alternative way
	//SetRootComponent(Capsule); PublicFunction alternative way
}

void ABird::BeginPlay()
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

void ABird::Move(const FInputActionValue& Value)
{
	const float DirectionValue = Value.Get<float>();
	{
		if (Controller && (DirectionValue != 0.f))
		{
			FVector Forward = GetActorForwardVector();
			FVector Right = GetActorRightVector();
			AddMovementInput(Forward,DirectionValue);
			AddMovementInput(Right,DirectionValue);
		}
	}
}

void ABird::Look(const FInputActionValue& Value)
{
	auto LookAxisValue = Value.Get<FVector2D>();
	UE_LOG(LogTemp, Warning, TEXT("Look called: X=%f Y=%f"), LookAxisValue.X, LookAxisValue.Y);
	if (GetController())
	{
		AddControllerYawInput(LookAxisValue.X);
		AddControllerPitchInput(LookAxisValue.Y);
	}
}

void ABird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABird::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ABird::Move);
		EnhancedInputComponent->BindAction(FreeLook, ETriggerEvent::Triggered, this, &ABird::Look);
	}
}


