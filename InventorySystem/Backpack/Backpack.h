#pragma once

#include "../Inventory/Inventory.h"
#include "../Items/Item.h"
#include "../Items/ItemFactory.h"
#include <array>
#include <list>

//-----------------------Backpack-----------------------------
// | Box0 | Box1 | Box2 | Box3 | Box4 | Box5 | Box6 | Box7 |
// |      |      |      |      |      |      |      |      |
//------------------------------------------------------------

using namespace std;

class Backpack
{
public:
	// ������Inventory
	Inventory* p_inventory;

	Backpack(Inventory *p_inventory, ItemFactory* p_itemFactory);
	~Backpack();

	// ����һ����Ʒ
	bool Pick(Item* p_item, int quantity);

	// ʹ�õ�i��box��ĵ���
	bool UseBox(int i);

	// �Ӳֿ��л�ȡ��Ʒ��������
	// �������������������false
	bool GetFromInventory(Item* p_item);

	// ��item��Backpack���뵽Inventory��
	void MoveToInventory(Item* p_item);

	// ��ӡ����
	void Display() const;

	// ����item��backpack�е���Ŀ
	// û���򷵻�0
	int GetItemCount(Item* p_item) const;

private:
	// ��Ҫ�����ϱ��������������磬һ��������8������
	static const int capacity = 8;

	// ������ÿ�����ӵĴ洢����
	struct BoxStruct
	{
		Item* p_item = nullptr;
		int quantity;
	};

	// ��array��ʾ����
	// array<BoxStruct, capacity> boxes;
	BoxStruct boxes[capacity];

	// ���ӵ�ʹ����ʷ����ǰ��������ǰʹ�õģ������-->���
	list<int> boxUseHistory;

	// Item�����ֿ�
	ItemFactory* p_itemFactory;

	// �����Ƿ��п�λ
	// ����-1��û�п�λ
	// ���ص�һ����λ���±�
	int HasEmpty() const;

	// ���غ���item��box
	// ������û��Item�򷵻�-1
	// ��Item������Box�±�
	int HasItem(Item *& p_item) const;

	// �������item��quantity+=quantity����������ڣ�quantity = quantity������true
	// û�п�λ������false, ����ӵ��ֿ���
	bool AddHandle(Item* p_item, int quantity);

	// ���item����Ŀ����1������true��quantity -= 1
	// ���item����Ŀ����1������true��ɾ��arrayData
	// �������������false
	bool RemoveHandle(Item* & p_item, int quantity);

	// ������ǰʹ�õ�һ��Box
	// ����box�ı��
	int GetLeastUsedBox() const;

	// ˢ��box��ʹ����ʷ��i�����ʹ�õ�box���
	void UpdateBoxUseHistory(int i);
};
