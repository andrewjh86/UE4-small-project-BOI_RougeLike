// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttributeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BINDINGOFISSAC3D_API UAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UAttributeComponent();

	//Dynamic
	bool bIsDead = false;

	UPROPERTY(BlueprintReadOnly, Category = "Attributes_Dynamic")
		float Health;

	UPROPERTY(BlueprintReadOnly, Category = "Attributes_Dynamic")
		float Stamina;

	//Static:
	UPROPERTY(BlueprintReadOnly, Category = "Attributes_Static")
		float Defense;



protected: 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes_Static")
		float BaseHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes_Static")
		float BaseStamina;


public:	

	UFUNCTION(BlueprintCallable, Category = "Attributes_Static")
		void UpgradeHealth(float amount);

	UFUNCTION(BlueprintCallable, Category = "Attributes_Dynamic")
		void AddHealth(float amount);

		UFUNCTION(BlueprintCallable, Category = "Attributes_Static")
		void UpgradeStamina(float amount);

	UFUNCTION(BlueprintCallable, Category = "Attributes_Dynamic")
		void AddStamina(float amount);
//
protected:
	// Called when the game starts
	virtual void BeginPlay() override;



		
};
