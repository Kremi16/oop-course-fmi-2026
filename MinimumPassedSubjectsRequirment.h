#pragma once
#include"AdmissionRequirement.h"

class MinimumPassedSubjectsRequirment:public AdmissionRequirement
{
private:
	Category category;
	unsigned minPassedSubjects;

public:
	MinimumPassedSubjectsRequirment(Category category, unsigned min);

	RequirmentResult check(const Student& student) const override;
};

