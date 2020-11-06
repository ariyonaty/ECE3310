#ifndef DLL_H
#define DLL_H

#include <iostream>
#include "node.h"

class DLL
{
private:
    Node *phead = {nullptr};
    Node *ptail = {nullptr};
    size_t count = {0};

public:
    DLL();
    ~DLL();

    Node *insert(Node *p);
    Node *insert_front(Node *p);
    Node *insert_back(Node *p);
    Node *insert_after(Node *p, Node *pnode);

    void delete_front();
    void delete_back();
    void delete_node(Node*pnode);

    Node *front();
    Node *back();
    Node *next(Node *pnode);
    Node *prev(Node *pnode);

    double distance(Node *pNew, Node *pIter);

    void dump();
    void display();
};

#endif /* DLL_H */