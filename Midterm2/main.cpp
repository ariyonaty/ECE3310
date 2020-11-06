#include <iostream>
#include "dll.h"

int main(void)
{
    DLL list;

    Node *a = new Node(1, 3);
    Node *b = new Node(10, 8);
    Node *c = new Node(13, 4);
    Node *d = new Node(6, 6);
    Node *e = new Node(13, 7);
    Node *f = new Node(5, 1);
    Node *g = new Node(2, 9);

    list.dump();
    list.insert(a);
    list.insert(b);
    list.insert(c);
    list.insert(d);
    list.insert(e);
    list.insert(f);
    list.insert(g);
    list.dump();
    list.display();

    return EXIT_SUCCESS;
}

/* Order should follow:  

A -> F -> D -> G -> B -> C -> E

*/