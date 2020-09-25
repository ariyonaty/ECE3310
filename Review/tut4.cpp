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
#include <thread>
#include <chrono>
#include <mutex>

int GetRandom(int max)
{
    srand(time(NULL));
    return rand() % max;
}

void ExecuteThread(int id)
{
    auto nowTime = std::chrono::system_clock::now();
    time_t sleepTime = std::chrono::system_clock::to_time_t(nowTime);
    tm myLocalTime = *localtime(&sleepTime);
    std::cout << "Thread " << id << "Sleep Time: " << ctime(&sleepTime) << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(GetRandom(3)));
    nowTime = std::chrono::system_clock::now();
    sleepTime = std::chrono::system_clock::to_time_t(nowTime);
    std::cout << "Thread " << id << "Sleep Time: " << ctime(&sleepTime) << std::endl;
}

int main(int argc, char const *argv[])
{

    std::thread th1(ExecuteThread, 1);
    th1.join();

    std::thread th2(ExecuteThread, 2);
    th2.join();

    return 0;
}
