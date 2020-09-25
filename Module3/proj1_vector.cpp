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

void printData(std::vector<StatePopulation> sp)
{
    for (int i = 0; i < sp.size(); i++)
    {
        std::cout << sp[i].name << " - " << sp[i].population << std::endl;
    }
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

    for (int i = 0; i < 9; i++) // Skip the first 9 lines of CSV
    {
        std::getline(file, str);
    }

    StatePopulation sp; // temporary state population struct object for getting data and manipulating.
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

    int sum = 0;
    double variance = 0;
    for (int i = 0; i < statePops.size(); i++)
    {
        sum += statePops[i].population;
    }

    std::sort(statePops.begin(), statePops.end(), comparePopulation);

    int mean = sum / statePops.size();
    int median = statePops[statePops.size() / 2].population;

    for (int i = 0; i < statePops.size(); i++)
    {
        variance += pow((statePops[i].population - mean), 2);
    }
    variance = variance / (statePops.size() - 1);
    double stdDeviation = sqrt(variance);

    std::cout << "*******************************" << std::endl;
    std::cout << "    US 2010 POPULATION DATA" << std::endl;
    std::cout << "*******************************" << std::endl;
    std::cout << "Mean: " << mean << std::endl;
    std::cout << "Median: " << median << std::endl;
    std::cout << "Variance: " << std::fixed << std::setprecision(2) << variance << std::endl;
    std::cout << "Standard Deviation: " << std::fixed << std::setprecision(2) << stdDeviation << std::endl;
    std::cout << "*******************************" << std::endl;

    return 0;
}
