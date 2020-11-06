#include <iostream>
#include "node.h"

Node::Node(char letter, int x = 0, int y = 0)
{
    this->letter = letter;
    this->x_coor = x;
    this->y_coor = y;
}

