#include <iostream>
#include "node.h"

Node::Node(int coeff, int exp)
{
    this->coeff = coeff;
    this->exp = exp;

    this->next = nullptr;
}