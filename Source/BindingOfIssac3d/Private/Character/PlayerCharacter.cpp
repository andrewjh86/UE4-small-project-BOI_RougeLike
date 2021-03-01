// Copyright Epic Games, Inc. All Rights Reserved.


#include "Character/PlayerCharacter.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "Kismet/GameplayStatics.h"

//universal character includes:
#include "Attribute/AttributeComponent.h"
#include "Melee/ActionComponent.h"
#include "Items/InventoryComponent.h"

APlayerCharacter::APlayerCharacter()
{
	//actor:
	PrimaryActorTick.bCanEverTick = false;

	//Player only:	
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->bUsePawnControlRotation = true;
	SpringArmComp->SetupAttachment(RootComponent);
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(SpringArmComp);
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	//gameplay:

}

void APlayerCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();


}

void APlayerCharacter::DeathHandle() {
	Super::DeathHandle();
	UE_LOG(LogTemp, Warning, TEXT("Player Death"));
}



//////////////////////////////////////////////////////////////////////////
// Input:
// Hit_LMB  Hit1_FK  Interact_EK  Interact1_RK  Aim_RMB  Boost_Space  Run_LShift  Menu_Tab  Map_MK  Pause_PK 

void APlayerCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	check(PlayerInputComponent);

	// Bind jump events
	PlayerInputComponent->BindAction("Boost_Space", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Boost_Space", IE_Released, this, &ACharacter::StopJumping);

	//if (ActionComponent) {
	//	UE_LOG(LogTemp, Warning, TEXT("SetupPlayerInputComponent_ActionComponent"));

	//	if (ActionComponent->TryInitializeActionComponent()) {
	PlayerInputComponent->BindAction("Hit_LMB", IE_Pressed, ActionComponent, &UActionComponent::StartPrimaryAction);
	PlayerInputComponent->BindAction("Hit_LMB", IE_Released, ActionComponent, &UActionComponent::StopPrimaryAction);;
	PlayerInputComponent->BindAction("Interact1_RK", IE_Pressed, ActionComponent, &UActionComponent::EditPrimaryAction);

	//	}
	//}

	//Move:
	// Bind movement events
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);

	//Look Around:
	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &APlayerCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &APlayerCharacter::LookUpAtRate);

	//Debug:
	//PlayerInputComponent->BindAction("Hit1_FK", IE_Pressed, this, &APlayerCharacter::DebugInteract);

}

void APlayerCharacter::DebugInteract() {
	//GEngine->AddOnScreenDebugMessage(2, 4.0f, FColor::Green, FString("Interact"));

}


void APlayerCharacter::MoveForward(float Value)
{

	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void APlayerCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void APlayerCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void APlayerCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}






