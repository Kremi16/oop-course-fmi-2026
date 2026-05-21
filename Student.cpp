#include "Student.h"
#include<stdexcept>

Student::Student(const string& facultyNumber, const string& name, unsigned collectedCredits, double grade)
	:collectedCredits(collectedCredits)
{
	if (facultyNumber.empty())
	{
		throw invalid_argument("Faculty number cannot be an empty string.");
	}
	this->facultyNumber = facultyNumber;

	if (grade < 2.00 || grade>6.00)
	{
		throw invalid_argument("Invalid grade.");
	}
	this->grade = grade;
}

unsigned Student::getCredits()const
{
	return collectedCredits;
}

vector<unique_ptr<Subject>> Student::getPassedSubjects()const
{
	return passedSubjects;
}

bool Student::hasPassedSubject(const string& subjectName) const
{
	for (const auto& subject : passedSubjects)
	{
		if (subject->getName() == subjectName)
		{
			return true;
		}
	}
	return false;
}

unsigned Student::countPassedSubjectsByCategory(Category category) const
{
	return count(passedSubjects.begin(), passedSubjects.end(),
		[&category](const unique_ptr<Subject>& s)
		{
			return s->getCategory() == category;
		});
}

unsigned Student::getCreditsFromElectiveSubjects() const
{
	unsigned credits = 0;

	for (const auto& subject : passedSubjects)
	{
		if (subject->isElective())
		{
			credits += subject->getCredits();
		}
	}
	return credits;
}

double Student::getGrade()const
{
	return grade;
}

const string& Student::getFacultyNumber() const
{
	return facultyNumber;
}
