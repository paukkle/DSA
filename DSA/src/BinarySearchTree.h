#pragma once


struct BinarySearchTree
{
	int value;
	BinarySearchTree* leftNode = nullptr;
	BinarySearchTree* rightNode = nullptr;

	BinarySearchTree(int value);
	void insertNode(int value);
	bool searchNode(int value);
};

void printBinaryTreeInOrder(BinarySearchTree* root, int level = 0, const std::string& prefix = "Root: ");
BinarySearchTree* exampleBST();