#ifndef NODE_H
#define NODE_H

class Node
{
public:
    int coeff;
    int exp;
    Node *next;
    Node(int coeff, int exp);
};

#endif /* NODE_H */
