
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <sstream>
#include <fstream>
#include <numeric>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <deque>
#include <iterator>
#include <memory>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int amtToStore;
    std::cout << "How many numbers do you want to store? ";
    std::cin >> amtToStore;

    std::unique_ptr<int[]> pNums(new int[amtToStore]);
    if (pNums != NULL)
    {
        int i = 0;
        while (i < amtToStore)
        {
            std::cout << "Enter a number: ";
            std::cin >> pNums[i];
            i++;
        }
    }
    /* 
    // old method
    int *pNums;
    pNums = (int *)malloc(amtToStore * sizeof(int));

    <insert NULL conditional here>
    
    if (pNums != NULL)
    {
        int i = 0;
        while (i < amtToStore)
        {
            std::cout << "Enter a number: ";
            std::cin >> pNums[i];
            i++;
        }
    delete pNums;
    } */
    std::cout << "You entered these numbers: " << std::endl;
    for (int i = 0; i < amtToStore; i++)
    {
        std::cout << pNums[i] << std::endl;
    }

    return 0;
}
