#include "Subject.h"
#include<stdexcept>

Subject::Subject(const string& name, unsigned credits, Category category, bool mandatory,bool elective)
	:credits(credits),category(category),mandatory(mandatory),elective(elective)
{
	if (name.empty())
	{
		throw invalid_argument("Subject name cannot be an empty string.");
	}

	this->name = name;
}

const string& Subject::getName() const
{
	return name;
}

Category Subject::getCategory() const
{
	return category;
}

bool Subject::isMandatory() const
{
	return mandatory;
}

bool Subject::isElective()const
{
	return elective;
}

unsigned Subject::getCredits()const
{
	return credits;
}