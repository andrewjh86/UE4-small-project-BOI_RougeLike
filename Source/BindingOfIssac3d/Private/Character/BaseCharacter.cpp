// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BaseCharacter.h"
#include "Components/StaticMeshComponent.h" 
#include "Components/CapsuleComponent.h"
#include "Engine/Engine.h" 


// Sets default values
ABaseCharacter::ABaseCharacter()
{
	//3d space:
	GetCapsuleComponent()->InitCapsuleSize(35.f, 96.0f);

	PrimaryActorTick.bCanEverTick = false;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	StaticMeshComponent->SetupAttachment(GetCapsuleComponent());
	StaticMeshComponent->SetGenerateOverlapEvents(false);
	StaticMeshComponent->SetSimulatePhysics(false);
	StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	//gameplay:
	AttributeComponent = CreateDefaultSubobject<UAttributeComponent>(TEXT("AttributeSet"));
	ActionComponent =CreateDefaultSubobject<UActionComponent>(TEXT("ActionComponent"));

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(2, 4.0f, FColor::Green, FString("CharacterPlay"));

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


UAttributeComponent* ABaseCharacter::GetAttributeComponent_Implementation()
{
	return AttributeComponent;
}

void ABaseCharacter::DebugCheckAssignVariables()
{
	
}

