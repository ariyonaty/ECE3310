#include <iostream>

class Node
{
public:
    Node();
    Node(int, int);

    int exponent;
    int coefficient;

    Node *next;

    Node()
    {
        exponent = 0;
        coefficient = 0;
        next = nullptr;
    }
};

class List
{
public:
    node *head;
    int count;

    List()
    {
    }
}
