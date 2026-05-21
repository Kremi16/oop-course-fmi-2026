#include "MinimumCreditsException.h"

const char* MinimumCreditsException::what() const noexcept
{
	return "Invalid minimum credits requirement configuration.";
}
