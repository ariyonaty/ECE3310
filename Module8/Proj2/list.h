#ifndef LIST_H
#define LIST_H

class Node
{
public:
    int coeff;
    int exp;
    Node *next;
    Node(int coeff, int exp);
};

#endif /* LIST_H */
