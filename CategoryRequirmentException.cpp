#include "CategoryRequirmentException.h"

const char* CategoryRequirmentException::what() const noexcept
{
    return "Invalid category subjects requirement configuration.";
}
