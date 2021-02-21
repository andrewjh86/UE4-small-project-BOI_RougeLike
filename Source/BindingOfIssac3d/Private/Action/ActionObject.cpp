// Fill out your copyright notice in the Description page of Project Settings.


#include "Action/ActionObject.h"
#include "Components/ActorComponent.h"


void UActionObject::ActionImplementation()
{
	UE_LOG(LogTemp, Warning, TEXT("Action()"));
}

void UActionObject::ActionStart() 
{
	UE_LOG(LogTemp, Warning, TEXT("Actionstart()"));
}

void UActionObject::ActionStop()
{
	UE_LOG(LogTemp, Warning, TEXT("ActionStop()"));

}

bool UActionObject::TryInitializeAction(UActionComponent* _OwningActionComponent)
{
	OwningActionComponent = _OwningActionComponent;
	UE_LOG(LogTemp, Warning, TEXT("InitializeAction"));

	return true;
}

bool UActionObject::TryUninitializeAction()
{
	UE_LOG(LogTemp, Warning, TEXT("UninitializeAction"));

	return true;
}

bool UActionObject::CheckIfActionCanRun()
{
	return false;
}





