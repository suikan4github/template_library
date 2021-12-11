#include <iostream>
#include <thread>
#include "calc.hpp"

// Calculate the square root of 1 to the given num.
void CalcSqrt(int num)
{
    Calc calc;

    // count from 1 to num
    for (int i = 1; i <= num; i++)
        std::cout << "[CalcSqrt] The square root of " << i << " is " << calc.sqrt(i) << std::endl;
}

int main()
{
    std::cout << "[main] Thread start." << std::endl;

    // run the CalcSaqrt() as thread. This is for the test of the std::thread functionality in the each platform
    std::thread t(CalcSqrt, 10);

    std::cout << "[main] Waiting for the end of thread." << std::endl;

    // wait for the end of thread execution.
    t.join();

    std::cout << "[main] Thread terminated." << std::endl;

    return 0;
}