#pragma once
#include"CustomExceptions.h"

class MinimumGradeException:public exception
{
public:
	const char* what()const noexcept override;
};

