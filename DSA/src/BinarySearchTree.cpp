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


void BinarySearchTree::deleteNode(int value, BinarySearchTree* parentNode)
{
	BinarySearchTree* currentNode = this;

	while (currentNode != nullptr)
	{
		if (value < currentNode->value)
		{
			parentNode = currentNode;
			currentNode = currentNode->leftNode;
		}
		else if (value > currentNode->value)
		{
			parentNode = currentNode;
			currentNode = currentNode->rightNode;
		}
		else {
			// both leaves are non-empty
			// search for the minimum value from the right leaf and set it as the currentNode's value
			// then remove the minimum value from the right subtree
			if (currentNode->leftNode != nullptr && currentNode->rightNode != nullptr)
			{
				currentNode->value = currentNode->rightNode->getMinValue();
				currentNode->rightNode->deleteNode(currentNode->value, currentNode);
			}

			// we have found the value and parentNode is nullptr,
			// indicating that we're not removing the minimum value
			else if (parentNode == nullptr)
			{

				// there are leaves on the left side
				// replace current node value with the left
				if (currentNode->leftNode != nullptr)
				{
					currentNode->value = currentNode->leftNode->value;
					currentNode->rightNode = currentNode->leftNode->rightNode;
					currentNode->leftNode = currentNode->leftNode->leftNode;
				}

				// there are leaves on the left side
				// replace current node value with the left
				else if (currentNode->rightNode != nullptr)
				{
					currentNode->value = currentNode->rightNode->value;
					currentNode->leftNode = currentNode->rightNode->leftNode;
					currentNode->rightNode = currentNode->rightNode->rightNode;
				}
			} 
			
			// we are removing the minimum value from the right side
			// parentNode's left or right leaf is nullptr
			else if (parentNode->leftNode == currentNode)
			{
				parentNode->leftNode = currentNode->leftNode != nullptr ? currentNode->leftNode
																		: currentNode->rightNode;
			} else if (parentNode->rightNode == currentNode) {
				parentNode->rightNode = currentNode->leftNode != nullptr ? currentNode->leftNode
																		: currentNode->rightNode;
			}

			break;
		}

	}
}


int BinarySearchTree::getMinValue()
{
	if (leftNode == nullptr)
	{
		return value;
	}
	else
	{
		return leftNode->getMinValue();
	}
}

void BinarySearchTree::printTreeInOrder(BinarySearchTree* root, int level, const std::string& prefix)
{
	if (root != nullptr) {
		std::cout << std::string(level * 4, ' ') << prefix << root->value << std::endl;
		printTreeInOrder(root->leftNode, level + 1, "L--- ");
		printTreeInOrder(root->rightNode, level + 1, "R--- ");
	}
}

void BinarySearchTree::printStructure()
{
	printTreeInOrder(this);
}

BinarySearchTree* BinarySearchTree::exampleBST()
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


void BinarySearchTree::deleteTree(BinarySearchTree* root)
{
	if (root == nullptr) return;

	deleteTree(root->leftNode);
	deleteTree(root->rightNode);

	delete root;
}