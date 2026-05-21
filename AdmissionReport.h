#pragma once
#include<vector>
#include<string>
using namespace std;

class AdmissionReport
{
private:
    bool admitted = true;

    vector<string> messages;

public:
    void addFailure(const string& message);
    bool isAdmitted() const;
    const vector<string>& getMessages() const;
};