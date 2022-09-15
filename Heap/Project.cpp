#include "Project.h"

Project::Project(int projectID, string projectName, string teamLead, string rollNumber) : projectID(projectID), projectName(projectName), teamLead(teamLead), rollNumber(rollNumber)
{
}

bool Project::operator<(const Project& rhs)
{
	return projectID < rhs.projectID;
}

bool Project::operator>(const Project& rhs)
{
	return projectID > rhs.projectID;
}

void Project::display()
{
	cout << "-| Name: " << projectName << " ID: " << projectID << " Team Lead: " << teamLead << " Roll No.: " << rollNumber << " |- ";

}
