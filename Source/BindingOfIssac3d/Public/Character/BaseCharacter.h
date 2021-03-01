// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Character/CharacterInterface.h"
#include "BaseCharacter.generated.h"



class UStaticMeshComponent;
class USceneComponent;
class UActionComponent;
class UInventoryComponent;
class UAttributeComponent;

UCLASS()
class BINDINGOFISSAC3D_API ABaseCharacter : public ACharacter, public ICharacterInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UAttributeComponent* GetAttributeComponent_Implementation() const override { return AttributeComponent; }

	UActionComponent* GetActionComponent() const { return ActionComponent; }

	UInventoryComponent* GetInventoryComponent() const { return InventoryComponent; }

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	//UFUNCTION(BlueprintCallable, Category = Attribute)
		virtual void DeathHandle();


	//Debug only:
	UFUNCTION(BlueprintCallable, Category = Debug)
		void DebugCheckAssignVariables();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Debug)
		USceneComponent* ShootDebugSceneComponent;
	USceneComponent* GetShootDebugSceneComponent() { return ShootDebugSceneComponent; }
	//EndDebug

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Atribute)
		UAttributeComponent* AttributeComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Action)
		UActionComponent* ActionComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
		UInventoryComponent* InventoryComponent;



};
