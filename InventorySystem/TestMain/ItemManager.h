#pragma once

#include "../Items/Item.h"
#include "../Items/ItemFactory.h"
#include "./Potions/Potions.h"
#include "./Weapons/Weapons.h"
#include "./Clothes/Clothes.h"
#include "./Equipments/Equipments.h"
#include "./Coins/Coins.h"

class ItemManager : public ItemFactory
{
public:
	ItemManager();
	~ItemManager();

	Item* Create(ItemType type, int id) override;

	virtual ItemMixStat GetItemMixedStat(string name) override;

	Item* Create(string name) override;

private:
	Item* CreateWeapon(int id);
	Item* CreateEquipment(int id);
	Item* CreateCloth(int id);
	Item* CreatePotion(int id);
	Item* CreateCoin(int id);

	// 道具合成表
	string ItemMixTable[2][4] = 
	{ 
		{"Little HP Potion", "Middle HP Potion", "Big HP Potion", "Super HP Potion"}, 
		{"Little MP Potion", "Middle MP Potion", "Big MP Potion", "Super MP Potion"},
	};
};
