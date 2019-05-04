#include "Backpack.h"
#include <iostream>

using namespace std;

Backpack::Backpack(Inventory *p_inventory, ItemFactory* p_itemFactory)
{
	// ����Inventory
	this->p_inventory = p_inventory;

	//
	this->p_itemFactory = p_itemFactory;

	// ��ʼ��boxUseHistoy����[1,2,3,4,5,6,7,8]
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
		// ����һ������Item��ʹ��
		Item *p_item = p_itemFactory->Create(boxes[i].p_item->GetType(), boxes[i].p_item->GetId());

		// ����item��Use()����
		p_item->Function();
		// �ӱ�����remove 1��item
		// ��������Ϊ0ʱ��Remove��ʹp_item = nullptr
		RemoveHandle(p_item, 1);

		// Debug
		cout << "You use a " << p_item->GetName() << ", Backpack remains " << HasItem(p_item)
			<< ", Inventory remains: " << p_inventory->Exist(p_item) << endl;

		// ɾ�����������item
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
		// ���backpack�п�λ
		// ��ȡInventory�и�item������
		int count = p_inventory->Exist(p_item);
		// ��Inventory����ȫ�Ƴ���item
		p_inventory->Remove(*p_item, count);
		// ���뵽backpack��
		AddHandle(p_item, count);
		return true;
	}
	else
	{
		// ���backpack��û�п�λ
		// ��ȡ���ʹ�õĸ���
		int box = GetLeastUsedBox();
		// �����е���Ʒ���뵽�ֿ���
		MoveToInventory(boxes[box].p_item);

		// ��ʱ�пո��ӣ��ظ��ϸ���֧������
		int count = p_inventory->Exist(p_item);
		p_inventory->Remove(*p_item, count);
		AddHandle(p_item, count);
		return false;
	}
}

void Backpack::MoveToInventory(Item * p_item)
{
	// ��ȡ���������item����������
	int box = HasItem(p_item);
	int count = boxes[box].quantity;
	// �ڽ��������У����컺���item
	Item* p_swapItem = p_itemFactory->Create(p_item->GetType(), p_item->GetId());
	// �ӱ������Ƴ���Ʒ
	RemoveHandle(p_item, count);
	// ���뵽Inventory��
	p_inventory->Add(p_swapItem, count);
	// ������ɣ�ɾ�������item
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
		// ����item����ֻ��������
		boxes[box].quantity += quantity;
		// ˢ��boxʹ��
		UpdateBoxUseHistory(box);
		return true;
	}
	else if((box = HasEmpty()) != -1)
	{
		// ������item�����пո���
		boxes[box].p_item = p_item->Clone();
		boxes[box].quantity = quantity;
		// ˢ��boxʹ��
		UpdateBoxUseHistory(box);
		return true;
	}
	else
	{
		// ������item��Ҳ�����ڿո���
		// ���ӽ�Inventory
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
			// �����ȽϿյĸ���
			if (*boxes[i].p_item == *p_item)
			{
				// ����item
				if (boxes[i].quantity > quantity)
				{
					// backpack��item��������ʹ��������ֻ�ı�����
					boxes[i].quantity -= quantity;
					UpdateBoxUseHistory(i);
					return true;
				}
				else if (boxes[i].quantity <= quantity)
				{
					// backpack��item����С�ڵ���ʹ������������=0��box�е���Ʒ��Ϊ��
					boxes[i].quantity = 0;
					delete boxes[i].p_item;
					boxes[i].p_item = nullptr;
					UpdateBoxUseHistory(i);
					return true;
				}
			}
		}
	}
	// Backpack��û��item
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