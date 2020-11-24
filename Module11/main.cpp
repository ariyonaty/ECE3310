#include <iostream>
#include <cstdlib>

#include "bst.h"

int main(void)
{
    int TreeKeys[16] = {50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80};
    BST bst;

    std::cout << "[+] Printing tree in order before adding numbers" << std::endl;
    bst.PrintInOrder();

    for (int i = 0; i < 16; i++)
    {
        bst.AddLeaf(TreeKeys[i]);
    }

    std::cout << "[+] Printing tree in order after adding numbers" << std::endl;
    bst.PrintInOrder();

    // bst.PrintChildren(bst.ReturnRootKey());
    // for (int i = 0; i < 16; i++)
    // {
    //     bst.PrintChildren(TreeKeys[i]);
    //     std::cout << std::endl;
    // }

    std::cout << "Smallest value in tree: " << bst.FindSmallest() << std::endl;

    int input = 0;
    std::cout << "Enter key value to delete. Enter -1 to stop process." << std::endl;
    while (input != -1)
    {
        std::cout << "Delete Node: ";
        std::cin >> input;
        {
            if(input  != -1)
            {
                std::cout << std::endl;
                bst.RemoveNode(input);
                bst.PrintInOrder();
                std::cout << std::endl;
            }
        }
    }
    

    return EXIT_SUCCESS;
}