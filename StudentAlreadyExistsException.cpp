#include "StudentAlreadyExistsException.h"

const char* StudentAlreadyExistsException::what() const noexcept
{
    return "Student with this faculty number already exists.";
}
