
#include "gtest/gtest.h"
#include "calc.hpp"
#include <stdexcept>

// The name of the death test CASE have to  be .*DeathTest
// Read GoogleTest document https://github.com/google/googletest/blob/main/docs/advanced.md#death-test-naming
TEST(CalcDeathTest, SqrtWithMinusParam)
{
    Calc calc;
#ifndef NDEBUG
    // We test only when assert() works.
    ASSERT_DEATH(calc.sqrt(-1), "param >= 0");
#endif
}
