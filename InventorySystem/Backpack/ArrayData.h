#pragma once

class ArrayData
{
public:
	ArrayData();
	~ArrayData();

	// ��¡������Item��override
	virtual ArrayData* Clone() = 0;

protected:
	// ��Ʒ�Ƿ������
	bool bConsumable;
};
