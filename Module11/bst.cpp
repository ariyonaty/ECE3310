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

int BST::FindSmallest(node *p)
{
    if (!root)
    {
        std::cout << "The tree is empty." << std::endl;
        return -2;
    }
    else
    {
        if (p->left)
        {
            return FindSmallest(p->left);
        }
        else
        {
            return p->key;
        }
    }
}

int BST::FindSmallest()
{
    return FindSmallest(root);
}

void BST::RemoveNode(int key)
{
    RemoveNode(key, root);
}

void BST::RemoveNode(int key, node *parent)
{
    if (root)
    {
        if (root->key == key)
        {
            // RemoveRootMatch();
        }
        else
        {
            if (key < parent->key && parent->left)
            {
                parent->left->key == key ? RemoveMatch(parent, parent->left, true) : RemoveNode(key, parent->left);
            }
            else if (key > parent->key && parent->right)
            {
                parent->right->key == key ? RemoveMatch(parent, parent->right, false) : RemoveNode(key, parent->right);
            }
            else
            {
                std::cout << "Key not found in tree." << std::endl;
            }
        }
    }
    else
    {
        std::cout << "The tree is empty." << std::endl;
    }
}

void BST::RemoveRootMatch()
{
    if (root)
    {
        node *tmp = root;
        int rootKey = root->key;
        int smallestInRightSubtree;

        // Case 0: 0 children
        if (!root->left && !root->right)
        {
            root = nullptr;
            delete tmp;
        }
        // Case 1 - 1 child
        else if (!root->left && root->right)
        {
            root = root->right;
            tmp->right = nullptr;
            delete tmp;
            std::cout << "The root node with key " << rootKey << " was deleted. The new root contains key " << root->key << std::endl;
        }
        else if (root->left && !root->right)
        {
            root = root->left;
            tmp->left = nullptr;
            delete tmp;
            std::cout << "The root node with key " << rootKey << " was deleted. The new root contains key " << root->key << std::endl;
        }
        // Case 2 - 2 children
        else
        {
            smallestInRightSubtree = FindSmallest(root->right);
            RemoveNode(smallestInRightSubtree, root);
            root->key = smallestInRightSubtree;
            std::cout << "The root key with key " << rootKey << " was overwritten with key " << root->key << std::endl;
        }
    }
    else
    {
        std::cout << "Cannot remove root. Tree is empty." << std::endl;
    }
}

void BST::RemoveMatch(node *parent, node *match, bool left)
{
    if (root)
    {
        node *tmp;
        int matchKey = match->key;
        int smallestInRightSubtree;

        // Case 0: 0 children
        if (!match->left && !match->right)
        {
            tmp = match;
            left == true ? parent->left = nullptr : parent->right = nullptr;
            delete tmp;
            std::cout << "Node containing key " << matchKey << " was removed." << std::endl;
        }
        // Case 1: 1 child
        else if (!match->left && match->right)
        {
            left == true ? parent->left = match->right : parent->right = match->right;
            match->right = nullptr;
            tmp = match;
            delete tmp;
            std::cout << "Node containing key " << matchKey << " was removed." << std::endl;
        }
        else if (match->left && !match->right)
        {
            left == true ? parent->left = match->left : parent->right = match->left;
            match->left = nullptr;
            tmp = match;
            delete tmp;
            std::cout << "Node containing key " << matchKey << " was removed." << std::endl;
        }
        // Case 2: 2 children
        else
        {
            smallestInRightSubtree = FindSmallest(match->right);
            RemoveNode(smallestInRightSubtree, match);
            match->key = smallestInRightSubtree;
        }
    }
    else
    {
        std::cout << "Cannot remove match. Tree is empty." << std::endl;
    }
}