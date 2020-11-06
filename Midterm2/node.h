#ifndef NODE_H
#define NODE_H

class Node
{
public:
    int x_coor;
    int y_coor;
    Node* next;
    Node* prev;

    Node(int, int);
};

#endif /* NODE_H */