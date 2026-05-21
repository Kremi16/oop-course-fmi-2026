#pragma once
#include<vector>
#include<memory>
#include"AdmissionRequirement.h"
#include"AdmissionReport.h"
#include"Utils.h"

using namespace std;

class AdmissionService
{
private:
    vector<shared_ptr<AdmissionRequirement>> requirements;

public:
    void addRequirement(const shared_ptr<AdmissionRequirement>& requirement);
    AdmissionReport checkStudent(const Student& student) const;
};