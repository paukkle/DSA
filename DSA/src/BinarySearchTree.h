#pragma once

#include "BaseDataStructure.h"
#include <string>


class NodeLeaf
{
	int value;
	NodeLeaf* left = nullptr;
	NodeLeaf* right = nullptr;
};

class BinarySearchTree : BaseDataStructure
{
private:
	int value;
	BinarySearchTree* leftNode = nullptr;
	BinarySearchTree* rightNode = nullptr;
	void printTreeInOrder(BinarySearchTree* root, int level = 0, const std::string& prefix = "Root: ");

public:
	BinarySearchTree(int value);
	void insertNode(int value);
	bool searchNode(int value);
	void deleteNode(int value, BinarySearchTree* parentNode = nullptr);
	void deleteTree(BinarySearchTree* root);
	int getMinValue();
	void printStructure() override;
	static BinarySearchTree* exampleBST();
	
};