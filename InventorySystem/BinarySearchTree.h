#pragma once

#include "TreeData.h"

class BinarySearchTree
{
public:
	// 创建一个root为nullptr的二叉搜索树
	BinarySearchTree();

	// BinarySearchTree is destructed, the used memory is deallocated appropriately
	~BinarySearchTree();

	// Insert a Node with a TreeData object
	// Return true if node is inserted, new node's quantity = quantity 
	// Return false if treeData is nullptr
	// Return false if treeData is already in BinarySearchTree, exist node's quantity += quantity
	bool Insert(TreeData *treeData, int quantity);

	// Remove a TreeData object from BinarySearchTree
	// Return true if quantity is greater than 1, quantity -= 1
	// Return true if quantity is 1, remove TreeData from BinarySearchTree
	// Otherwise, return false
	bool remove(const TreeData &treeData, int quantity);

private:
	struct Node
	{
		TreeData *data;
		Node *right;
		Node *left;
		int quantity;
	};
	
	Node *root;

	// Return true if node is inserted, new node's quantity = quantity 
	// Return false if treeData is already in BinarySearchTree, exist node's quantity += quantity
	bool __Insert(Node *&root, TreeData *treeData, int quantity);

	// Remove a Node from BinarySearchTree
	// Return true if quantity is greater than 1, quantity -= 1
	// Return true if quantity is 1, remove TreeData from BinarySearchTree
	// Otherwise, return false
	bool __Remove(Node *&, const TreeData & treeData, int quantity);

	// Remove a node and the new root is assigned to the value returned by findAndDeleteSmallest()
	void __RemoveRoot(Node *&root);

	// Find and Delete the node with the smallest TreeData value in the subtree
	// Return Deleted TreeData
	TreeData * findAndDeleteSmallest(Node *&root, int &count);
};

