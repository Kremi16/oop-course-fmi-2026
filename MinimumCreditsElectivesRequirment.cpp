#include "MinimumCreditsElectivesRequirment.h"
#include"ElectivesException.h"

MinimumCreditsElectivesRequirment::MinimumCreditsElectivesRequirment(unsigned minCredits):
	AdmissionRequirement()
{
	if (minCredits == 0)
	{
		throw ElectivesException();
	}
}

RequirmentResult MinimumCreditsElectivesRequirment::check(const Student& student) const
{
	unsigned count = student.getCreditsFromElectiveSubjects();
	if (count >= minCredits)
	{
		return { true,"Student has enough credits from elective subjects." };
	}
	return { false,"Student does not have enough credits from elective subjects." };
}
