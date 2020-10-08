#pragma once
#include "node.h"

class LList
{
    public:
        Node *first;
        LList();
        bool empty();
        void insert(Node *newnode, Node *pred);
        void insertfirst(Node *newnode);
        void erase(Node *pred);
        void display();
};