// Fill out your copyright notice in the Description page of Project Settings.


#include "Action/ActionObject.h"
#include "Components/ActorComponent.h"


void UActionObject::ActionImplementation()
{
	UE_LOG(LogTemp, Warning, TEXT("Action called on base class"));
}

void UActionObject::ActionStart() 
{
	UE_LOG(LogTemp, Warning, TEXT("Actionstart called on base class"));
}

void UActionObject::ActionStop()
{
	UE_LOG(LogTemp, Warning, TEXT("ActionStop called on base class"));
	
}

void UActionObject::InitializeAction(UActionComponent* _OwningActionComponent)
{
	OwningActionComponent = _OwningActionComponent;
	UE_LOG(LogTemp, Warning, TEXT("Ititialize Base"));

}

void UActionObject::UninitializeAction()
{

}

bool UActionObject::CheckIfActionCanRun()
{
	return true;
}




//cancel, stop, 
