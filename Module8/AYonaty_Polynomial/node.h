#ifndef NODE_H
#define NODE_H

class Node
{
public:
    int coeff;
    int exp;
    Node* next;

    void printNode();

    Node();
    Node(int c, int e);
};

#endif /* NODE_H */