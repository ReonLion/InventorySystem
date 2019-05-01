#include "BinarySearchTree.h"



BinarySearchTree::BinarySearchTree()
{
	root = nullptr;
}


BinarySearchTree::~BinarySearchTree()
{
}

bool BinarySearchTree::Insert(TreeData * treeData, int quantity)
{
	bool inserted;
	if (treeData)
	{
		inserted = __Insert(root, treeData, quantity);
	}
	else
	{
		return false;
	}
	return inserted;
}

bool BinarySearchTree::__Insert(Node *& root, TreeData * treeData, int quantity)
{
	bool inserted;
	if (!root)
	{
		root = new Node;
		root->data = treeData;
		root->quantity = quantity;
		root->left = root->right = nullptr;
		return true;
	}
	else
	{
		if (*treeData < *root->data)
		{
			inserted = __Insert(root->left, treeData, quantity);
		}
		else if (*treeData > *root->data)
		{
			inserted = __Insert(root->right, treeData, quantity);
		}
		else
		{
			root->quantity += quantity;
			inserted = false;
		}
	}
	return inserted;
}

bool BinarySearchTree::__Remove(Node *&, const TreeData & treeData, int quantity)
{
	bool removed;
	if (!root)
	{
		removed = false;
	}
	else if (*root->data == treeData)
	{
		if (root->quantity == 1)
		{
			__RemoveRoot(root);
			removed = true;
		}
		else
		{
			root->quantity -= quantity;
			removed = true;
		}
	}
	else if (treeData < *root->data)
	{
		removed = __Remove(root->left, treeData, quantity);
	}
	else if (treeData > *root->data)
	{
		removed = __Remove(root->right, treeData, quantity);
	}
	return removed;
}

TreeData * BinarySearchTree::findAndDeleteSmallest(Node *& root, int & count)
{
	return nullptr;
}
