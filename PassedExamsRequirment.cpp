#include "PassedExamsRequirment.h"

RequirmentResult PassedExamsRequirment::check(const Student& student) const
{
    for (const auto& subject : subjectNames)
    {
        if (!student.hasPassedSubject(subject))
        {
            return { false,"Student does not have passed all required subjects." };
        }
    }

    return { true,"Student has passed all required subjects." };
}
