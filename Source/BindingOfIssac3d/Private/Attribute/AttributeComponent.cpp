// Fill out your copyright notice in the Description page of Project Settings.


#include "Attribute/AttributeComponent.h"

// Sets default values for this component's properties
UAttributeComponent::UAttributeComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}


void UAttributeComponent::UpgradeHealth(float amount)
{
	float Increase = BaseHealth / (BaseHealth + amount) * Health;
	BaseHealth += amount;
	AddHealth(Increase);
}

void UAttributeComponent::AddHealth(float amount)
{
	Health = FMath::Clamp(Health + amount, 0.0f, BaseHealth);

	if (Health <= 0.0f)
	{
		bIsDead = true;
	}
}

void UAttributeComponent::UpgradeStamina(float amount)
{
	float Increase = BaseStamina / (BaseStamina + amount) * Stamina;
	BaseStamina += amount;
	AddStamina(Increase);
}

void UAttributeComponent::AddStamina(float amount)
{
	Stamina = FMath::Clamp(Stamina + amount, 0.0f, BaseStamina);

}


void UAttributeComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}



