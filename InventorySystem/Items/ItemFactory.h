#pragma once

#include "Item.h"

class ItemFactory
{
public:
	ItemFactory();
	~ItemFactory();

	virtual Item* Create(ItemType type, int id) = 0;
};