#pragma once

#include <string>
#include <iostream>
#include "../Inventory/TreeData.h"

using namespace std;

// 物品种类
enum ItemType
{
	WEAPON = 0,
	EQUIPMENT,
	CLOTH,
	POTION,
	COIN = 4,
};

// 重要，在上面增加物品种类时，一定要相应改变下面这个值
static const int8_t ItemTypeNum = 5;

class Item : public TreeData
{
public:
	Item();
	~Item();

	// 根据物品类型创建一个对象
	Item(ItemType type);

	// 设置物品类型
	void SetType(ItemType type);

	// 设置物品id
	void SetId(int id);

	// 设置物品bConsumable
	void SetConsumable(bool bConsumable);

	// 设置物品名称
	void SetName(string name);

	// 返回物品类型
	ItemType GetType() const;

	// 返回物品id
	int GetId() const;

	// 返回物品bConsumable
	bool IsConsumable() const;

	// 返回物品名称
	string GetName() const;

	// Return true if this TreeData object is smaller than the other one
	// Two TreeData object must can be compared
	bool operator<(const TreeData & otherTreeData) const override;

	// Return true if this TreeData object is bigger than the other one
	bool operator>(const TreeData & otherTreeData) const override;

	// Return true if Two TreeData objects are equal
	bool operator==(const TreeData & otherTreeData) const override;

	// Return true if Two TreeData objects are not equal
	bool operator!=(const TreeData & otherTreeData) const override;

	// 打印
	virtual void print(ostream& output) const override;

	// 拷贝对象
	virtual Item* Clone() override;

	// Item功能
	virtual void Function();


protected:
	// 物品种类
	ItemType type;
	// 物品id,每个物品id在此种类中必须唯一
	int id;
	// 物品名称
	string name;
	// 物品是否是可消耗品
	bool bConsumable;
};

