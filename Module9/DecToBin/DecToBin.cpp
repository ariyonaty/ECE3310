/*
* Ari Yonaty
* ECE3310
* 10.27.2020
* Linked List Stack
* -- Dec to Bin
*/

#include <iostream>
#include "stack.h"

int main(void)
{
	Stack myStack = Stack();

    int num, remainder;
    std::cout << "*******************************" << std::endl;
    std::cout << "****** Decimal to Binary ******" << std::endl;
    std::cout << "*******************************" << std::endl;
    std::cout << "Enter a decimal number: ";

    std::cin >> num;

    while (num > 0)
    {
        remainder = num % 2;
        num = num / 2;
        myStack.push(remainder);
    }

    std::cout << "Binary Equivalent: ";
    myStack.output();

	return EXIT_SUCCESS;
}