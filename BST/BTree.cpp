//
// Created by smyku on 23.01.2017.
//

#include "BTree.h"

BTree::BTree() {
    root = nullptr;
}

BTree::~BTree() {
    destroyTree();
}

void BTree::destroyTree() {
    destroyTree(root);
}

void BTree::destroyTree(Node *leaf) {
    if (leaf != nullptr)
    {
        destroyTree(leaf->left);
        destroyTree(leaf->right);
        delete leaf;
    }
}

void BTree::insert(int key) {
    if (root != nullptr)
    {
        insert(key, root);
    }
    else
    {
        root = new Node;
        root->value = key;
        root->left = nullptr;
        root->right = nullptr;
    }
}

void BTree::insert(int key, Node *leaf) {
    if (key < leaf->value)
    {
       if (leaf->left != nullptr)
        {
            insert(key, leaf->left);
        }
       else
       {
           leaf->left = new Node;
           leaf->left->value = key;
           leaf->left->left = nullptr;
           leaf->left->right = nullptr;
       }
    }
    else if (key >= leaf->value)
    {
        if (leaf->right != nullptr)
        {
            insert(key, leaf->right);
        }
        else
        {
            leaf->right = new Node;
            leaf->right->value = key;
            leaf->right->left = nullptr;
            leaf->right->right = nullptr;
        }
    }
}

Node *BTree::search(int key, Node *leaf) {

    if (leaf != nullptr)
    {
        if (key == leaf->value)
            return leaf;
        if (key < leaf->value)
            return search(key, leaf->left);
        else
            return search(key, leaf->right);
    }
    return nullptr;
}

Node *BTree::search(int key) {
    return search(key, root);
}

int BTree::searchKey(int key) {

    Node *searchNode = new Node;
    searchNode = search(key, root);

    if(searchNode != nullptr)
        return searchNode->value;
    return 0;
}

