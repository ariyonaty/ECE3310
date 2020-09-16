#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>

#define NUM_OF_STATES 50

struct StatePopulation
{
    std::string name;
    int population;
};

struct CsvData
{
    std::string area;
    int census;
    int estimate;
    int pop2010;
    int pop2011;
};

int main(int argc, char const *argv[])
{
    std::vector<StatePopulation> statePops;
    std::vector<CsvData> csvData(50);

    std::string area;
    int census;
    int estimate;
    int pop2010;
    int pop2011;

    std::ifstream data("nst-est2011-01.csv");

    if (!data.is_open())
    {
        std::cerr << "Error opening file." << std::endl;
    }

    std::string str;
    for (int i = 0; i < 9; i++)
    {
        std::getline(data, str);
    }
    
    while(std::getline(data, str) && (str != ",,,,"))
    {
        std::istringstream iss(str);
        // std::string token;
        // while (std::getline(iss, token, ','))
        // {
            
        // }

        while (iss >> area >> census >> estimate >> pop2010 >> pop2011)
        {
            statePops.push_back({area, pop2010});
        }

        // std::cout << std::endl;
    }

    for (int i = 0; i < statePops.size(); i++)
    {
        std::cout << statePops[i].name << " - " << statePops[i].population << std::endl;
    }

    data.close();

    return 0;
}
