/**
* Ari Yonaty
* ECE3310
* Midterm 2
* 11.5.2020
*/

#include <iostream>
#include "dll.h"

int main(void)
{
    std::cout << "--------------------------" << std::endl;
    std::cout << "\tMIDTERM 2" << std::endl;
    std::cout << "--------------------------" << std::endl;
    
    DLL list;

    Node *a = new Node('A', 1, 3);
    Node *b = new Node('B', 10, 8);
    Node *c = new Node('C', 13, 4);
    Node *d = new Node('D', 6, 6);
    Node *e = new Node('E', 13, 7);
    Node *f = new Node('F', 5, 1);
    Node *g = new Node('G', 2, 9);

    list.insert(a);
    list.insert(b);
    list.insert(c);
    list.insert(d);
    list.insert(e);
    list.insert(f);
    list.insert(g);

    std::cout << "\n[+] The travel path is: " << std::endl;
    list.display();

    return EXIT_SUCCESS;
}

/* Order should follow:  

A -> F -> D -> G -> B -> C -> E

*/