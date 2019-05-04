#include "Inventory.h"
#include <iostream>

Inventory::Inventory()
{
	for (int i = 0; i < SubTreeNum; ++i)
	{
		inventory[i] = new BinarySearchTree();
	}
}

bool Inventory::Remove(const Item & item, int quantity)
{
	return inventory[int(item.GetType())]->Remove(item, quantity);
}

bool Inventory::Add(Item * p_item, int quantity)
{
	if (!p_item->IsConsumable())
	{
		// 如果是不可消耗物品(即无数量)，树中存在则直接返回
		if (Exist(p_item))
		{
			return false;
		}
	}
	return inventory[int(p_item->GetType())]->Insert(p_item, quantity);
}


int Inventory::Exist(Item * p_item)
{
	return inventory[int(p_item->GetType())]->Exist(p_item);
}

void Inventory::Display()
{

	std::cout << "------------------------------Inventory----------------------------------\n";
	for (int i = 0; i < SubTreeNum; ++i)
	{
		inventory[i]->Display();
	}
	std::cout << "-------------------------------------------------------------------------\n";
}

Inventory::~Inventory()
{
	delete[] inventory;
}
