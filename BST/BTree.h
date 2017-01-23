//
// Created by smyku on 23.01.2017.
//

#ifndef UNTITLED_BTREE_H
#define UNTITLED_BTREE_H

#include <list>
#include "Node.h"

class BTree
{

public:
    BTree();
    ~BTree();

    void insert(int key);
    Node *search(int key);
    int  searchKey(int key);
    void destroyTree();

private:
    void destroyTree(Node *leaf);
    void insert(int key, Node *leaf);
    Node *search(int key, Node *leaf);

    Node *root;

};


#endif //UNTITLED_BTREE_H
