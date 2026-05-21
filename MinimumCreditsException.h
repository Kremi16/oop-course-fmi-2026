#pragma once
#include"CustomExceptions.h"

class MinimumCreditsException:public exception
{
public:
	const char* what() const noexcept override;
};

