// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//action special include:

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActionComponent.generated.h"

class UActionObject;
class ABaseCharacter;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BINDINGOFISSAC3D_API UActionComponent : public UActorComponent
{
	GENERATED_BODY()



protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION()
		void InitializeActionComponent();

	//UPROPERTY()
	//	TArray<TSubclassOf<UActionObject>> StartActionClasses;

	//UPROPERTY()
	//	TArray<UActionObject*> ActionList;

	//UFUNCTION()
	//	void IntitializeStartingActions();


	UPROPERTY()
		ABaseCharacter* OwningBaseCharacter;

public:



	// Sets default values for this component's properties
	UActionComponent();

	//UFUNCTION()
	//	void AddAction();

	//UFUNCTION()
	//	void TakeAwayAction();


	//Input Functions: 
	UFUNCTION()
		void StartPrimaryAction();

	UFUNCTION()
		void StopPrimaryAction();

	UFUNCTION()
		void EditPrimaryAction();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action")
		TSubclassOf<UActionObject> PrimaryActionClass;

	UPROPERTY()
		UActionObject* PrimaryAction;

	ABaseCharacter* GetOwningBaseCharacter() const { return OwningBaseCharacter; }
};
