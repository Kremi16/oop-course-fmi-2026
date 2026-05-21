#pragma once
#include"AdmissionRequirement.h"

class PassedAllMandatorySubjectsRequirment:public AdmissionRequirement
{
private:
	vector<unique_ptr<Subject>> allMandatorySubjects;

public:
	PassedAllMandatorySubjectsRequirment(const vector<unique_ptr<Subject>>& mandatorySubjects);

	RequirmentResult check(const Student& student) const override;
};

