#pragma once
#include"CustomExceptions.h"

class StudentNotFoundException :public exception
{
public:
	const char* what() const noexcept override;
};

