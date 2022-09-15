#pragma once
#include<math.h>
#include "Project.h"
#include <iostream>
using namespace std;

class PriorityQueue
{
	Project* arr;
	int count;
	int size;
public:
	PriorityQueue(int height = 0);
	~PriorityQueue();
	PriorityQueue(const PriorityQueue& rhs);
	void insert(Project val);
	void resize();
	Project getNextProject();
	void swap(Project& a, Project& b);
	int searchIndex(string name);
	Project getSpecificProject(string name);
	//void decreaseProjectPriority(int i);
	void increaseProjectPriority(int i);

	//utilities
	int getLeftChild(int i);
	int getRightChild(int i);
	int getParent(int i);
	int getNodeCount();

	void displayAllProjects();
};

