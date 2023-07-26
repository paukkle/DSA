#include <iostream>

#include "BinarySearchTree.h"
#include "Choices.h"


int main()
{
    
    BinarySearchTree* bst = BinarySearchTree::exampleBST();
    bst->printStructure();

    std::cout << bst->searchNode(0) << std::endl;

    BSTChoices bstChoices = BSTChoices();

    //bstChoices.getChoice();

    bst->deleteNode(5);
    bst->printStructure();
}