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

/* static void print_list(node *phead, node *ptail)
{
    std::cout << "************* list *************" << std::endl;
    std::cout << "head: " << phead << std::endl;
    std::cout << "tail: " << ptail << std::endl;

    while (phead)
    {
        std::cout << "[+] node: " << phead << std::endl;
        std::cout << "      next = " << phead->next << std::endl;
        std::cout << "      prev = " << phead->prev << std::endl;
        std::cout << "      data = " << phead->value << std::endl;

        phead = phead->next;
    }
} */

class node_list
{
private:
    node *phead = {nullptr};
    node *ptail = {nullptr};
    size_t count = {0};

public:
    node_list(){};
    ~node_list()
    {
        // XXX empty list
    }

    node *insert_front(int value)
    {
        node *p = new node(value);
        // XXX
        return p;
    }

    node *insert_back(int value)
    {
        node *p = new node(value);
        // XXX
        return p;
    }

    node *insert_after(node *pnode, int value)
    {
        node *p = new node(value);
        // XXX
        return p;
    }

    void delete_front()
    {
    }

    void delete_back()
    {
    }

    void delete_node(node *pnode)
    {
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

        while (phead)
        {
            std::cout << "[+] node: " << phead << std::endl;
            std::cout << "      next = " << phead->next << std::endl;
            std::cout << "      prev = " << phead->prev << std::endl;
            std::cout << "      data = " << phead->value << std::endl;

            phead = phead->next;
        }
    }
};

int main()
{
    node_list n;

    n.dump();
    n.insert_front(1);          // 1
    n.dump();
    n.insert_front(2);          // 2 -> 1
    n.dump();       

    return 0;
}