/*
* Ari Yonaty
* ECE3310
* 10.10.2020
* Project 2
* Linked List Project
*/

#include <iostream>
#include "poly.h"

int main(void)
{
    std::cout << "*********************************************" << std::endl;
    std::cout << "************ LINKED LIST PROJECT ************" << std::endl;
    std::cout << "*********************************************" << std::endl;

    Poly poly1, poly2, polyRes;

    poly1.insert(1, 0);
    poly1.insert(2, 3);
    poly1.insert(3, 12);
    poly1.insert(4, 25);
    poly1.insert(5, 99);

    poly2.insert(1, 0);
    poly2.insert(9, 4);
    poly2.insert(13, 12);

    polyRes.add(poly1, poly2);

    std::cout << "p1(x) = ";
    poly1.printPoly();

    std::cout << "p2(x) = ";
    poly2.printPoly();

    std::cout << "[+] Adding poly1 and poly2..." << std::endl;
    std::cout << "p3(x) = p1(x) + p2(x) \n\t= ";
    polyRes.printPoly();

    /**** Demonstrating deletion ****/
    std::cout << "[-] Deleting first node..." << std::endl;
    std::cout << "p3(x) = ";
    polyRes.deleteFront();
    polyRes.printPoly();

    std::cout << "[-] Deleting node following 3rd node..." << std::endl;
    std::cout << "p3(x) = ";
    Node* pn1 = polyRes.phead->next->next;
    polyRes.deleteNode(&pn1->next);
    polyRes.printPoly();

    return EXIT_SUCCESS;
}
