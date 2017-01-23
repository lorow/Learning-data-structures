#include <iostream>
#include "BTree.h"

int main() {

    BTree *tree = new  BTree();
    tree->insert(20);
    std::cout<<"jesli dzewo dziala to wartosć wyniesie 20: "<<tree->searchKey(20);
}