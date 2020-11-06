#ifndef NODE_H
#define NODE_H

class Node
{
public:
    char letter;
    int x_coor;
    int y_coor;
    Node* next;
    Node* prev;

    Node(char, int, int);
};

#endif /* NODE_H */