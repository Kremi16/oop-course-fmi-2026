#pragma once
#include"AdmissionRequirement.h"

class MinGradeRequirment:public AdmissionRequirement
{
private:
	double minGrade;

public:
	explicit MinGradeRequirment(double minGrade);
	RequirmentResult check(const Student& student) const override;
};

