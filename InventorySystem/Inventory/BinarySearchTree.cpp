#include "BinarySearchTree.h"
#include <iostream>


BinarySearchTree::BinarySearchTree()
{
	p_root = nullptr;
}


BinarySearchTree::~BinarySearchTree()
{
	ClearTreeHandle(p_root);
}

bool BinarySearchTree::Insert(TreeData * p_treeData, int quantity)
{
	/*bool inserted;
	if (p_treeData)
	{
		inserted = InsertHandle(p_root, p_treeData, quantity);
	}
	else
	{
		return false;
	}*/
	return InsertHandle(p_root, p_treeData, quantity);
}

bool BinarySearchTree::Remove(const TreeData & treeData, int quantity)
{
	return RemoveHandle(p_root, treeData, quantity);
}

void BinarySearchTree::ClearTree()
{
	ClearTreeHandle(p_root);
}

bool BinarySearchTree::IsEmpty() const
{
	return p_root == nullptr;
}

int BinarySearchTree::Exist(TreeData * p_treeData)
{	
	return ExistHandle(p_root, p_treeData);
}

void BinarySearchTree::Display()
{
	DisplayHandle(p_root);
}

void BinarySearchTree::DisplayHandle(Node *&p_root)
{
	if (p_root == nullptr)
	{
		return;
	}
	DisplayHandle(p_root->p_left);
	std::cout << *p_root->p_data << ", Num: " << p_root->quantity << endl;
	DisplayHandle(p_root->p_right);
}

bool BinarySearchTree::InsertHandle(Node *& p_root, TreeData * p_treeData, int quantity)
{
	bool inserted;
	if (!p_root)
	{
		// ���p_root�ǿ�ָ�룬����һ���½ڵ�
		p_root = new Node;
		// �½ڵ��p_dataָ��������treeData
		p_root->p_data = p_treeData->Clone();
		p_root->quantity = quantity;
		p_root->p_left = p_root->p_right = nullptr;
		return true;
	}
	else
	{
		if (*p_treeData < *p_root->p_data)
		{
			// treeData < root.data��������treeData��root����������
			inserted = InsertHandle(p_root->p_left, p_treeData, quantity);
		}
		else if (*p_treeData > *p_root->p_data)
		{
			// treeData > root.data��������treeData��root����������
			inserted = InsertHandle(p_root->p_right, p_treeData, quantity);
		}
		else
		{
			p_root->quantity += quantity;
			inserted = false;
		}
	}
	return inserted;
}

bool BinarySearchTree::RemoveHandle(Node *& p_root, const TreeData & treeData, int quantity)
{
	bool removed;
	if (!p_root)
	{
		removed = false;
	}
	else if (*p_root->p_data == treeData)
	{
		if (p_root->quantity == 1)
		{
			RemoveRoot(p_root);
			removed = true;
		}
		else
		{
			p_root->quantity -= quantity;
			removed = true;
		}
	}
	else if (treeData < *p_root->p_data)
	{
		removed = RemoveHandle(p_root->p_left, treeData, quantity);
	}
	else if (treeData > *p_root->p_data)
	{
		removed = RemoveHandle(p_root->p_right, treeData, quantity);
	}
	return removed;
}

void BinarySearchTree::RemoveRoot(Node *& p_root)
{
	if (p_root->p_left == nullptr && p_root->p_right == nullptr)
	{
		// p_rootָ��Ľڵ������������ǿ�ʱ��ֱ��ɾ��ָ��ýڵ��ָ��
		delete p_root->p_data;
		delete p_root;
		p_root = nullptr;
	}
	else if (p_root->p_left == nullptr)
	{
		// p_rootָ��Ľڵ�ֻ��������ʱ��ɾ��p_root��p_root = p_root->p_right
		Node *temp = p_root;
		p_root = p_root->p_right;
		delete temp->p_data;
		delete temp;
	}
	else if (p_root->p_right == nullptr)
	{
		// p_rootָ��Ľڵ�ֻ��������ʱ��ɾ��p_root��p_root = p_root->p_left
		Node *temp = p_root;
		p_root = p_root->p_left;
		delete temp->p_data;
		delete temp;
	}
	else
	{
		// p_rootָ��Ľڵ�����������ʱ
		// ɾ��p_root��������С�Ľڵ㣬��ʹp_root->p_data = SmallestTreeData
		delete p_root->p_data;
		int count = 0;
		p_root->p_data = FindAndDeleteSmallest(p_root->p_right, count);
		p_root->quantity = count;
	}
}

TreeData * BinarySearchTree::FindAndDeleteSmallest(Node *& p_root, int & count)
{
	if (p_root->p_left == nullptr)
	{
		// ɾ��p_root��ָNode�������������һ���ڵ㣬������ɾ����treeData
		// p_root = p_root->p_right;
		TreeData *p_treeData = p_root->p_data;
		count = p_root->quantity;
		Node *temp = p_root;
		p_root = p_root->p_right;
		delete temp;
		return p_treeData;
	}
	else
	{
		return FindAndDeleteSmallest(p_root->p_left, count);
	}
}

void BinarySearchTree::ClearTreeHandle(Node *& p_root)
{
	if (p_root != nullptr)
	{
		ClearTreeHandle(p_root->p_left);
		ClearTreeHandle(p_root->p_right);
		delete p_root->p_data;
		delete p_root;
		p_root = nullptr;
	}
}

int BinarySearchTree::ExistHandle(Node *& p_root, TreeData * p_treeData)
{
	int count;
	if (!p_root)
	{
		return 0;
	}
	else
	{
		if (*p_treeData < *p_root->p_data)
		{
			// treeData < root.data��������������
			count = ExistHandle(p_root->p_left, p_treeData);
		}
		else if (*p_treeData > *p_root->p_data)
		{
			// treeData > root.data��������������
			count = ExistHandle(p_root->p_right, p_treeData);
		}
		else
		{
			return p_root->quantity;
		}
	}
	return count;
}
