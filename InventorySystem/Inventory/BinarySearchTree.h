#pragma once

#include "TreeData.h"

class BinarySearchTree
{
public:
	// 创建一个root为nullptr的二叉搜索树
	BinarySearchTree();

	// 删除二叉搜索树，释放分配的内存
	~BinarySearchTree();

	// 向树中插入一个TreeData
	// 插入成功则返回true，Node中TreeData的数目quantity = quantity
	// 如果TreeData是空指针，返回false
	// 如果TreeData已经存在树中，返回false，Node中TreeData的数目quantity += quantity
	bool Insert(TreeData *p_treeData, int quantity);

	// 从树中删除一个TreeData
	// 如果TreeData的数目大于1，返回true，quantity -= 1
	// 如果TreeData的数目等于1，返回true，从树中删除TreeData
	// 其它情况，返回false
	bool Remove(const TreeData &treeData, int quantity);

	// 清空树并释放内存
	void ClearTree();

	// 树是否为空树
	bool IsEmpty() const;

private:
	struct Node
	{
		TreeData *p_data;
		Node *p_right;
		Node *p_left;
		int quantity;
	};
	
	Node *p_root;

	// 插入成功则返回true，Node中TreeData的数目quantity = quantity
	// 如果TreeData已经存在树中，返回false，Node中TreeData的数目quantity += quantity
	bool InsertHandle(Node *&p_root, TreeData *p_treeData, int quantity);

	// 从树中删除一个TreeData
	// 如果TreeData的数目大于1，返回true，quantity -= 1
	// 如果TreeData的数目等于1，返回true，从树中删除TreeData
	// 其它情况，返回false
	bool RemoveHandle(Node *&p_root, const TreeData & treeData, int quantity);

	// 从树中删除一个Node，并给这个Node的子树重新分配根节点
	void RemoveRoot(Node *&p_root);

	// 寻找并删除p_root子树中最小的一个Node，并返回这个Node中的p_treeData
	TreeData * FindAndDeleteSmallest(Node *&p_root, int &count);

	// 清空树，并删除TreeData
	void ClearTreeHandle(Node *&root);
};

