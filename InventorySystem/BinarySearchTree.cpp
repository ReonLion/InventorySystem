#include "BinarySearchTree.h"



BinarySearchTree::BinarySearchTree()
{
	p_root = nullptr;
}


BinarySearchTree::~BinarySearchTree()
{
}

bool BinarySearchTree::Insert(TreeData * p_treeData, int quantity)
{
	bool inserted;
	if (p_treeData)
	{
		inserted = InsertHandle(p_root, p_treeData, quantity);
	}
	else
	{
		return false;
	}
	return inserted;
}

bool BinarySearchTree::InsertHandle(Node *& p_root, TreeData * p_treeData, int quantity)
{
	bool inserted;
	if (!p_root)
	{
		// 如果p_root是空指针，建立一个新节点
		p_root = new Node;
		// 新节点的p_data指向待插入的treeData
		p_root->p_data = p_treeData;
		p_root->quantity = quantity;
		p_root->p_left = p_root->p_right = nullptr;
		return true;
	}
	else
	{
		if (*p_treeData < *p_root->p_data)
		{
			// treeData < root.data，则插入的treeData在root的左子树上
			inserted = InsertHandle(p_root->p_left, p_treeData, quantity);
		}
		else if (*p_treeData > *p_root->p_data)
		{
			// treeData > root.data，则插入的treeData在root的右子树上
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

bool BinarySearchTree::RemoveHandle(Node *&, const TreeData & treeData, int quantity)
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
		// p_root指向的节点左右子树都是空时，直接删除指向该节点的指针
		delete p_root->p_data;
		delete p_root;
		p_root = nullptr;
	}
	else if (p_root->p_left == nullptr)
	{
		// p_root指向的节点只有右子树时，删除p_root，p_root = p_root->p_right
		Node *temp = p_root;
		p_root = p_root->p_right;
		delete temp->p_data;
		delete temp;
	}
	else if (p_root->p_right == nullptr)
	{
		// p_root指向的节点只有左子树时，删除p_root，p_root = p_root->p_left
		Node *temp = p_root;
		p_root = p_root->p_left;
		delete temp->p_data;
		delete temp;
	}
	else
	{
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
		// 删除p_root所指Node的左子树的最后一个节点，并返回删除的treeData
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
