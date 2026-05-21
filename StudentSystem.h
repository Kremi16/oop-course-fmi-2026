#pragma once
#include<vector>
#include<memory>
#include "Student.h"
#include "AdmissionService.h"
using namespace std;

class StudentSystem
{
private:
    vector<Student> students;

    shared_ptr<AdmissionService> admissionService;

public:
    StudentSystem(const shared_ptr<AdmissionService>& service);

    void addStudent(const Student& student);

    void removeStudent(const string& facultyNumber);

    Student& operator[](const string& facultyNumber);

    AdmissionReport checkAdmission(const string& facultyNumber) const;
};