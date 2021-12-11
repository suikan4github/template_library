// Test cases for the calc class

#include "gtest/gtest.h"
#include "calc.hpp"
#include <stdexcept>

TEST(Calc, Sqrt)
{
    Calc calc;

    EXPECT_EQ(calc.sqrt(4.0), 2.0);
}

TEST(Calc, SqrtPrrecision)
{
    Calc calc;

    EXPECT_DOUBLE_EQ(calc.sqrt(2), 1.4142135623730951);
}
