#include <iostream>
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

void printData(StatePopulation sp)
{
    std::cout << sp.name << " - " << sp.population << std::endl;
}

void printData(std::vector<StatePopulation> sp)
{
    for (int i = 0; i < sp.size(); i++)
    {
        std::cout << sp[i].name << " - " << sp[i].population << std::endl;
    }
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

    std::vector<StatePopulation> statePops;

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

    StatePopulation sp;
    std::string tmp;

    while (getline(file, str) && !str.empty() && (str != ",,,,"))
    {
        // std::cout << str << std::endl;
        std::stringstream stream(str);
        std::getline(stream, tmp, ',');
        sp.name = tmp.substr(1);
        std::getline(stream, tmp, ',');
        std::getline(stream, tmp, ',');
        std::getline(stream, tmp, ',');
        sp.population = std::stoi(tmp);
        std::getline(stream, tmp, ',');
        if (!stream)
            break;

        statePops.push_back(sp);
    }

    int arrPop[statePops.size()];

    int mean;
    int sum = 0;
    for (int i = 0; i < statePops.size(); i++)
    {
        sum += statePops[i].population;
        arrPop[i] = statePops[i].population;
    }

    // printData(statePops);
    std::cout << "*******************" << std::endl;
    std::sort(statePops.begin(), statePops.end(), comparePopulation);
    // printData(statePops);
    // std::cout << "*******************" << std::endl;
    // std::sort(statePops.begin(), statePops.end(), compareName);
    // printData(statePops);

    mean = sum / statePops.size();
    std::cout << "*******************" << std::endl;
    std::cout << "Mean: " << mean << std::endl;
    int median = statePops[statePops.size() / 2].population;
    std::cout << "Median: " << median << std::endl;

    double variance = 0;
    for (int i = 0; i < statePops.size(); i++)
    {
        variance += pow((statePops[i].population - mean), 2);
    }
    variance = variance / (statePops.size() - 1);
    std::cout << "Variance: " << std::fixed << variance << std::endl;
    double stdDeviation = sqrt(variance);
    std::cout << "Standard Deviation: " << std::fixed << stdDeviation << std::endl;
    

    return 0;
}