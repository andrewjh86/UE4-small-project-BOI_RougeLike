// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/BaseItem.h"

UBaseItem::UBaseItem() {
	 UniqueItemName = EUniqueItemName::Base;

}

void UBaseItem::AddItems(UBaseItem* AddingItem)
{
	Amount += AddingItem->Amount;
}
