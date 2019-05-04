#pragma once

#include <string>
#include <iostream>
#include "../Inventory/TreeData.h"

using namespace std;

// ��Ʒ����
enum ItemType
{
	WEAPON = 0,
	EQUIPMENT,
	CLOTH,
	POTION,
	COIN = 4,
};

// ��Ҫ��������������Ʒ����ʱ��һ��Ҫ��Ӧ�ı��������ֵ
static const int8_t ItemTypeNum = 5;

class Item : public TreeData
{
public:
	Item();
	~Item();

	// ������Ʒ���ʹ���һ������
	Item(ItemType type);

	// ������Ʒ����
	void SetType(ItemType type);

	// ������Ʒid
	void SetId(int id);

	// ������ƷbConsumable
	void SetConsumable(bool bConsumable);

	// ������Ʒ����
	void SetName(string name);

	// ������Ʒ����
	ItemType GetType() const;

	// ������Ʒid
	int GetId() const;

	// ������ƷbConsumable
	bool IsConsumable() const;

	// ������Ʒ����
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

	// ��ӡ
	virtual void print(ostream& output) const override;

	// ��������
	virtual Item* Clone() override;

	// Item����
	virtual void Function();


protected:
	// ��Ʒ����
	ItemType type;
	// ��Ʒid,ÿ����Ʒid�ڴ������б���Ψһ
	int id;
	// ��Ʒ����
	string name;
	// ��Ʒ�Ƿ��ǿ�����Ʒ
	bool bConsumable;
};

