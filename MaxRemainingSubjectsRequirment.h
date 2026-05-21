#pragma once
#include"AdmissionRequirement.h"

class MaxRemainingSubjectsRequirment:public AdmissionRequirement
{
private:
	static constexpr unsigned MAX_VALUE = 4;
	unsigned maxRemaining;
	vector<unique_ptr<Subject>> allElectiveSubjects;

public:
	MaxRemainingSubjectsRequirment(unsigned maxRemaining,
		vector<unique_ptr<Subject>> allElectiveSubjects);
	RequirmentResult check(const Student& student) const override;
};

