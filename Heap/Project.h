#pragma once
#include <string>
#include <iostream>

using namespace std;


class PriorityQueue;

class Project {
	friend PriorityQueue;
	int projectID;
	string projectName;
	string teamLead;
	string rollNumber;
public:
	Project(int projectID = -1, string projectName = "", string teamLead="", string rollNumber = "");
	bool operator<(const Project& rhs);
	bool operator>(const Project& rhs);
	void display();
};