
#include <cmath>
#include <limits>
#include "dll.h"

DLL::DLL()
{
}

DLL::~DLL()
{
    while (count > 0)
        delete_front();
}

Node *DLL::insert(Node *p)
{
    std::cout << "[+] Inserting node " << p->letter << " into list" << std::endl;

    if (phead == nullptr)
    {
        insert_front(p);
    }
    else
    {
        double tempDistance = 0;
        double minDistance = std::numeric_limits<double>::max();
        Node *nearest = phead;
        Node *temp = phead;

        for (int i = 0; i < count; i++)
        {
            tempDistance = distance(p, temp);
            if (tempDistance < minDistance)
            {
                minDistance = tempDistance;
                nearest = temp;
            }
            temp = temp->next;
        }

        if (nearest->next == nullptr || nearest->prev == nullptr)
        {
            insert_after(p, nearest);
        }
        else
        {
            double distPrev = distance(p, nearest->prev);
            double distNext = distance(p, nearest->next);

            if (distPrev < distNext)
            {
                insert_after(p, nearest->prev);
            }
            else
            {
                insert_after(p, nearest);
            }
        }
    }
    return p;
}

double DLL::distance(Node *pNew, Node *pIter)
{
    int x1 = pNew->x_coor;
    int y1 = pNew->y_coor;
    int x2 = pIter->x_coor;
    int y2 = pIter->y_coor;

    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

Node *DLL::insert_front(Node *p)
{
    p->next = phead;

    if (p->next)
        p->next->prev = p;

    phead = p;

    if (ptail == nullptr)
        ptail = p;

    ++count;
    return p;
}

Node *DLL::insert_back(Node *p)
{
    p->prev = ptail;

    if (p->prev)
        p->prev->next = p;

    ptail = p;

    if (phead == nullptr)
        phead = p;

    ++count;
    return p;
}

/**
 * Insert node p after pnode
 * 
 * @param   p - node to insert
 * @param   pnode - inserting p after pnode
 */
Node *DLL::insert_after(Node *p, Node *pnode)
{
    p->prev = pnode;
    p->next = pnode->next;

    pnode->next = p;

    if (p->next)
        p->next->prev = p;

    if (ptail == pnode)
        ptail = p;

    ++count;
    return p;
}

void DLL::delete_front()
{
    delete_node(phead);
}

void DLL::delete_back()
{
    delete_node(ptail);
}

void DLL::delete_node(Node *pnode)
{
    if (pnode == nullptr)
        return;
    if (pnode->next)
        pnode->next->prev = pnode->prev;
    if (pnode->prev)
        pnode->prev->next = pnode->next;
    if (phead == pnode)
        phead = pnode->next;
    if (ptail == pnode)
        ptail = pnode->prev;
    --count;
}

Node *DLL::front()
{
    return phead;
}

Node *DLL::back()
{
    return ptail;
}

Node *DLL::next(Node *pnode)
{
    return pnode->next;
}

Node *DLL::prev(Node *pnode)
{
    return pnode->prev;
}

void DLL::dump()
{
    std::cout << "************* list *************" << std::endl;
    std::cout << "head: " << phead << std::endl;
    std::cout << "tail: " << ptail << std::endl;

    Node *p = phead;
    while (p)
    {
        std::cout << "[+] node: " << p << std::endl;
        std::cout << "      next = " << p->next << std::endl;
        std::cout << "      prev = " << p->prev << std::endl;
        std::cout << "      coor = " << p->x_coor << ", " << p->y_coor << std::endl;

        p = p->next;
    }
}

void DLL::display()
{
    std::cout << "************* path *************" << std::endl;
    
    Node *p = phead;
    while(p)
    {
        std::cout << p->letter << "(" << p->x_coor << ", " << p->y_coor << ")";
        if (p->next)
            std::cout << " --> ";

        p = p->next;
    }
    std::cout << std::endl;
}