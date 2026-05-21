#include "AdmissionService.h"

void AdmissionService::addRequirement(const shared_ptr<AdmissionRequirement>& requirement)
{
	requirements.push_back(requirement);
}

AdmissionReport AdmissionService::checkStudent(const Student& student) const
{
    AdmissionReport report;

    for (const auto& req : requirements)
    {
        RequirmentResult result = req->check(student);

        if (!result.passed)
        {
            report.addFailure(result.message);
        }
    }
    return report;
}
