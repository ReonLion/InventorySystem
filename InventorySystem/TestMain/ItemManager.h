#pragma once

#include "../Items/Item.h"
#include "../Items/ItemFactory.h"
#include "./Potions/Potions.h"
#include "./Weapons/Weapons.h"
#include "./Clothes/Clothes.h"
#include "./Equipments/Equipments.h"
#include "./Coins/Coins.h"

typedef std::uint64_t hash_t;
constexpr hash_t prime = 0x100000001B3ull;
constexpr hash_t basis = 0xCBF29CE484222325ull;

class ItemManager : public ItemFactory
{
public:
	ItemManager();
	~ItemManager();

	virtual Item* Create(ItemType type, int id) override;
	Item* Create(string name);

private:
	Item* CreateWeapon(int id);
	Item* CreateEquipment(int id);
	Item* CreateCloth(int id);
	Item* CreatePotion(int id);
	Item* CreateCoin(int id);
};
