#ifndef NODE_H
#define NODE_H

class Node
{
public:
    int coeff;
    int exp;
    Node *next;

    Node(int c, int e);
};

#endif