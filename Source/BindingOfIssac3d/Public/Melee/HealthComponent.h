// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BINDINGOFISSAC3D_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UHealthComponent();

	bool bIsDead=false;

	UPROPERTY(BlueprintReadOnly, Category = "Attributes-Adjustable")
		float Health=100;

	UPROPERTY(BlueprintReadOnly, Category = "Attributes-Static")
		float Strength = 100;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes-Adjustable")
		float DefaultHealth=100;


public:
	UFUNCTION()
		void HandleTakeAnyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

	UFUNCTION(BlueprintCallable, Category = "Health")
		void Heal(float HealAmount);

	UFUNCTION(BlueprintCallable, Category = "Health")
		void ChangeDefaultHealth(float Amount);


};
	