#pragma once
#include<string>
using namespace std;

enum class Category
{
	Informatics,
	Mathemathics,
	SoftwareEngineering,
	AppliedMathemathics,
	Other
};

struct RequirmentResult
{
	bool passed;
	string message;
};

