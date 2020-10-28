#include <iostream>
#include "poly.h"

/**
 * Default constructor
 */
Poly::Poly(/* args */)
{
}

/**
 * Deconstructor
 * Deletes each node.
 */
Poly::~Poly()
{
    while (count > 0)
        deleteFront();
}

/**
 * Insert node at aftert specified node.
 * Sorting occurs at insertion.
 *
 * @param pnode     pointer to next pointer to insert node
 * @param c         coefficient for new node
 * @param e         exponent for new node
 */
Node* Poly::insert(Node* pnode, int c, int e)
{
    Node* p = new Node(c, e);

    p->next = pnode->next;
    pnode->next = p;

    ++count;

    this->sort();
    return p;
}

/**
 * Insert node at head of list.
 * Sorting occurs at insertion.
 *
 * @param c         coefficient for new node
 * @param e         exponent for new node
 */
Node* Poly::insert(int c, int e)
{
    Node* p = new Node(c, e);

    p->next = phead;
    phead = p;

    ++count;

    this->sort();
    return p;
}

/**
 * Swaps positions of two nodes in linked list.
 *
 * @param n1        node 1 to swap
 * @param n2        node 2 to swap
 */
Node* Poly::swap(Node* n1, Node* n2)
{
    Node* tmp = n2->next;
    n2->next = n1;
    n1->next = tmp;

    return n2;
}

/**
 * Bubble sort algo to sort linked list in ascending exponent order
 */
void Poly::sort()
{
    Node** h;
    int i, j, swapped;

    for (i = 0; i <= count; i++)
    {

        h = &phead;
        swapped = 0;

        for (j = 0; j < count - i - 1; j++)
        {

            Node* p1 = *h;
            Node* p2 = p1->next;

            if (p1->exp > p2->exp)
            {

                /* update the link after swapping */
                *h = swap(p1, p2);
                swapped = 1;
            }

            h = &(*h)->next;
        }

        /* break if the loop ended without any swap */
        if (swapped == 0)
            break;
    }
}

/**
 * Delete first node in list
 */
void Poly::deleteFront()
{
    if (phead == nullptr)
        return;

    if (phead)
        phead = phead->next;

    --count;
}

/**
 * Delete a node from the list.
 *
 * @param pnode     A pointer to the next pointer in the node preceeding the node to delete.
 */
void Poly::deleteNode(Node** pnode)
{
    if (*pnode == nullptr)
        return;

    Node* tmp = *pnode;
    *pnode = (*pnode)->next;
    delete tmp;

    --count;
}

/**
 * Add two polynomials to third polynomial
 * Follows: result poly = poly1 + poly2
 *
 * @param poly1         first polynomial
 * @param poly2         second polynomial
 */
void Poly::add(Poly poly1, Poly poly2)
{
    int coeff, exp;

    Node* p1 = poly1.phead;
    Node* p2 = poly2.phead;

    while (p1 && p2)
    {
        if (p1->exp == p2->exp)
        {
            coeff = p1->coeff + p2->coeff;
            exp = p1->exp;
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp > p2->exp)
        {
            coeff = p1->coeff;
            exp = p1->exp;
            p1 = p1->next;
        }
        else if (p1->exp < p2->exp)
        {
            coeff = p2->coeff;
            exp = p2->exp;
            p2 = p2->next;
        }
        this->insert(coeff, exp);
    }
    if (p1 == nullptr)
    {
        while (p2)
        {
            coeff = p2->coeff;
            exp = p2->exp;
            p2 = p2->next;
            this->insert(coeff, exp);
        }
    }
    else if (p2 == nullptr)
    {
        while (p1)
        {
            coeff = p1->coeff;
            exp = p1->exp;
            p1 = p1->next;
            this->insert(coeff, exp);
        }
    }
    this->simplify();
}

/**
 * Simplifies single polynomial like terms (terms with same exponent)
 */
void Poly::simplify()
{
    Node* p1, * p2, * tmp;
    p1 = this->phead;

    /* Pick elements one by one */
    while (p1 && p1->next)
    {
        p2 = p1;

        // Compare the picked element
        // with rest of the elements
        while (p2->next)
        {

            // If powerer of two elements are same
            if (p1->exp == p2->next->exp)
            {

                // Add their coefficients and put it in 1st element
                p1->coeff = p1->coeff + p2->next->coeff;
                tmp = p2->next;
                p2->next = p2->next->next;

                // remove the 2nd element
                delete tmp;
                --count;
            }
            else
                p2 = p2->next;
        }
        p1 = p1->next;
    }
}

/**
 * Print the addresses and values of nodes in list.
 * Used for debugging purposes.
 */
void Poly::display()
{
    std::cout << "************* list *************" << std::endl;
    std::cout << "head: " << phead << std::endl;

    Node* p = phead;
    while (p)
    {
        std::cout << "[+] node: " << p << std::endl;
        std::cout << "      next = " << p->next << std::endl;
        std::cout << "     coeff = " << p->coeff << std::endl;
        std::cout << "       exp = " << p->exp << std::endl;
        std::cout << "      term = " << p->coeff << "x^" << p->exp << std::endl;

        p = p->next;
    }
}

/**
 * Checks if the polynomial list is empty
 *
 * @return      bool
 */
bool Poly::isEmpty()
{
    return (phead == nullptr) ? true : false;
}

/**
 * Output function for isEmpty()
 */
void Poly::empty()
{
    if (isEmpty())
    {
        std::cout << "List is empty." << std::endl;
    }
    else
    {
        std::cout << "List not empty." << std::endl;
    }
}

/**
 * Prints sorted polynomial
 */
void Poly::printPoly()
{
    Node* p = phead;

    while (p)
    {
        if (p->exp == 0)
            std::cout << p->coeff;
        else
            std::cout << p->coeff << "x^" << p->exp;
        p = p->next;
        if (p)
            std::cout << " + ";
    }
    std::cout << std::endl;
}