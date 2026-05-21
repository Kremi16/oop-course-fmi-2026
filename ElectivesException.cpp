#include "ElectivesException.h"

const char* ElectivesException::what() const noexcept
{
    return "Invalid electives requirement configuration.";
}
