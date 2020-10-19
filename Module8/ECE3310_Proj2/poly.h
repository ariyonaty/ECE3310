#ifndef POLY_H
#define POLY_H

#include "node.h"

class Poly
{
private:
    int count = {0};
    // Node *phead = {nullptr};

    Node *swap(Node *n1, Node *n2);
    void sort();
    void simplify();
    bool isEmpty();

public:
    Poly();
    ~Poly();

    Node *phead = {nullptr};


    Node *insert(int c, int e);
    Node *insert(Node *pnode, int c, int e);

    void deleteFront();
    void deleteNode(Node **pnode);
    void add(Poly poly1, Poly poly2);
    void empty();
    void display();
    void printPoly();
};

#endif /* POLY_H */