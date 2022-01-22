/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-01-22
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <thread>
#include "calc.hpp"

/**
 * @brief  Calculate the square root of 1 to the given num.
 *
 * @param num From 1 to this number are calculated
 */
void CalcSqrt(int num)
{
    Calc calc;

    // count from 1 to num
    for (int i = 1; i <= num; i++)
        std::cout << "[CalcSqrt] The square root of " << i << " is " << calc.sqrt(i) << std::endl;
}

/**
 * @brief Main function
 *
 * @return int always return 0
 */
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