#pragma once
#include<string>
#include"Utils.h"
using namespace std;

class Subject
{
private:
	string name;
	unsigned credits;
	Category category;
	bool mandatory;
	bool elective;

public:
	Subject() = default;
	Subject(const string& name, unsigned credits, Category category, bool mandatory,bool elective);

	const string& getName()const;
	Category getCategory()const;
	bool isMandatory()const;
	bool isElective()const;
	unsigned getCredits()const;
};

