#include "Inventory.h"
#include <iostream>

//------------------------------------------------------------
// ���ö�������ģʽʵ���̰߳�ȫ
Inventory* Inventory::p = new Inventory;

Inventory * Inventory::GetInstance()
{
	return p;
}
//------------------------------------------------------------

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
		// ����ǲ���������Ʒ(��������)�����д�����ֱ�ӷ���
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
