// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseItem.generated.h"

/**
 *
 */

UENUM(BlueprintType)
enum class EUniqueItemName : uint8 {
	Base,
	Ammo,
	FireAmmo
};


UCLASS(Blueprintable)
class BINDINGOFISSAC3D_API UBaseItem : public UObject
{
	GENERATED_BODY()


public:
	UBaseItem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
		EUniqueItemName UniqueItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
		TSubclassOf<AActor> ActorClass;

	UPROPERTY(EditAnywhere, Category = Item)
		int16 Amount;

	UPROPERTY(EditAnywhere, Category = Item)
		int8 MaxStack;

	UFUNCTION(BlueprintCallable, Category = Item)
		virtual void AddItems(UBaseItem* AddingItem);
};