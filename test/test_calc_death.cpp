
#include "gtest/gtest.h"
#include "calc.hpp"
#include <stdexcept>

TEST(Calc, Death)
{
    Calc calc;
#ifndef NDEBUG
    // We test only when assert() works.
    ASSERT_DEATH(calc.sqrt(-1), "param >= 0");
#endif
}
