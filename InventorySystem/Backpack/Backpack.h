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
	// 关联的Inventory
	Inventory* p_inventory;

	Backpack(Inventory *p_inventory, ItemFactory* p_itemFactory);
	~Backpack();

	// 捡起一个物品
	bool Pick(Item* p_item, int quantity);

	// 使用第i个box里的道具
	bool UseBox(int i);

	// 从仓库中获取物品到背包中
	// 发生交换的情况，返回false
	bool GetFromInventory(Item* p_item);

	// 将item从Backpack移入到Inventory中
	void MoveToInventory(Item* p_item);

	// 打印背包
	void Display() const;

	// 返回item在backpack中的数目
	// 没有则返回0
	int GetItemCount(Item* p_item) const;

private:
	// 重要，身上背包的容量，例如，一个背包有8个格子
	static const int capacity = 8;

	// 背包中每个格子的存储类型
	struct BoxStruct
	{
		Item* p_item = nullptr;
		int quantity;
	};

	// 用array表示格子
	// array<BoxStruct, capacity> boxes;
	BoxStruct boxes[capacity];

	// 格子的使用历史，最前面的是最久前使用的，即最久-->最近
	list<int> boxUseHistory;

	// Item生产仓库
	ItemFactory* p_itemFactory;

	// 背包是否有空位
	// 返回-1，没有空位
	// 返回第一个空位的下标
	int HasEmpty() const;

	// 返回含有item的box
	// 背包中没有Item则返回-1
	// 有Item，返回Box下标
	int HasItem(Item *& p_item) const;

	// 如果存在item，quantity+=quantity，如果不存在，quantity = quantity，返回true
	// 没有空位，返回false, 并添加到仓库中
	bool AddHandle(Item* p_item, int quantity);

	// 如果item的数目大于1，返回true，quantity -= 1
	// 如果item的数目等于1，返回true，删除arrayData
	// 其它情况，返回false
	bool RemoveHandle(Item* & p_item, int quantity);

	// 获得最久前使用的一个Box
	// 返回box的编号
	int GetLeastUsedBox() const;

	// 刷新box的使用历史，i是这次使用的box编号
	void UpdateBoxUseHistory(int i);
};
