#include <iostream>
#include "llist.h"

int main(int argc, char const *argv[])
{
    Node *n1 = new Node(1);
    LList mylist;
    
    if (mylist.empty())
    {
        std::cout << "List is empty." << std::endl;
    }

    mylist.insertfirst(n1);
    mylist.insert(n1, NULL);
    mylist.display();

    return 0;
}
