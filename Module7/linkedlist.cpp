#include <iostream>

struct node
{
    node    *next;
    int     value;

    node (int i)
    {
        value = i;
        next = nullptr;
    }
};

/**
 * Print the addresses and values of node starting with p.
 * 
 * @param p     The address of the first node in the list to print.
 */
static void print_list(node *p)
{
    std::cout << "************* list *************" << std::endl;

    while(p)
    {
        std::cout << "[+] node: " << p << std::endl;
        std::cout << "next = " << p->next << std::endl;
        std::cout << "value = " << p->value << std::endl;

        p = p->next;
    }
}

/**
 * Insert a node into the list.
 * 
 * @param pp    A pointer to the next pointer in the node preceeding the new node.
 * @param pn    A pointer to the node to insert.
 */
static void insert_node(node **pp, node *pn)
{
    pn->next = *pp;
    *pp = pn;
}

/**
 * Delete a node from the list.
 * 
 * @param pp    A pointer to the next pointer in the node preceeding the node to delete.
 */
static void delete_node(node **pp)
{
    if (*pp == nullptr)     // make sure a node is being deleted
        return;

    node *ptemp = *pp;      // remember address of the node to delete
    *pp = (*pp)->next;      // remove node from list
    delete ptemp;           // delete node
}

/**
 * Demonstrate single linked list insertions/
 */
int main()
{
    node *phead = nullptr;

    print_list(phead);

    node *pn1 = new node(1);
    insert_node(&phead, pn1);

    node *pn2 = new node(2);
    insert_node(&phead, pn2);

    node *pn3 = new node(3);
    insert_node(&pn1->next, pn3);

    node *pn4 = new node(4);
    insert_node(&pn1->next, pn4); // 2 -> 1 -> 4 -> 3

    // delete the head node from list
    delete_node(&phead);
    print_list(phead);  // 1 -> 4 -> 3

    // delete non-head node following #1 from middle of list
    delete_node(&pn1->next);
    print_list(phead);  // 1 -> 3

    // delete all nodes in list
    while (phead)
        delete_node(&phead);

    print_list(phead);

    return 0;
}