#pragma once
#include"Student.h"

class AdmissionRequirement
{
public:
	AdmissionRequirement() = default;
	virtual RequirmentResult check(const Student& student) const = 0;
	virtual ~AdmissionRequirement() = default;
};

