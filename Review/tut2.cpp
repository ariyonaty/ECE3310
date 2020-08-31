
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

#define PI 3.14159
#define AREA_CIRCLE(radius) (PI * pow(radius, 2))

template <typename T>
void Times2(T val)
{
    std::cout << val << " * 2 = " << val * 2 << std::endl;
}

template <typename T, typename U>
class Person
{
public:
    T height;
    U weight;
    static int numOfPeople;
    Person(T h, U w)
    {
        height = h, weight = w;
        numOfPeople++;
    }
    void getData()
    {
        std::cout << "Height: " << height << " and weight " << weight << std::endl;
    }
};
template <typename T, typename U>
int Person<T, U>::numOfPeople;

int main(int argc, char const *argv[])
{
    std::ofstream writeToFile;
    std::ifstream readFromFile;
    std::string txtToWrite = "";
    std::string txtFromFile = "";

    writeToFile.open("test.txt", std::ios_base::out | std::ios_base::trunc);
    if (writeToFile.is_open())
    {
        writeToFile << "Beginning of file\n";
        std::cout << "Enter data to write: ";
        std::getline(std::cin, txtToWrite);
        writeToFile << txtToWrite << std::endl;
        writeToFile.close();
    }

    std::cout << "--------------" << std::endl;

    readFromFile.open("test.txt", std::ios_base::in);
    if (readFromFile.is_open())
    {
        while (readFromFile.good())
        {
            getline(readFromFile, txtFromFile);
            std::cout << txtFromFile << std::endl;
        }
        readFromFile.close();
    }

    std::cout << AREA_CIRCLE(5) << std::endl;
    Times2(5);
    Times2(5.3);

    Person<double, int> mikeTyson(5.83, 216);
    mikeTyson.getData();

    std::deque<int> nums = {1, 2, 3, 4};
    nums.push_front(0);
    nums.push_back(5);
    for (int x : nums)
    {
        std::cout << x << std::endl;
    }

    std::vector<int> nums2 = {1, 2, 3, 4};
    std::vector<int>::iterator itr;
    for (itr = nums2.begin(); itr < nums2.end(); itr++)
    {
        std::cout << *itr << std::endl;
    }

    return 0;
}
