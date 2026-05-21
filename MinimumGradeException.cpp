#include "MinimumGradeException.h"

const char* MinimumGradeException::what() const noexcept
{
    return "Invalid average grade requirement configuration (must be between 2.00 and 6.00).";
}
