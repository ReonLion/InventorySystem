#pragma once

#include "BinarySearchTree.h"
#include "../Items/Item.h"

class Inventory
{
public:
	// 创建新的仓库对象
	// 新的仓库包含ItemType数目个二叉搜索树（一个搜索树对应一个类别）
	Inventory();

	// 从Inventory中移除一个Item
	bool Remove(const Item & item, int quantity);

	// 向Inventory中添加一个Item
	// 返回false，说明之前仓库中不存在这个item，反之，返回false
	bool Add(Item* p_item, int quantity);

	// 判断仓库中是否有一个item
	// 如果存在，返回数目
	// 如果不存在，返回0
	int Exist(Item* p_item);

	// 打印仓库
	void Display();

	// 销毁Inventory对象，释放指针和内存
	~Inventory();
private:
	// 物品种类的数目
	int8_t SubTreeNum = ItemTypeNum;
	// ItemType数目个二叉搜索树
	BinarySearchTree** inventory = new BinarySearchTree*[SubTreeNum];
};

