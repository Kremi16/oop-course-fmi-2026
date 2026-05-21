#include "AdmissionReport.h"

void AdmissionReport::addFailure(const string& message)
{
	admitted = false;
	messages.push_back(message);
}

bool AdmissionReport::isAdmitted() const
{
	return admitted;
}

const vector<string>& AdmissionReport::getMessages() const
{
	return messages;
}
