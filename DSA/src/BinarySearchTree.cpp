#include <iostream>
#include <string>
#include <vector>

#include "BinarySearchTree.h"


NodeLeaf::NodeLeaf(int value)
	: value(value){}


BinarySearchTree::BinarySearchTree(int value)
	: m_root(new NodeLeaf(value)){}

BinarySearchTree::~BinarySearchTree() {
	deleteTree(m_root);
}

void BinarySearchTree::_insertNode(NodeLeaf* root, int value)
{
	NodeLeaf* currentNode = root;

	while (true)
	{
		if (value < currentNode->value)
		{
			if (currentNode->leftNode == nullptr)
			{
				currentNode->leftNode = new NodeLeaf(value);
				break;
			}

			currentNode = currentNode->leftNode;
		}
		else
		{
			if (currentNode->rightNode == nullptr)
			{
				currentNode->rightNode = new NodeLeaf(value);
				break;
			}

			currentNode = currentNode->rightNode;
		}
	}
}


void BinarySearchTree::insertNode(int value)
{
	_insertNode(m_root, value);
}

bool BinarySearchTree::searchNode(int value)
{
	NodeLeaf* currentNode = m_root;

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


NodeLeaf* BinarySearchTree::_deleteNode(NodeLeaf* root, int value)
{
		if (root == nullptr) {
			return root;
		}

		if (value < root->value) {
			root->leftNode = _deleteNode(root->leftNode, value);
		}
		else if (value > root->value) {
			root->rightNode = _deleteNode(root->rightNode, value);
		}
		else {
			// Node with only one child or no child
			if (root->leftNode == nullptr) {
				NodeLeaf* temp = root->rightNode;
				delete root;
				return temp;
			}
			else if (root->rightNode == nullptr) {
				NodeLeaf* temp = root->leftNode;
				delete root;
				return temp;
			}

			// Node with two children: Get the in-order successor (smallest in the right subtree)
			NodeLeaf* temp = _getMinValue(root->rightNode);

			// Copy the successor's value to the current node
			root->value = temp->value;

			// Delete the in-order successor
			root->rightNode = _deleteNode(root->rightNode, temp->value);
		}

		return root;
}

void BinarySearchTree::deleteNode(int value)
{
	m_root = _deleteNode(m_root, value);
}
NodeLeaf* BinarySearchTree::getMinValue()
{
	return _getMinValue(m_root);
}

NodeLeaf* BinarySearchTree::_getMinValue(NodeLeaf* root) {
	if (root == nullptr) {
		return nullptr;
	}

	while (root->leftNode != nullptr) {
		root = root->leftNode;
	}

	return root;
}


void BinarySearchTree::printTreeInOrder(NodeLeaf* root, int level, const std::string& prefix)
{
	if (root != nullptr) {
		std::cout << std::string(level * 4, ' ') << prefix << root->value << std::endl;
		printTreeInOrder(root->leftNode, level + 1, "L--- ");
		printTreeInOrder(root->rightNode, level + 1, "R--- ");
	}
}

void BinarySearchTree::printStructure()
{
	printTreeInOrder(m_root);
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


void BinarySearchTree::deleteTree(NodeLeaf* root)
{
	if (root == nullptr) return;

	deleteTree(root->leftNode);
	deleteTree(root->rightNode);

	delete root;
}

