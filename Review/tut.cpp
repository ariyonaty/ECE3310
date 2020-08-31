
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <sstream>
#include <numeric>
#include <cstdlib>
#include <ctime>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<int> GenerateRandVec(int, int, int);

int main(int argc, char const *argv[])
{
    vector<int> vecVals = GenerateRandVec(10, 1, 50);

    int sum = 0;
    for_each(vecVals.begin(), vecVals.end(),
             [&](int x) { sum += x; });
    cout << "Sum: " << sum << endl;
}

vector<int> GenerateRandVec(int numOfNums, int min, int max)
{
    vector<int> vecValues;
    srand(time(NULL));
    int i = 0, randVal = 0;
    while (i < numOfNums)
    {
        randVal = min = rand() % ((max + 1) - min);
        vecValues.push_back(randVal);
        i++;
    }
    return vecValues;
}