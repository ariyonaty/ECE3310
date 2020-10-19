/* 
    Ari Yonaty
    ECE3310
    10.14.2020
    Doubly Linked List
 */

#include <iostream>

struct node
{
    node *next = {nullptr};
    node *prev = {nullptr};
    int value;

    node(int i = 0)
    {
        value = i;
    }
};

class node_list
{
private:
    node *phead = {nullptr};
    node *ptail = {nullptr};
    size_t count = {0};

public:
    node_list()
    {
    }
    ~node_list()
    {
        while (count > 0)
            delete_front();
    }

    node *insert_front(int value)
    {
        node *p = new node(value);

        p->next = phead;

        if (p->next)
            p->next->prev = p; // link node #2 back to new node

        phead = p;

        if (ptail == nullptr) // special case inserting into empty list
            ptail = p;

        ++count;
        return p;
    }

    node *insert_back(int value)
    {
        node *p = new node(value);

        p->prev = ptail;

        if (p->prev)
            p->prev->next = p; // link node old tail to new tail node

        ptail = p;

        if (phead == nullptr) // special case inserting into empty list
            phead = p;

        ++count;
        return p;
    }

    node *insert_after(node *pnode, int value)
    {
        node *p = new node(value);

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

    void delete_front()
    {
        delete_node(phead);
    }

    void delete_back()
    {
        delete_node(ptail);
    }

    void delete_node(node *pnode)
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

    /**
     * @return Pointer to first node in list or nullptr if empty
     */
    node *front()
    {
        return phead;
    }

    /**
     * @return Pointer to last node in list or nullptr if empty
     */
    node *back()
    {
        return ptail;
    }

    /**
     * @return Pointer to node following pnode or nullptr 
     *  if pnode is tail node.
     */
    node *next(node *pnode)
    {
        return pnode->next;
    }

    /**
     * @return Pointer to node preceeding pnode or nullptr 
     *  if pnode is head node.
     */
    node *prev(node *pnode)
    {
        return pnode->prev;
    }

    void dump()
    {
        std::cout << "************* list *************" << std::endl;
        std::cout << "head: " << phead << std::endl;
        std::cout << "tail: " << ptail << std::endl;

        node *p = phead;
        while (p)
        {
            std::cout << "[+] node: " << p << std::endl;
            std::cout << "      next = " << p->next << std::endl;
            std::cout << "      prev = " << p->prev << std::endl;
            std::cout << "      data = " << p->value << std::endl;

            p = p->next;
        }
    }
};

int main()
{
    node_list n;

    n.dump();
    n.insert_front(1); // 1
    n.dump();
    node *pn2 = n.insert_front(2); // 2 -> 1
    n.dump();
    node *pn3 = n.insert_back(3); // 2 -> 1 -> 3
    n.dump();

    node *p = n.back(); // p will point to node #3
    std::cout << "back node: " << p << std::endl;

    p = n.prev(p); // p will point to node #1
    std::cout << "back-1 node: " << p << std::endl;

    n.insert_after(p, 4); // 2 -> 1 -> 4 -> 3
    n.dump();

    n.delete_back(); // 2 -> 1 -> 4
    n.dump();

    n.delete_front(); // 1 -> 4
    n.dump();

    n.delete_node(p); // 4
    n.dump();

    n.delete_front();
    n.dump();

    return 0;
}