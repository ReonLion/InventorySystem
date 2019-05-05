#pragma once

#include "Item.h"
#include <vector>
#include <string>

using namespace std;

class ItemFactory
{
public:
	ItemFactory();
	~ItemFactory();

	virtual Item* Create(ItemType type, int id) = 0;

	virtual bool IsItemMixed(string name) = 0;

	virtual bool GetItemMixedList(string name) = 0;

	// ���ߺϳɱ�
	vector<vector<string>> ItemMixTable;
};