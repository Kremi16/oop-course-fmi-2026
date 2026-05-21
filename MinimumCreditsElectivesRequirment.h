#pragma once
#include"AdmissionRequirement.h"

class MinimumCreditsElectivesRequirment:public AdmissionRequirement
{
private:
	unsigned minCredits;

public:
	explicit MinimumCreditsElectivesRequirment(unsigned minCredits);

	RequirmentResult check(const Student& student) const override;
};

