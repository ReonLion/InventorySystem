#pragma once

#include "TreeData.h"

class Item : public TreeData
{
public:
	Item();
	~Item();

	// ������Ʒ���ʹ���һ������
	Item(char ch);

	// ������Ʒ����
	virtual void SetType(char ch);

	// ������Ʒ����
	virtual char GetType() const;

	// ����һ����Ʒ
	virtual Item* create() = 0;

protected:
	char type;
};

