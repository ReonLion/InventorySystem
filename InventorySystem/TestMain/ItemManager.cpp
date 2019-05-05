#include "ItemManager.h"

ItemManager::ItemManager()
{
	
}

ItemManager::~ItemManager()
{
}

Item * ItemManager::Create(ItemType type, int id)
{
	switch (type)
	{
	case WEAPON:
		return CreateWeapon(id);
	case EQUIPMENT:
		return CreateEquipment(id);
	case CLOTH:
		return CreateCloth(id);
	case POTION:
		return CreatePotion(id);
	case COIN:
		return CreateCoin(id);
	default:
		return nullptr;
	};
}

ItemMixStat ItemManager::GetItemMixedStat(string name)
{
	for(int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 4 - 1; ++j)
		{
			if (ItemMixTable[i][j] == name)
			{
				ItemMixStat stat;
				stat.bCanBeMixed = true;
				stat.p_sourceItemList = ItemMixTable[i];
				stat.sourceItemListCount = 3;
				stat.destinationItem = ItemMixTable[i][3];
				return stat;
			}
		}
	}
	ItemMixStat stat = { false, nullptr, 0, ""};
	return stat;
}

Item * ItemManager::Create(string name)
{
	// ¼ò¼òµ¥µ¥=_=£¬TODO,¹þÏ£±í
	if (name == "Little HP Potion")
	{
		return new LittleHPPotion();
	}
	else if (name == "Middle HP Potion")
	{
		return new MiddleHPPotion();
	}
	else if (name == "Big HP Potion")
	{
		return new BigHPPotion();
	}
	else if (name == "Super HP Potion")
	{
		return new SuperHPPotion();
	}
	else if (name == "Little MP Potion")
	{
		return new LittleMPPotion();
	}
	else if (name == "Middle MP Potion")
	{
		return new MiddleMPPotion();
	}
	else if (name == "Big MP Potion")
	{
		return new BigMPPotion();
	}
	else if (name == "Super MP Potion")
	{
		return new SuperMPPotion();
	}
	else if (name == "Magic Sword")
	{
		return new MagicSword();
	}
	else if (name == "Old Sword")
	{
		return new OldSword();
	}
	else if (name == "Russty Axe")
	{
		return new RusstyAxe();
	}
	else if (name == "Cute Skirt")
	{
		return new CuteSkirt();
	}
	else if (name == "Iron Armour")
	{
		return new IronArmour();
	}
	else if (name == "Old Robe")
	{
		return new OldRobe();
	}
	else if (name == "Copper Ring")
	{
		return new CopperRing();
	}
	else if (name == "Gold Ring")
	{
		return new GoldRing();
	}
	else if (name == "Silver Ring")
	{
		return new SilverRing();
	}
	else if (name == "Gold Coin")
	{
		return new GoldCoin();
	}
	else if (name == "Silver Coin")
	{
		return new SilverCoin();
	}
	else
	{
		return nullptr;
	}
}

Item * ItemManager::CreateWeapon(int id)
{
	switch (id)
	{
	case 1:
		return new OldSword();
	case 2:
		return new RusstyAxe();
	case 3:
		return new MagicSword();
	default:
		return nullptr;
	}
}

Item * ItemManager::CreateEquipment(int id)
{
	switch (id)
	{
	case 1:
		return new GoldRing();
	case 2:
		return new SilverRing();
	case 3:
		return new CopperRing();
	default:
		return nullptr;
	}
}

Item * ItemManager::CreateCloth(int id)
{
	switch (id)
	{
	case 1:
		return new IronArmour();
	case 2:
		return new OldRobe();
	case 3:
		return new CuteSkirt();
	default:
		return nullptr;
	}
}

Item * ItemManager::CreatePotion(int id)
{
	switch (id)
	{
	case 1:
		return new LittleHPPotion();
	case 2:
		return new MiddleHPPotion();
	case 3:
		return new BigHPPotion();
	case 4:
		return new LittleMPPotion();
	case 5:
		return new MiddleMPPotion();
	case 6:
		return new BigMPPotion();
	case 7:
		return new SuperHPPotion();
	case 8:
		return new SuperMPPotion();
	default:
		return nullptr;
	}
}

Item * ItemManager::CreateCoin(int id)
{
	switch (id)
	{
	case 1:
		return new GoldCoin();
	case 2:
		return new SilverCoin();
	default:
		return nullptr;
	}
}

