#include <iostream>

#include "BinarySearchTree.h"
#include "Choices.h"


BSTChoices::BSTChoices()
{
	m_choices = std::vector<std::string>{
		"Select your choice by: ",
		" 1. Print your current tree.",
		" 2. Add a number to the tree.",
		" 3. Search for a number.",
		" 4. Return to main window."
	};
}

int BSTChoices::getNumChoices()
{
	return m_choices.size() - 1;
}

int BSTChoices::getChoice()
{
	int choice = 0;

	for (auto choice : m_choices)
	{
		std::cout << choice << std::endl;
	}

	while ((choice < 1) || (choice > getNumChoices()))
	{
		std::cout << "\nWhich operation would you like to perform? ";
		std::cin >> choice;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << std::endl;
	return choice;

}
