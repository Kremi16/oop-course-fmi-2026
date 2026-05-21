#include "StudentSystem.h"
#include "StudentAlreadyExistsException.h"
#include "StudentNotFoundException.h"

StudentSystem::StudentSystem(
    const std::shared_ptr<AdmissionService>& service
)
    : admissionService(service)
{
}

void StudentSystem::addStudent(const Student& student)
{
    for (const auto& s : students)
    {
        if (s.getFacultyNumber() == student.getFacultyNumber())
        {
            throw StudentAlreadyExistsException();
        }
    }

    students.push_back(student);
}

void StudentSystem::removeStudent(const string& facultyNumber)
{
    for (auto it = students.begin(); it != students.end(); ++it)
    {
        if (it->getFacultyNumber() == facultyNumber)
        {
            students.erase(it);
            return;
        }
    }

    throw StudentNotFoundException();
}

Student& StudentSystem::operator[](const string& facultyNumber)
{
    for (auto& s : students)
    {
        if (s.getFacultyNumber() == facultyNumber)
        {
            return s;
        }
    }

    throw StudentNotFoundException();
}

AdmissionReport StudentSystem::checkAdmission(const string& facultyNumber) const
{
    for (const auto& s : students)
    {
        if (s.getFacultyNumber() == facultyNumber)
        {
            return admissionService->checkStudent(s);
        }
    }

    throw StudentNotFoundException();
}