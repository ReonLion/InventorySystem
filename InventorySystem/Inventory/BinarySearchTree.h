#pragma once

#include "TreeData.h"

class BinarySearchTree
{
public:
	// ����һ��rootΪnullptr�Ķ���������
	BinarySearchTree();

	// ɾ���������������ͷŷ�����ڴ�
	~BinarySearchTree();

	// �����в���һ��TreeData
	// ����ɹ��򷵻�true��Node��TreeData����Ŀquantity = quantity
	// ���TreeData�ǿ�ָ�룬����false
	// ���TreeData�Ѿ��������У�����false��Node��TreeData����Ŀquantity += quantity
	bool Insert(TreeData *p_treeData, int quantity);

	// ������ɾ��һ��TreeData
	// ���TreeData����Ŀ����1������true��quantity -= 1
	// ���TreeData����Ŀ����1������true��������ɾ��TreeData
	// �������������false
	bool Remove(const TreeData &treeData, int quantity);

	// ��������ͷ��ڴ�
	void ClearTree();

	// ���Ƿ�Ϊ����
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

	// ����ɹ��򷵻�true��Node��TreeData����Ŀquantity = quantity
	// ���TreeData�Ѿ��������У�����false��Node��TreeData����Ŀquantity += quantity
	bool InsertHandle(Node *&p_root, TreeData *p_treeData, int quantity);

	// ������ɾ��һ��TreeData
	// ���TreeData����Ŀ����1������true��quantity -= 1
	// ���TreeData����Ŀ����1������true��������ɾ��TreeData
	// �������������false
	bool RemoveHandle(Node *&p_root, const TreeData & treeData, int quantity);

	// ������ɾ��һ��Node���������Node���������·�����ڵ�
	void RemoveRoot(Node *&p_root);

	// Ѱ�Ҳ�ɾ��p_root��������С��һ��Node�����������Node�е�p_treeData
	TreeData * FindAndDeleteSmallest(Node *&p_root, int &count);

	// ���������ɾ��TreeData
	void ClearTreeHandle(Node *&root);
};

