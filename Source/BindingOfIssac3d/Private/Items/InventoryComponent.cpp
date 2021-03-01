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




void UInventoryComponent::AddItemToInventory(UBaseItem* NewItem)
{
	if (UBaseItem* NewAmmo = Cast<UBaseItem>(NewItem)) {
		for (UBaseItem* CheckAmmo : AmmoList)
		{
			if (CheckAmmo->UniqueItemName == NewAmmo->UniqueItemName) {
				return;
			}
		}
		

	}
	else {

		//InventoryList.Add()

	}
}

void UInventoryComponent::AddItemToInventoryFromClass(TSubclassOf<UBaseItem> NewItemClass)
{

}

// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	UBaseItem* NewAmmo = NewObject< UBaseItem>(this);
	UBaseItem* NewAmmo1 = NewObject< UBaseItem>(this);
	NewAmmo1->Amount = 4;
	UBaseItem* NewAmmo2 = NewObject< UBaseItem>(this);
	InventoryList.AddUnique(NewAmmo);
	InventoryList.AddUnique(NewAmmo1);
	InventoryList.AddUnique(NewAmmo2);
	
	UE_LOG(LogTemp, Warning, TEXT("num items: %d"),InventoryList.Num());


}





