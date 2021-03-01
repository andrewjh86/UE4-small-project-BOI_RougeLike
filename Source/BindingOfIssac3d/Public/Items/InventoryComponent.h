// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class UBaseItem;
class UAmmoItem;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BINDINGOFISSAC3D_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInventoryComponent();

	UFUNCTION(BlueprintCallable, Category = Inventory)
		void AddItemToInventory(UBaseItem* NewItem);

	UFUNCTION(BlueprintCallable, Category = Inventory)
		void AddItemToInventoryFromClass(TSubclassOf<UBaseItem> NewItemClass);
	UFUNCTION(BlueprintPure)
	TArray<UBaseItem*> GetInventoryList() const  { return InventoryList; };

	//Ammo list
	UFUNCTION(BlueprintPure)
	TArray<UAmmoItem*> GetAmmoList() const { return AmmoList; };

	//health list

	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	//map of amo with ammounts:
	//TMap<FString,int32> AmmoList;


	TArray<UBaseItem*> InventoryList;
	TArray<UAmmoItem*> AmmoList;

};
