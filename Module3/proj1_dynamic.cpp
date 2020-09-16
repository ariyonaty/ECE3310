#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

#define SIZE 51

struct StatePopulation
{
    std::string name;
    int population;
};

/* Print individual state population structure data */
void printData(StatePopulation sp)
{
    std::cout << sp.name << " - " << sp.population << std::endl;
}

bool comparePopulation(const StatePopulation &a, const StatePopulation &b)
{
    return a.population < b.population;
}

bool compareName(const StatePopulation &a, const StatePopulation &b)
{
    return a.name < b.name;
}

int main(int argc, char const *argv[])
{
    StatePopulation *statePops = new StatePopulation[51];

    std::ifstream file("nst-est2011-01.csv");

    if (!file.is_open())
    {
        std::cerr << "Error opening file." << std::endl;
    }

    std::string str;

    std::string area;
    int census, estimate, pop2010, pop2011;
    char delimiter;

    for (int i = 0; i < 9; i++)
    {
        std::getline(file, str);
    }

    std::string tmp;

    int i = 0;
    while (getline(file, str) && !str.empty() && (str != ",,,,"))
    {
        std::stringstream stream(str);
        std::getline(stream, tmp, ',');
        statePops[i].name = tmp.substr(1);
        std::getline(stream, tmp, ',');
        std::getline(stream, tmp, ',');
        std::getline(stream, tmp, ',');
        statePops[i].population = std::stoi(tmp);
        std::getline(stream, tmp, ',');
        if (!stream)
            break;

        i++;
    }

    int sum = 0;
    double variance = 0;

    std::sort(statePops, statePops + SIZE, comparePopulation); // sort by population size

    for (int i = 0; i < SIZE; i++)
    {
        sum += statePops[i].population;
    }

    int mean = sum / SIZE;
    int median = statePops[51 / 2].population;

    for (int i = 0; i < SIZE; i++)
    {
        variance += pow((statePops[i].population - mean), 2);
    }
    variance = variance / (SIZE - 1);
    double stdDeviation = sqrt(variance);

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
