
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

    node *insert(int coeff, int exp)
    {
        node *p = new node(coeff, exp);

        p->next = phead;
        phead = p;

        ++count;
        return p;
    }

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

    void add(node_list poly1, node_list poly2)
    {
        int coeff;
        int exp;

        node *p1 = poly1.phead;
        node *p2 = poly2.phead;

        while (p1 && p2)
        {
            if (p1->exponent == p2->exponent)
            {
                coeff = p1->coeff + p2->coeff;
                exp = p1->exponent;
                p1 = p1->next;
                p2 = p2->next;
            }
            else if (p1->exponent > p2->exponent)
            {
                coeff = p1->coeff;
                exp = p1->exponent;
                p1 = p1->next;
            }
            else if (p1->exponent < p2->exponent)
            {
                coeff = p2->coeff;
                exp = p2->exponent;
                p2 = p2->next;
            }
            this->insert(coeff, exp);
        }
        if (p1 == nullptr)
        {
            while (p2)
            {
                coeff = p2->coeff;
                exp = p2->exponent;
                p2 = p2->next;
                this->insert(coeff, exp);
            }
        }
        else if (p2 == nullptr)
        {
            while (p1)
            {
                coeff = p1->coeff;
                exp = p1->exponent;
                p1 = p1->next;
                this->insert(coeff, exp);
            }
        }
    }

    void removeDuplicates()
    {

        node *ptr1, *ptr2, *dup;
        ptr1 = this->phead;

        /* Pick elements one by one */
        while (ptr1 != NULL && ptr1->next != NULL)
        {
            ptr2 = ptr1;

            // Compare the picked element
            // with rest of the elements
            while (ptr2->next != NULL)
            {

                // If powerer of two elements are same
                if (ptr1->exponent == ptr2->next->exponent)
                {

                    // Add their coefficients and put it in 1st element
                    ptr1->coeff = ptr1->coeff + ptr2->next->coeff;
                    dup = ptr2->next;
                    ptr2->next = ptr2->next->next;

                    // remove the 2nd element
                    delete (dup);
                    --count;
                }
                else
                    ptr2 = ptr2->next;
            }
            ptr1 = ptr1->next;
        }
    }
    /**
     * Display list node-by-node
     * Used for debugging.
     */
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

    void simplify()
    {
        node *current = phead;
        node *newNode = new node();
        node *newHead = newNode;
        int coefficentSum, maxExponent;

        if (current != NULL)
        {
            coefficentSum = current->coeff;
            maxExponent = current->exponent;
        }

        while (current->next != NULL)
        {
            if (maxExponent == current->next->exponent)
            {
                coefficentSum += current->next->coeff;
                current = current->next;
            }

            if (current->next != NULL)
            {
                if (maxExponent > current->next->exponent)
                {
                    newNode->coeff = coefficentSum;
                    newNode->exponent = current->exponent;

                    node *simplify = new node();
                    newNode->next = simplify;
                    newNode = newNode->next;

                    maxExponent = current->next->exponent;
                    coefficentSum = current->next->coeff; // update sum
                    current = current->next;
                }
            }
        }

        newNode->coeff = coefficentSum;
        newNode->exponent = current->exponent;

        this->phead = newHead;
    }

    void print_poly()
    {
        std::cout << "************* poly *************" << std::endl;

        node *p = phead;

        while (p)
        {
            if (p->exponent == 0)
                std::cout << p->coeff;
            else
                std::cout << p->coeff << "x^" << p->exponent;
            p = p->next;
            if (p)
                std::cout << " + ";
        }
        std::cout << std::endl;
    }

    int getCount()
    {
        return count;
    }

    void simp()
    {
        node *tmp = phead;

        int merge = 0;

        while (tmp)
        {
            int exp = tmp->exponent;
            merge = tmp->coeff;
            node *tmp2 = tmp;
            tmp2 = tmp2->next;
            while (tmp2)
            {
                if (tmp2->exponent == tmp->exponent)
                {
                    merge += tmp2->coeff;
                }
                tmp2 = tmp2->next;
            }
            tmp->coeff = merge;
            tmp = tmp->next;
            merge = 0;
        }
    }
};

int main(void)
{
    /*     node_list poly1;

    // std::cout << "List Empty? " << std::boolalpha << n.is_empty() << std::endl;
    // n.empty();
    // n.display();
    node *n1 = poly1.insert_front(1, 0);
    // n.display();
    poly1.insert(n1, 2, 3);
    poly1.insert(n1, 2, 1);
    poly1.insert(n1, 3, 4);
    poly1.insert(n1, 3, 7);
    poly1.insert(n1, 3, 1);
    poly1.insert(n1, 3, 2);
    // n.display();

    // poly1.print_poly();
    poly1.bubbleSort();
    poly1.print_poly();

    // std::cout << "List Empty? " << std::boolalpha << n.is_empty() << std::endl;
    // n.empty();
    node_list poly2;
    poly2.insert(1, 2);
    poly2.insert(3, 4);
    poly2.insert(5, 6);

    // poly2.print_poly();
    poly2.bubbleSort();
    poly2.print_poly();

    node_list polyRes;
    std::cout << "------------------" << std::endl;
    polyRes.add(poly1, poly2);
    polyRes.print_poly();
    polyRes.bubbleSort();
    polyRes.print_poly();
    polyRes.simplify();
    polyRes.print_poly(); */

    node_list poly1, poly2, polyRes;
    poly1.insert(1, 0);
    poly1.insert(2, 3);
    poly1.insert(3, 12);
    poly1.insert(4, 25);
    poly1.insert(5, 99);
    poly1.bubbleSort();
    poly1.print_poly();

    poly2.insert(1, 0);
    poly2.insert(9, 4);
    poly2.insert(13, 12);
    poly2.bubbleSort();
    poly2.print_poly();

    polyRes.add(poly1, poly2);
    polyRes.bubbleSort();
    polyRes.print_poly();
    // polyRes.simp();
    // polyRes.print_poly();
    // polyRes.simplify();
    polyRes.removeDuplicates();

    polyRes.print_poly();
    // polyRes.display();

    return 0;
}