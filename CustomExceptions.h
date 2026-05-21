#pragma once
#include<stdexcept>
#include<string>
using namespace std;

class CustomExceptions:public exception
{
private:
	string message;

public:
	virtual const char* what()const noexcept= 0;
	virtual ~CustomExceptions() = 0;
};

