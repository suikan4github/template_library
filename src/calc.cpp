#include "calc.hpp"
#include <assert.h>

double Calc::sqrt(double param)
{
    assert(param >= 0);

    return std::sqrt(param);
}
