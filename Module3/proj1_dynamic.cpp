#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

struct StatePopulation
{
    std::string name;
    int population;
};

bool comparePopulation(const StatePopulation &a, const StatePopulation &b)
{
    return a.population < b.population;
}

bool compareName(const StatePopulation &a, const StatePopulation &b)
{
    return a.name < b.name;
}

/* Functions Prototypes */
void printData(StatePopulation sp);
void swap(int *x, int *y);
void bubbleSort(int arr[], int n);

int main(int argc, char const *argv[])
{
    int sum = 0, mean = 0, median = 0;
    int arrIndex = 0, arrSize = 0;
    double variance = 0, stdDeviation = 0;
    std::string str, tmp;

    std::ifstream file("nst-est2011-01.csv"); // open csv file

    if (!file.is_open()) // check if error occured when opening file
    {
        std::cerr << "Error opening file." << std::endl;
    }

    while (getline(file, str) && !str.empty() && (str != ",,,,")) // get number of states by checking start of line with '.' from CSV
    {
        if (str[0] == '.')
            arrSize++;
    }

    StatePopulation *statePops = new StatePopulation[arrSize]; // create dynamic array based on arrSize calculated above
    int *tempArray = new int[arrSize];

    file.seekg(0); // go back to line 1 of file

    while (getline(file, str) && !str.empty() && (str != ",,,,")) // parse CSV and store data in dynamic array
    {
        if (str[0] != '.')
            continue;

        std::stringstream stream(str);
        std::getline(stream, tmp, ',');
        statePops[arrIndex].name = tmp.substr(1);
        std::getline(stream, tmp, ',');
        std::getline(stream, tmp, ',');
        std::getline(stream, tmp, ',');
        statePops[arrIndex].population = std::stoi(tmp);
        sum += std::stoi(tmp);
        tempArray[arrIndex] = std::stoi(tmp);
        std::getline(stream, tmp, ',');
        if (!stream)
            break;

        arrIndex++;
    }

    /* More elegant way to sort entire strucutre */
    // std::sort(statePops, statePops + arrSize, comparePopulation); // sort by population size
    bubbleSort(tempArray, arrSize);

    mean = sum / arrSize;
    median = tempArray[arrSize / 2];

    for (int i = 0; i < arrSize; i++)
    {
        variance += pow((statePops[i].population - mean), 2);
    }
    variance = variance / (arrSize - 1);
    stdDeviation = sqrt(variance);

    /* Print Data */
    std::cout << "*******************************" << std::endl;
    std::cout << "    US 2010 POPULATION DATA" << std::endl;
    std::cout << "*******************************" << std::endl;
    std::cout << "Mean: " << mean << std::endl;
    std::cout << "Median: " << median << std::endl;
    std::cout << "Variance: " << std::fixed << std::setprecision(2) << variance << std::endl;
    std::cout << "Standard Deviation: " << std::fixed << std::setprecision(2) << stdDeviation << std::endl;
    std::cout << "*******************************" << std::endl;

    delete[] statePops;

    return 0;
}


void printData(StatePopulation sp)
{
    std::cout << sp.name << " - " << sp.population << std::endl;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}