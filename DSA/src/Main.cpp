#include <iostream>

#include "BinarySearchTree.h"
#include "Choices.h"


int main()
{
    
    BinarySearchTree* bst = BinarySearchTree::exampleBST();
    bst->printStructure();

    BSTChoices bstChoices = BSTChoices();

    //bstChoices.getChoice();

    int search = 10;

    std::cout << bst->searchNode(search) << std::endl;
    bst->deleteNode(search);
    std::cout << bst->searchNode(search) << std::endl;
    bst->printStructure();
    delete bst;

}