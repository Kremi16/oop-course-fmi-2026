#pragma once
#include"CustomExceptions.h"
#include<stdexcept>

class StudentAlreadyExistsException:public exception
{
public:
	const char* what() const noexcept override;
};

