/* 
    Ari Yonaty
    C++ Review
 */

// This is a single line comment
/* 
    This
    is
    a 
    multiline
    comment
  */

#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <sstream>
#include <numeric>
#include <cstdlib>
#include <ctime>
#include <cmath>

int imGlobal = 0;
const double PI = 3.1415;

int main(int argc, char const *argv[])
{
    std::cout << "Hello, World!" << std::endl;

    bool married = false;
    char myGrade = 'A';

    auto whatAmI = true;

    std::string q1 = "Enter a number : ";
    std::string num1;
    int num2;
    std::cout << q1;
    std::cin >> num1;
    std::cin >> num2;
    std::cout << "Num1: " << num1 << " ; " << sizeof(num1) << std::endl;
    std::cout << "Num2: " << num2 << " ; " << sizeof(num2) << std::endl;

    /* Conditionals */
    int age;
    std::cout << "Enter your age: ";
    std::cin >> age;

    if ((age >= 1) && (age <= 18))
        std::cout << "This is an imporant birthday!" << std::endl;

    bool canIVote = (age >= 18) ? true : false;

    

    return 0;
}
