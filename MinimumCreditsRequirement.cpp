#include "MinimumCreditsRequirement.h"
#include"MinimumCreditsException.h"

MinimumCreditsRequirement::MinimumCreditsRequirement(unsigned minCredits):
    AdmissionRequirement()
{
    if (minCredits == 0)
    {
        throw MinimumCreditsException();
    }
}

RequirmentResult MinimumCreditsRequirement::check(const Student& student) const
{
    if (student.getCredits() >= minCredits)
    {
        return { true,"Student has enough credits!" };
    }
    
    return { false,"Student does not have enough credits." };
}
