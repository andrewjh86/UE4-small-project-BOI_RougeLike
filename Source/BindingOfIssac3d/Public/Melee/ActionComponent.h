// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//action special include:

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActionComponent.generated.h"

class UActionObject;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BINDINGOFISSAC3D_API UActionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UActionComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:	
	UFUNCTION()
		bool TryInitializeActionComponent();

	UFUNCTION()
		bool TrySwapActionObject();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action")
	TSubclassOf<UActionObject> PrimaryActionClass;

	UPROPERTY()
		UActionObject* PrimaryAction;

	UFUNCTION()
		void StartPrimaryAction();

	UFUNCTION()
		void StopPrimaryAction();

};
