#include "Backpack.h"
#include <iostream>

using namespace std;

Backpack::Backpack(Inventory *p_inventory, ItemFactory* p_itemFactory)
{
	// 关联Inventory
	this->p_inventory = p_inventory;

	//
	this->p_itemFactory = p_itemFactory;

	// 初始化boxUseHistoy，例[1,2,3,4,5,6,7,8]
	for (int i = 0; i < capacity; ++i)
	{
		boxUseHistory.push_back(i);
	}
}

Backpack::~Backpack()
{
}

bool Backpack::Pick(Item * p_item, int quantity)
{
	bool res = AddHandle(p_item, quantity);
	cout << "You pick up a " << p_item->GetName() << ", Backpack remains " << GetItemCount(p_item)
		<< ", Inventory remains: " << p_inventory->Exist(p_item) << endl;
	return res;
}

bool Backpack::UseBox(int i)
{
	if (boxes[i].p_item != nullptr)
	{
		// 产生一个缓存Item来使用
		Item *p_item = p_itemFactory->Create(boxes[i].p_item->GetType(), boxes[i].p_item->GetId());

		// 调用item的Use()方法
		p_item->Function();
		// 从背包中remove 1个item
		// 当数量变为0时，Remove会使p_item = nullptr
		RemoveHandle(p_item, 1);

		// Debug
		cout << "You use a " << p_item->GetName() << ", Backpack remains " << HasItem(p_item)
			<< ", Inventory remains: " << p_inventory->Exist(p_item) << endl;

		// 删除缓存产生的item
		delete p_item;
		return true;
	}
	else
	{
		cout << "There is no Item in Box " << i + 1 << endl;
		return false;
	}
}

bool Backpack::GetFromInventory(Item * p_item)
{
	if (HasEmpty() != -1)
	{
		// 如果backpack有空位
		// 获取Inventory中该item的数量
		int count = p_inventory->Exist(p_item);
		// 从Inventory中完全移除该item
		p_inventory->Remove(*p_item, count);
		// 加入到backpack中
		AddHandle(p_item, count);
		return true;
	}
	else
	{
		// 如果backpack中没有空位
		// 获取最不常使用的格子
		int box = GetLeastUsedBox();
		// 将其中的物品移入到仓库中
		MoveToInventory(boxes[box].p_item);

		// 此时有空格子，重复上个分支的内容
		int count = p_inventory->Exist(p_item);
		p_inventory->Remove(*p_item, count);
		AddHandle(p_item, count);
		return false;
	}
}

void Backpack::MoveToInventory(Item * p_item)
{
	// 获取背包中这个item的所有数量
	int box = HasItem(p_item);
	int count = boxes[box].quantity;
	// 在交换过程中，创造缓存的item
	Item* p_swapItem = p_itemFactory->Create(p_item->GetType(), p_item->GetId());
	// 从背包中移除物品
	RemoveHandle(p_item, count);
	// 加入到Inventory中
	p_inventory->Add(p_swapItem, count);
	// 交换完成，删除缓存的item
	delete p_swapItem;
}

void Backpack::Display() const
{
	cout << "----------------------------------------Backpack--------------------------------------------------\n";
	for (int i = 0; i < capacity; ++i)
	{
		Item* p_item = boxes[i].p_item;
		if (p_item != nullptr)
		{
			cout << p_item->GetName() << " " << boxes[i].quantity << "  |  ";
		}
		else
		{
			cout << "None" << "  |  ";
		}
	}
	cout << endl;
	cout << "--------------------------------------------------------------------------------------------------\n";
}

int Backpack::GetItemCount(Item * p_item) const
{
	int box = HasItem(p_item);
	if ( box != -1)
	{
		return boxes[box].quantity;
	}
	else
	{
		return 0;
	}
}

int Backpack::HasEmpty() const
{
	for (int i = 0; i < capacity; ++i)
	{
		if (boxes[i].p_item == nullptr)
		{
			return i;
		}
	}

	return -1;
}

int Backpack::HasItem(Item * &p_item) const
{
	for (int i = 0; i < capacity; ++i)
	{
		if (boxes[i].p_item != nullptr and *(boxes[i].p_item) == *p_item)
		{
			return i;
		}
	}

	return -1;
}


bool Backpack::AddHandle(Item * p_item, int quantity)
{
	int box;
	if ((box = HasItem(p_item)) != -1)
	{
		// 存在item，则只增加数量
		boxes[box].quantity += quantity;
		// 刷新box使用
		UpdateBoxUseHistory(box);
		return true;
	}
	else if((box = HasEmpty()) != -1)
	{
		// 不存在item，但有空格子
		boxes[box].p_item = p_item->Clone();
		boxes[box].quantity = quantity;
		// 刷新box使用
		UpdateBoxUseHistory(box);
		return true;
	}
	else
	{
		// 不存在item，也不存在空格子
		// 添加进Inventory
		p_inventory->Add(p_item, quantity);
		return false;
	}
}

bool Backpack::RemoveHandle(Item *& p_item, int quantity)
{
	for (int i = 0; i < capacity; ++i)
	{
		if (boxes[i].p_item != nullptr)
		{
			// 跳过比较空的格子
			if (*boxes[i].p_item == *p_item)
			{
				// 存在item
				if (boxes[i].quantity > quantity)
				{
					// backpack中item数量大于使用数量，只改变数量
					boxes[i].quantity -= quantity;
					UpdateBoxUseHistory(i);
					return true;
				}
				else if (boxes[i].quantity <= quantity)
				{
					// backpack中item数量小于等于使用数量，数量=0，box中的物品置为空
					boxes[i].quantity = 0;
					delete boxes[i].p_item;
					boxes[i].p_item = nullptr;
					UpdateBoxUseHistory(i);
					return true;
				}
			}
		}
	}
	// Backpack中没有item
	return false;
}

int Backpack::GetLeastUsedBox() const
{
	return *boxUseHistory.begin();
}

void Backpack::UpdateBoxUseHistory(int i)
{
	boxUseHistory.remove(i);
	boxUseHistory.push_back(i);
}
