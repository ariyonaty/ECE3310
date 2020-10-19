#include <iostream>
#include "llist.h"

LList::LList()
{
    first = NULL;
}

bool LList::empty()
{
    return (first == NULL) ? true : false;
}

void LList::insert(Node *newnode, Node *pred)
{
    if (pred != NULL)
    {
        newnode->next = pred->next;
        pred->next = newnode;
    }
    else
    {
        first = newnode;
    }
}

void LList::insertfirst(Node *newnode)
{
    first = newnode;
}

void LList::erase(Node *pred)
{
    Node *temp;
    temp = pred->next;
    pred->next = pred->next->next;
    temp->next = NULL;
}

void LList::display()
{
    Node *current = first;
    while (current != NULL)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}