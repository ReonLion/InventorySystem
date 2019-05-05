#pragma once

#include "Item.h"
#include <vector>
#include <string>

using namespace std;

struct ItemMixStat
{
	// �Ƿ��ǿ��Ա��ϳɵ���Ʒ
	bool bCanBeMixed = false;
	// ָ��ָ��һ�����飬���������Ǻϳɱ�
	string* p_sourceItemList = nullptr;
	int sourceItemListCount = 0;
	// �ϳɵ���Ʒ������
	string destinationItem = "";
};

class ItemFactory
{
public:
	ItemFactory();
	~ItemFactory();

	virtual Item* Create(ItemType type, int id) = 0;

	virtual Item* Create(string name) = 0;

	virtual ItemMixStat GetItemMixedStat(string name) = 0;
};