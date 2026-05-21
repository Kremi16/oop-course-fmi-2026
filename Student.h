#pragma once
#include<vector>
#include<memory>
#include"Subject.h"

class Student
{
private:
	string facultyNumber;
	string name;
	vector<unique_ptr<Subject>> passedSubjects;
	unsigned collectedCredits;
	double grade;

public:
	Student() = default;
	Student(const string& facultyNumber, const string& name, unsigned collectedCredits, double grade);

	unsigned getCredits()const;
	vector<unique_ptr<Subject>> getPassedSubjects()const;
	double getGrade()const;
	const string& getFacultyNumber()const;

	bool hasPassedSubject(const string& subject)const;
	unsigned countPassedSubjectsByCategory(Category category)const;
	unsigned getCreditsFromElectiveSubjects()const;
};

