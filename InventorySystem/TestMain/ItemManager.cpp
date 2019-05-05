#include "ItemManager.h"

ItemManager::ItemManager()
{
	//// 道具合成表
	//ItemMixTable.resize(2);
	//// "Little HP Potion + Middle HP Potion + Big HP Potion = Super HP Potion"
	//ItemMixTable[0].push_back("Little HP Potion");
	//ItemMixTable[0].push_back("Middle HP Potion");
	//ItemMixTable[0].push_back("Big HP Potion");
	//ItemMixTable[0].push_back("Super HP Potion");
	//// "Little MP Potion + Middle MP Potion + Big HP Potion = Super MP Potion"
	//ItemMixTable[1].push_back("Little MP Potion");
	//ItemMixTable[1].push_back("Middle MP Potion");
	//ItemMixTable[1].push_back("Big MP Potion");
	//ItemMixTable[1].push_back("Super MP Potion");

	ItemMixTable = { { "1", "2", "3" }, { "4", "5", "6" } };
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

Item * ItemManager::Create(string name)
{
	// 简简单单=_=，TODO,哈希表
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

