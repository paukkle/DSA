#include <iostream>

#include "BinarySearchTree.h"
#include "Choices.h"


int main()
{
    BinarySearchTree* bst = exampleBST();
    printBinaryTreeInOrder(bst);

    std::cout << bst->searchNode(0) << std::endl;

    BSTChoices bstChoices = BSTChoices();

    bstChoices.getChoice();
}