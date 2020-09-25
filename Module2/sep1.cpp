#include <iostream>
#include <climits>

int main(int argc, char const *argv[])
{
    int number = INT_MAX - 3;

    std::cout << "Max int: " << INT_MAX << std::endl;

    for (int i = 0; i < 7; i++, number++)
    {
        std::cout << "Number = " << number << std::endl;
    }

    return 0;
}
