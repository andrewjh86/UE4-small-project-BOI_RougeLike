// Fill out your copyright notice in the Description page of Project Settings.


#include "Melee/ActionComponent.h"
#include "Action/ActionObject.h"
#include "Character/BaseCharacter.h"
#include "Items/InventoryComponent.h"


// Sets default values for this component's properties
UActionComponent::UActionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...

}


// Called when the game starts
void UActionComponent::BeginPlay()
{
	Super::BeginPlay();

	//Initialize objects for character:
	InitializeActionComponent();

}



void UActionComponent::StartPrimaryAction()
{
	PrimaryAction->ActionStart();
}

void UActionComponent::StopPrimaryAction()
{
	PrimaryAction->ActionStop();

}
void UActionComponent::EditPrimaryAction()
{
	PrimaryAction->ActionEdit();

}


void UActionComponent::InitializeActionComponent() {

	//character setup:
	if (ABaseCharacter* CurrentOwner = Cast<ABaseCharacter>(GetOwner())) {
		OwningBaseCharacter = CurrentOwner;
		EquiptedInvenotry = OwningBaseCharacter->GetInventoryComponent();
	}

	//Action setup:
	if (PrimaryActionClass) {
		//PrimaryAction = NewObject<UActionObject>(PrimaryActionClass);
				//PrimaryAction=CreateDefaultSubobject<UActionObject>(FName("NNN"),PrimaryActionClass);
		PrimaryAction = NewObject<UActionObject>(this, PrimaryActionClass);

		PrimaryAction->InitializeAction(this);

	}
}

