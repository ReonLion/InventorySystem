#pragma once

#include "TreeData.h"

class Item : public TreeData
{
public:
	Item();
	~Item();

	// 根据物品类型创建一个对象
	Item(char ch);

	// 设置物品类型
	virtual void SetType(char ch);

	// 返回物品类型
	virtual char GetType() const;

	// 创建一个物品
	virtual Item* create() = 0;

protected:
	char type;
};

