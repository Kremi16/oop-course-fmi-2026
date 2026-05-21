#pragma once
#include"CustomExceptions.h"

class ElectivesException:public exception
{
public:
	const char* what()const noexcept override;
};

