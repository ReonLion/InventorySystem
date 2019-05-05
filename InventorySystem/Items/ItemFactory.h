#pragma once

#include "Item.h"
#include <vector>
#include <string>

using namespace std;

struct ItemMixStat
{
	// 是否是可以被合成的物品
	bool bCanBeMixed = false;
	// 指针指向一个数组，数组内容是合成表
	string* p_sourceItemList = nullptr;
	int sourceItemListCount = 0;
	// 合成的物品的名称
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