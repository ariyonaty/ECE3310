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

/* Prototypes */
double AddNumbers(double, double);

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
    // trick to print 'true' or 'false' instead of '0' or '1'
    std::cout.setf(std::ios::boolalpha);

    /* Arrays */
    int arrNums[10] = {1};
    int arrNums2[] = {1, 2, 3};
    int arrNums3[5] = {8, 9};

    std::cout << "1st value: " << arrNums3[0] << std::endl;
    arrNums3[0] = 7;
    std::cout << "1st value: " << arrNums3[0] << std::endl;
    int arrNums4[2][2] = {{1, 2},
                          {3, 4}};

    std::cout << arrNums4[0][1] << std::endl;

    std::vector<int> vNums(2);
    vNums[0] = 1;
    vNums[1] = 2;
    vNums.push_back(3);
    std::cout << "Vector size: " << vNums.size() << std::endl;

    /* Looping */
    int i = 1;
    while (i <= 20)
    {
        if (i % 2 == 0)
            i++;
        if (i == 15)
            break;
        std::cout << i << std::endl;
        i++;
    }

    std::vector<std::string> words;
    std::stringstream ss("Some random words");
    std::string word;
    while (getline(ss, word, ' '))
    {
        words.push_back(word);
    }

    for (int i = 0; i < words.size(); i++)
    {
        std::cout << words[i] << std::endl;
    }

    int arr3[] = {1, 2, 3};
    for (auto x : arr3)
    {
        std::cout << x << std::endl;
    }

    srand(time(NULL));
    int secretNum = rand() % 11;
    int guess = 0;
    do
    {
        std::cout << "Guess the number: ";
        std::cin >> guess;
        if (guess < secretNum)
            std::cout << "Too small!\n";
        if (guess > secretNum)
            std::cout << "Too big!\n";
    } while (guess != secretNum);
    std::cout << "You guessed it!" << std::endl;

    /* Strings */
    std::string str1 = "I'm a string";
    std::cout << "Access by index: " << str1[0] << std::endl;
    std::cout << "Access by func: " << str1.front() << std::endl;
    std::cout << "Length: " << str1.length() << std::endl;

    std::string str2 = str1;
    std::string str3(str2, 4);
    str3.append("!");
    std::cout << "Substring: " << str2.substr(2, 4) << std::endl;

    char letterZ = 'z';
    char num5 = '5';
    char aSpace = ' ';
    std::cout << "Is z a letter or number? " << isalnum(letterZ) << std::endl;
    std::cout << "Is z a letter? " << isalpha(letterZ) << std::endl;
    std::cout << "Is z a number? " << isdigit(letterZ) << std::endl;

    std::cout << AddNumbers(1.2345, 1.8765) << std::endl;

    /* Pointers */
    int *pAge = NULL;
    pAge = &age;
    std::cout << "Address: " << pAge << std::endl;
    std::cout << "Value: " << *pAge << std::endl;

    int arr[] = {1, 2, 3, 4, 5};
    int *pArr = arr;
    std::cout << "1st val: " << pArr << std::endl;
    std::cout << "2nd val: " << ++pArr << std::endl;

    /* Exception Handling */
    double number3 = 10, number4 = 0;
    try
    {
        if (number4 == 0)
            throw "Division by Zero Error";
        else
            std::cout << number3 << " / " << number4 << " = " << number3 / number4 << std::endl;
    }
    catch (const char *exp)
    {
        std::cerr << exp << '\n';
    }

    return 0;
}

double AddNumbers(double num1 = 0, double num2 = 0)
{
    return num1 + num2;
}
