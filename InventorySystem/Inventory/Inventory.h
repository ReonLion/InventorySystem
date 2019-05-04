#pragma once

#include "BinarySearchTree.h"
#include "../Items/Item.h"

class Inventory
{
public:
	// �����µĲֿ����
	// �µĲֿ����ItemType��Ŀ��������������һ����������Ӧһ�����
	Inventory();

	// ��Inventory���Ƴ�һ��Item
	bool Remove(const Item & item, int quantity);

	// ��Inventory�����һ��Item
	// ����false��˵��֮ǰ�ֿ��в��������item����֮������false
	bool Add(Item* p_item, int quantity);

	// �жϲֿ����Ƿ���һ��item
	// ������ڣ�������Ŀ
	// ��������ڣ�����0
	int Exist(Item* p_item);

	// ��ӡ�ֿ�
	void Display();

	// ����Inventory�����ͷ�ָ����ڴ�
	~Inventory();
private:
	// ��Ʒ�������Ŀ
	int8_t SubTreeNum = ItemTypeNum;
	// ItemType��Ŀ������������
	BinarySearchTree** inventory = new BinarySearchTree*[SubTreeNum];
};

