#include "PassedAllMandatorySubjectsRequirment.h"

PassedAllMandatorySubjectsRequirment::PassedAllMandatorySubjectsRequirment
(const vector<unique_ptr<Subject>>& mandatorySubjects) :AdmissionRequirement(),
   allMandatorySubjects(move(mandatorySubjects)){}

RequirmentResult PassedAllMandatorySubjectsRequirment::check(const Student& student) const
{
    auto studentPassedSubjects = student.getPassedSubjects();

    for (const auto& mandatory : allMandatorySubjects)
    {
        bool found = false;
        for (const auto& subject : studentPassedSubjects)
        {
            if (subject->getName() == mandatory->getName())
            {
                found = true;
            }
        }
        if (!found)
        {
            return { false,"Student has not passed all mandatory subjects." };
        }
    }
    return { true,"Student has passed all mandatory subjects." };
}
