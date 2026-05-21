#include "MaxRemainingSubjectsRequirment.h"
#include"ElectivesException.h"

MaxRemainingSubjectsRequirment::MaxRemainingSubjectsRequirment(unsigned maxRemaining,
    vector<unique_ptr<Subject>> allElectiveSubjects)
{
    if (maxRemaining == 0 || maxRemaining > MAX_VALUE || allElectiveSubjects.empty())
    {
        throw ElectivesException();
    }
    this->maxRemaining = maxRemaining;
    this->allElectiveSubjects = move(allElectiveSubjects);
}

RequirmentResult MaxRemainingSubjectsRequirment::check(const Student& student) const
{
    unsigned remaining = 0;

    auto passedStudentSubjects = student.getPassedSubjects();
    for (const auto& elective : allElectiveSubjects)
    {
        bool passed = false;
        for (const auto& subject : passedStudentSubjects)
        {
            if (elective->getName() == subject->getName())
            {
                passed = true;
                break;
            }
        }
        if (!passed)
        {
            remaining;
        }
    }

    if (remaining >= maxRemaining)
    {
        return { false,"Student has too many failed elective subjects." };
    }

    return { true, "Student does not have too many failed elective subjects." };
}
