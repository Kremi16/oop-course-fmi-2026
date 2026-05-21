#include "MinimumPassedSubjectsRequirment.h"
#include"CategoryRequirmentException.h"

MinimumPassedSubjectsRequirment::MinimumPassedSubjectsRequirment(Category category, unsigned min):
	AdmissionRequirement(), category(category)
{
	if (min == 0)
	{
		throw CategoryRequirmentException();
	}
	minPassedSubjects = min;
}

RequirmentResult MinimumPassedSubjectsRequirment::check(const Student& student) const
{
	unsigned count = student.countPassedSubjectsByCategory(category);
	if (count >= minPassedSubjects)
	{
		return { true,"Student has reached the minimum passed subjects of this category." };
	}

	return { false,"Student has not reached the minimum for this category." };
}
