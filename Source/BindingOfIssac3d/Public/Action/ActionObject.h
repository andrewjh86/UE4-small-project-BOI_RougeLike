// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
//includes necessary for all actions:
#include "Character/BaseCharacter.h"
#include "Melee/ActionComponent.h"


#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ActionObject.generated.h"


class UActionComponent;
/**
 *
 */

 //UCLASS(BlueprintType, Blueprintable,  meta = (ShortTooltip = "For making special abilities."))
UCLASS(Blueprintable)
class BINDINGOFISSAC3D_API UActionObject : public UObject
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category = "Action")
		virtual void ActionImplementation();

	UPROPERTY()
		UActionComponent* OwningActionComponent;

public:

	UFUNCTION(BlueprintCallable, Category = "Action")
		virtual void ActionStart();

	UFUNCTION(BlueprintCallable, Category = "Action")
		virtual void ActionStop();

	UFUNCTION(BlueprintCallable, Category = "Setup")
		virtual void InitializeAction(UActionComponent* _OwningActionComponent);

	UFUNCTION(BlueprintCallable, Category = "Setup")
		virtual void UninitializeAction();

	UFUNCTION(BlueprintCallable, Category = "Setup")
		virtual bool CheckIfActionCanRun();

	UActionComponent* GetOwningActionComponent() const {return OwningActionComponent; }

};



