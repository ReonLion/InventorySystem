#include "../Inventory/Inventory.h"
#include "../Backpack/Backpack.h"
#include "./Potions/Potions.h"
#include "ItemManager.h"
#include <iostream>
#include <string>

using namespace std;

void InitializeBackpack(Backpack* p_backpack, ItemManager* p_itemManager);

int PlayerAction();

void PlayerPickup(Backpack* p_backpack, ItemManager* p_itemManager);

void PlayerUse(Backpack* p_backpack);

void PlayerGetFromInventory(Backpack* p_backpack, ItemManager* p_itemManager);

int main()
{
	// 多线程测试
	Inventory* p_inventory = new Inventory();
	ItemManager* p_itemManager = new ItemManager();
	Backpack* p_backpack = new Backpack(p_inventory, p_itemManager);
	InitializeBackpack(p_backpack, p_itemManager);

	int input;
	do 
	{
		input = PlayerAction();
		switch (input)
		{
		case 1:
			PlayerPickup(p_backpack, p_itemManager);
			break;
		case 2:
			PlayerUse(p_backpack);
			break;
		case 3:
			PlayerGetFromInventory(p_backpack, p_itemManager);
		default:
			break;
		}
	} while (input != 4);
	
	delete p_inventory;

	system("Pause");
	return 0;
}

void InitializeBackpack(Backpack * p_backpack, ItemManager* p_itemManager)
{
	LittleHPPotion* p_LittleHPPotion = new LittleHPPotion();
	p_LittleHPPotion->Pickup(p_backpack, 3);
	LittleMPPotion* p_LittleMPPotion = new LittleMPPotion();
	p_LittleMPPotion->Pickup(p_backpack, 3);
	OldSword* p_oldSword = new OldSword();
	p_oldSword->Pickup(p_backpack, 1);
	IronArmour* p_ironArmour = new IronArmour();
	p_ironArmour->Pickup(p_backpack, 1);
	GoldRing* p_goldRing = new GoldRing();
	p_goldRing->Pickup(p_backpack, 1);
	GoldCoin* p_goldCoin = new GoldCoin();
	p_goldCoin->Pickup(p_backpack, 1);

	delete p_LittleHPPotion;
	delete p_LittleMPPotion;
	delete p_oldSword;
	delete p_ironArmour;
	delete p_goldRing;
	delete p_goldCoin;
	cout << "These are your initial items:\n";
	p_backpack->Display();
}

int PlayerAction()
{
	int i;

	cout << "Select a Action:\n";
	cout << "1. Pick up a Item.\n";
	cout << "2. Use a Item in Backpack.\n";
	cout << "3. Get a Item from Inventory to Backpack.\n";
	cout << "4. Quit.\n";

	string inputStr;
	getline(cin, inputStr);
	try
	{
		i = stoi(inputStr);
	}
	catch (...)
	{
		i = -1;
	}
	return i;
}

void PlayerPickup(Backpack* p_backpack, ItemManager* p_itemManager)
{
	cout << "Choose a item to Pick up\n";
	cout << "1. Little HP Potion\t2. Middle HP Potion\t3. Big HP Potion\n";
	cout << "4. Little MP Potion\t5. Middle MP Potion\t6. BIg MP Potion\n";
	cout << "7. Old Sword\t\t8. Russty Axe\t\t9.Magic Sword\n";
	cout << "10. Iron Armour\t\t11. Old Robe\t\t12. Cute Skirt\n";
	cout << "13. Gold Ring\t\t14. Silver Ring\t\t15. Copper Ring\n";
	cout << "16. Gold Coin\t\t17. Silver Coin\n";
	cout << "Input the code:\n";

	int code;
	string inputStr;
	getline(cin, inputStr);
	try
	{
		code = stoi(inputStr);
	}
	catch (...)
	{
		cout << "Please input a number 1 - 17:\n";
		return;
	}

	if (code > 0 && code <= 6)
	{
		Item* p_item = p_itemManager->Create(POTION, code);
		p_backpack->Pick(p_item, 1);
		delete p_item;
	}
	else if (code >= 7 && code <= 9)
	{
		Item* p_item = p_itemManager->Create(WEAPON, code - 6);
		p_backpack->Pick(p_item, 1);
		delete p_item;
	}
	else if (code >= 10 && code <= 12)
	{
		Item* p_item = p_itemManager->Create(CLOTH, code - 9);
		p_backpack->Pick(p_item, 1);
		delete p_item;
	}
	else if (code >= 13 && code <= 15)
	{
		Item* p_item = p_itemManager->Create(EQUIPMENT, code - 12);
		p_backpack->Pick(p_item, 1);
		delete p_item;
	}
	else if (code >= 16 && code <= 17)
	{
		Item* p_item = p_itemManager->Create(COIN, code - 15);
		p_backpack->Pick(p_item, 1);
		delete p_item;
	}
	// 输入错误，返回
	else
	{
		cout << "Item Code Invalid!\n";
		return;
	}

	p_backpack->p_inventory->Display();
	p_backpack->Display();
}

void PlayerUse(Backpack* p_backpack)
{
	int box;
	cout << "Choose a Box in Backpack to Use <1> <2> <3> <4> <5> <6> <7> <8>:\n";

	string inputStr;
	getline(cin, inputStr);
	try
	{
		box = stoi(inputStr);
	}
	catch (...)
	{
		cout << "Please a Box number 1-8:\n";
		return;
	}

	// 输入错误，返回
	if (box < 1 || box > 8)
	{
		cout << "There isn't Box " << box << ".\n";
		return;
	}

	// 使用Box里面的物品
	p_backpack->UseBox(box - 1);

	p_backpack->p_inventory->Display();
	p_backpack->Display();
}

void PlayerGetFromInventory(Backpack * p_backpack, ItemManager* p_itemManager)
{
	// 从仓库取出前，仓库中的物品打印
	p_backpack->p_inventory->Display();
	cout << "Choose an item in Inventory to get into Backpack (Input item name):\n";
	string name;

	getline(cin, name);
	// 创建暂时使用的item
	Item* p_item = p_itemManager->Create(name);

	// 不存在这个物品，输入错误
	if (p_item == nullptr)
	{
		cout << "There isn't a Item named " << name << ".\n";
		return;
	}
	// DEBUG显示用
	if (p_backpack->p_inventory->Exist(p_item) == 0)
	{
		cout << "There isn't a " << name << " in the Inventory.\n";
	}

	p_backpack->GetFromInventory(p_item);
	// 删除暂时使用的item
	delete p_item;

	// 从仓库取出后，仓库中的物品打印
	p_backpack->p_inventory->Display();
	p_backpack->Display();
}
