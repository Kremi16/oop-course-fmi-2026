#pragma once
#include"AdmissionRequirement.h"

class MinimumCreditsRequirement:public AdmissionRequirement
{
private:
	unsigned minCredits;

public:
	explicit MinimumCreditsRequirement(unsigned minCredits);

	RequirmentResult check(const Student& student) const override;
};

