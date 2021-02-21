// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//character special includes
#include "Attribute/AttributeComponent.h"
#include "Melee/ActionComponent.h"

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Character/CharacterInterface.h"
#include "BaseCharacter.generated.h"



class UStaticMeshComponent;
//class UAttributeComponent;
//class UActionComponent;

UCLASS()
class BINDINGOFISSAC3D_API ABaseCharacter : public ACharacter , public ICharacterInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = Attribute)	
	UAttributeComponent* GetAttributeComponent_Implementation() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "3D Space")
		UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Atribute")
		UAttributeComponent* AttributeComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action")
		UActionComponent* ActionComponent;

	UFUNCTION(BlueprintCallable, Category = Debug)
		void DebugCheckAssignVariables();
};
