#pragma once

#include "BaseDataStructure.h"
#include <string>


struct NodeLeaf
{
	int value;
	NodeLeaf* leftNode = nullptr;
	NodeLeaf* rightNode = nullptr;

	NodeLeaf(int value);
};

class BinarySearchTree : BaseDataStructure
{
public:
	BinarySearchTree(int value);
	~BinarySearchTree();
	void insertNode(int value);
	bool searchNode(int value);
	void deleteNode(int value);
	void printStructure() override;
	static BinarySearchTree* exampleBST();
	NodeLeaf* getMinValue();

private:
	NodeLeaf* m_root;
	void printTreeInOrder(NodeLeaf* root, int level = 0, const std::string& prefix = "Root: ");
	void _insertNode(NodeLeaf* root, int value);
	NodeLeaf* _deleteNode(NodeLeaf* root, int value);
	void deleteTree(NodeLeaf* root);
	NodeLeaf* _getMinValue(NodeLeaf* root);

	
};