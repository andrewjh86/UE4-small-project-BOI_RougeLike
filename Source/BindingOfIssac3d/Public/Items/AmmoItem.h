// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/BaseItem.h"
#include "AmmoItem.generated.h"

/**
 *  The only purpose of this class is to organize UItems through c++ code it doesn't work with blueprints
 */
UCLASS()
class BINDINGOFISSAC3D_API UAmmoItem : public UBaseItem
{
	GENERATED_BODY()
	
public:
	UAmmoItem();
};
