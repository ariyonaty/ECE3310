#include <iostream>
#include <cstdlib>

#include "bst.h"

BST::BST()
{
    root = nullptr;
}

BST::node *BST::CreateLeaf(int key)
{
    node *n = new node();
    n->key = key;

    return n;
}

void BST::AddLeaf(int key)
{
    AddLeaf(key, root);
}

void BST::AddLeaf(int key, node *p)
{
    if (!root)
        root = CreateLeaf(key);

    else if (key < p->key)
    {
        if (p->left)
        {
            AddLeaf(key, p->left);
        }
        else
        {
            p->left = CreateLeaf(key);
        }
    }
    else if (key > p->key)
    {
        if (p->right)
        {
            AddLeaf(key, p->right);
        }
        else
        {
            p->right = CreateLeaf(key);
        }
    }
    else
    {
        std::cout << "The key " << key << "has already been added to tree." << std::endl;
    }
}
