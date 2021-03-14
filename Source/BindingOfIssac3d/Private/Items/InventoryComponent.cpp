// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/InventoryComponent.h"
#include "Items/AmmoItem.h"


// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


void UInventoryComponent::InitializeInventory()
{
	if (StartingItems.Num() > 0) {

		for (TSubclassOf<UBaseItem> StartItemClass : StartingItems) {
			UBaseItem* NewItem = NewObject< UBaseItem>(GetOwner(), StartItemClass);

		}

	}
}


void UInventoryComponent::AddItemToInventory(UBaseItem* NewItem)
{
	bool bNeedToAddNewSlot = true;
	if (UAmmoItem* NewAmmo = Cast<UAmmoItem>(NewItem))
	{
		for (UAmmoItem* CheckAmmo : AmmoList)
		{
			if (CheckAmmo->GetClass() == NewAmmo->GetClass())
			{
				CheckAmmo->Amount += NewAmmo->Amount;
				bNeedToAddNewSlot = false;
				break;
			}
		}

		if (bNeedToAddNewSlot)
		{
			AmmoList.Add(NewAmmo);
		}

	}
	else {

		InventoryList.Add(NewItem);

	}
}

void UInventoryComponent::AddItemToInventoryFromClass(TSubclassOf<UBaseItem> NewItemClass)
{

}

bool UInventoryComponent::FindItemByClass(TSubclassOf<UBaseItem> ItemClass) {
	return false;
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();




}





