#include "StudentNotFoundException.h"

const char* StudentNotFoundException::what() const noexcept
{
	return "Student not found.";
}
