// Fill out your copyright notice in the Description page of Project Settings.


#include "Melee/ActionComponent.h"
#include "Action/ActionObject.h"


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

}

void UActionComponent::StartPrimaryAction()
{
	PrimaryAction->ActionStart();
}

void UActionComponent::StopPrimaryAction()
{
	PrimaryAction->ActionStop();

}

bool UActionComponent::TryInitializeActionComponent() {
	if (PrimaryAction) {
		return true;
	}
	if (PrimaryActionClass) {
		PrimaryAction = NewObject<UActionObject>(PrimaryActionClass);

		if (PrimaryAction->TryInitializeAction(this)) {
			return true;
		}
	}
	return false;
}

bool UActionComponent::TrySwapActionObject() {

	return false;
}


//// Called every frame
//void UActionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
//	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//
//	// ...
//}

