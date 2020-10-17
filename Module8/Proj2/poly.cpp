
#include <iostream>

class node
{
public:
    int coeff;
    int exponent;
    node *next;

    node()
    {
        next = nullptr;
    }

    node(int c, int e)
    {
        coeff = c;
        exponent = e;
        next = nullptr;
    }
};

class node_list
{
private:
    int count = {0};
    node *phead = {nullptr};

public:
    node_list()
    {
    }

    ~node_list()
    {
        while (count > 0)
            delete_front();
    }

    node *insert_front(int coeff, int exp)
    {
        node *p = new node(coeff, exp);

        p->next = phead;
        phead = p;

        ++count;
        return p;
    }

    node *insert(node *pnode, int coeff, int exp)
    {
        node *p = new node(coeff, exp);

        p->next = pnode->next;
        pnode->next = p;

        ++count;
        return p;
    }

    // node *insert(int coeff, int exp)
    // {
    //     node *p = new node(coeff, exp);
    // }

    void bubbleSort()
    {
        node **h;
        int i, j, swapped;

        for (i = 0; i <= count; i++)
        {

            h = &phead;
            swapped = 0;

            for (j = 0; j < count - i - 1; j++)
            {

                node *p1 = *h;
                node *p2 = p1->next;

                if (p1->exponent > p2->exponent)
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

    node *swap(node *n1, node *n2)
    {
        node *tmp = n2->next;
        n2->next = n1;
        n1->next = tmp;

        return n2;
    }

    void delete_front()
    {
        delete_node(phead);
    }

    void delete_node(node *pnode)
    {
        if (pnode == nullptr)
            return;

        if (phead == pnode)
            phead = pnode->next;
        --count;
    }

    void display()
    {
        std::cout << "************* list *************" << std::endl;
        std::cout << "head: " << phead << std::endl;

        node *p = phead;
        while (p)
        {
            std::cout << "[+] node: " << p << std::endl;
            std::cout << "      next = " << p->next << std::endl;
            std::cout << "     coeff = " << p->coeff << std::endl;
            std::cout << "       exp = " << p->exponent << std::endl;
            std::cout << "      term = " << p->coeff << "x^" << p->exponent << std::endl;

            p = p->next;
        }
    }

    bool is_empty()
    {
        return (phead == nullptr) ? true : false;
    }

    void empty()
    {
        if (this->phead == nullptr)
        {
            std::cout << "List is empty." << std::endl;
        }
        else
        {
            std::cout << "List not empty." << std::endl;
        }
    }

    void print_poly()
    {
        std::cout << "************* poly *************" << std::endl;

        node *p = phead;

        while (p)
        {
            std::cout << p->coeff << "x^" << p->exponent;
            p = p->next;
            if (p)
                std::cout << " + ";
        }
        std::cout << std::endl;
    }
};

int main(void)
{
    node_list n;

    // std::cout << "List Empty? " << std::boolalpha << n.is_empty() << std::endl;
    // n.empty();
    // n.display();
    node *n1 = n.insert_front(1, 0);
    // n.display();
    n.insert(n1, 2, 3);
    n.insert(n1, 2, 1);
    n.insert(n1, 3, 4);
    n.insert(n1, 3, 7);
    n.insert(n1, 3, 1);
    n.insert(n1, 3, 2);
    // n.display();

    n.print_poly();
    n.bubbleSort();
    n.print_poly();

    // std::cout << "List Empty? " << std::boolalpha << n.is_empty() << std::endl;
    // n.empty();

    return 0;
}