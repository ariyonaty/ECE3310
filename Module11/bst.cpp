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

void BST::PrintInOrder()
{
    PrintInOrder(root);
    std::cout << std::endl;
}

void BST::PrintInOrder(node *p)
{
    if (root)
    {
        if (p->left)
        {
            PrintInOrder(p->left);
        }
        std::cout << p->key << " ";
        if (p->right)
        {
            PrintInOrder(p->right);
        }
    }
    else
    {
        std::cout << "The tree is empty." << std::endl;
    }
}

BST::node *BST::ReturnNode(int key)
{
    return ReturnNode(key, root);
}

BST::node *BST::ReturnNode(int key, node *p)
{
    if (p)
    {
        if (p->key == key)
        {
            return p;
        }
        else
        {
            if (key < p->key)
            {
                return ReturnNode(key, p->left);
            }
            else
            {
                return ReturnNode(key, p->right);
            }
        }
    }
    else
    {
        return nullptr;
    }
}

int BST::ReturnRootKey()
{
    if (root)
    {
        return root->key;
    }
    else
    {
        return -1;
    }
}

void BST::PrintChildren(int key)
{
    node *ptr = ReturnNode(key);

    if (ptr)
    {
        std::cout << "Parent Node = " << ptr->key << std::endl;

        ptr->left == nullptr ? std::cout << "Left child = nullptr" << std::endl : std::cout << "Left child = " << ptr->left->key << std::endl;
        ptr->right == nullptr ? std::cout << "Right child = nullptr" << std::endl : std::cout << "Right child = " << ptr->right->key << std::endl;
    }
    else
    {
        std::cout << "Key " << key << " is not in the tree." << std::endl;
    }
}