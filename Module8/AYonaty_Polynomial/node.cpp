#include <iostream>
#include "node.h"

Node::Node()
{
    coeff = 0;
    exp = 0;
    next = nullptr;
}

Node::Node(int c, int e)
{
    coeff = c;
    exp = e;
    next = nullptr;
}

/**
 * Print Node data
 * Used for debugging.
 */
void Node::printNode()
{
    std::cout << "Node:\t" << coeff << "x^" << exp << std::endl;
}