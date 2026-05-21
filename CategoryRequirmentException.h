#pragma once
#include"CustomExceptions.h"

class CategoryRequirmentException:public exception
{
public:
	const char* what()const noexcept override;
};

