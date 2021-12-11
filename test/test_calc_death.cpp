
#include "gtest/gtest.h"
#include "calc.hpp"
#include <stdexcept>

TEST(Calc, Death)
{
    Calc calc;

    ASSERT_DEATH(calc.sqrt(-1), "param >= 0");
}
