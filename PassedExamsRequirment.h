#pragma once
#include"AdmissionRequirement.h"

class PassedExamsRequirment:public AdmissionRequirement
{
private:
	vector<string> subjectNames;

public:
	RequirmentResult check(const Student& student) const override;
};

