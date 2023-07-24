#include <iostream>
#include <string>
#include <vector>

#include "BinarySearchTree.h"


BinarySearchTree::BinarySearchTree(int value)
	: value(value) {}

void BinarySearchTree::insertNode(int value)
{
	BinarySearchTree* currentNode = this;

	while (true)
	{
		if (value < currentNode->value)
		{
			if (currentNode->leftNode == nullptr)
			{
				currentNode->leftNode = new BinarySearchTree(value);
				break;
			}

			currentNode = currentNode->leftNode;
		}
		else
		{
			if (currentNode->rightNode == nullptr)
			{
				currentNode->rightNode = new BinarySearchTree(value);
				break;
			}

			currentNode = currentNode->rightNode;
		}
	}
}

bool BinarySearchTree::searchNode(int value)
{
	BinarySearchTree* currentNode = this;

	while (currentNode != nullptr)
	{
		if (value < currentNode->value)
		{
			currentNode = currentNode->leftNode;
		}
		else if (value > currentNode->value)
		{
			currentNode = currentNode->rightNode;
		}
		else
		{
			return true;
		}
	}

	return false;

}


void printBinaryTreeInOrder(BinarySearchTree* root, int level, const std::string& prefix)
{
	if (root != nullptr) {
		std::cout << std::string(level * 4, ' ') << prefix << root->value << std::endl;
		printBinaryTreeInOrder(root->leftNode, level + 1, "L--- ");
		printBinaryTreeInOrder(root->rightNode, level + 1, "R--- ");
	}
}


BinarySearchTree* exampleBST()
{
	std::vector<int> values = {
		5, 15, 2, 5, 13, 22, 1, 14, 12
	};

	BinarySearchTree* bst = new BinarySearchTree(10);

	for (int value : values)
	{
		bst->insertNode(value);
	}

	return bst;
}