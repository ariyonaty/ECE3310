/* 
    Ari Yonaty
    ECE3310
    8.27.2020
 */

#include <iostream>

int main(void)
{
    unsigned int i, *pI;
    unsigned short j, *pJ;
    unsigned long k, *pK;

    pI = &i;
    pJ = &j;
    pK = &k;

    std::cout << "Size of unsigned int: " << sizeof(i) << std::endl;
    std::cout << "Size of unsigned short: " << sizeof(j) << std::endl;
    std::cout << "Size of unsigned long: " << sizeof(k) << std::endl;

    return 0;
}
