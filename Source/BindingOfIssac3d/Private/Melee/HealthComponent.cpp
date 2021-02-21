
// Fill out your copyright notice in the Description page of Project Settings.


#include "Melee/HealthComponent.h"



// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{



}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	if (AActor* MyOwner = GetOwner()) {
		MyOwner->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::HandleTakeAnyDamage);
	}


}


void UHealthComponent::HandleTakeAnyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{
	UE_LOG(LogTemp, Warning, TEXT("Health damage handle"));

	if (Damage <= 0.0f || bIsDead)
	{
		return;
	}



	// Update health clamped
	Health = FMath::Clamp(Health - Damage, 0.0f, DefaultHealth);



	bIsDead = Health <= 0.0f;


	if (bIsDead)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("ded"));

	}
}


void UHealthComponent::Heal(float HealAmount)
{
	if (Health <= 0.0f)
	{
		return;
	}

	Health = FMath::Clamp(Health + HealAmount, 0.0f, DefaultHealth);

}

void UHealthComponent::ChangeDefaultHealth(float Amount)
{
	DefaultHealth = Amount;
	Health = DefaultHealth;
}


