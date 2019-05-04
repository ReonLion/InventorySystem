#pragma once

class ArrayData
{
public:
	ArrayData();
	~ArrayData();

	// 克隆对象，在Item中override
	virtual ArrayData* Clone() = 0;

protected:
	// 物品是否可消耗
	bool bConsumable;
};
