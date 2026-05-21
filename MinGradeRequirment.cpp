#include "MinGradeRequirment.h"
#include"MinimumGradeException.h"

MinGradeRequirment::MinGradeRequirment(double minGrade)
{
    if (minGrade < 2.00 || minGrade>6.00)
    {
        throw MinimumGradeException();
    }
    this->minGrade = minGrade;
}

RequirmentResult MinGradeRequirment::check(const Student& student) const
{
    if (student.getGrade() < minGrade)
    {
        return { false,"Student has failed." };
    }

    return { true,"Student has passed." };
}
