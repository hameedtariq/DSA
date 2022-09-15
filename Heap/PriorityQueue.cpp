#include "PriorityQueue.h"


 PriorityQueue::PriorityQueue(int height)
{
	size = pow(2, height) - 1;
	if (size > 0) arr = new Project[size];
	else arr = nullptr;
	count = 0;
}


 PriorityQueue::~PriorityQueue()
{
	if (arr) delete[] arr;
	arr = nullptr;
	size = count = 0;
}

 PriorityQueue::PriorityQueue(const PriorityQueue& rhs)
 {
	 count = rhs.count;
	 size = rhs.size;
	 arr = new Project[size];
	 for (int i = 0; i < count; i++) {
		 arr[i] = rhs.arr[i];
	 }
 }


 void PriorityQueue::insert(Project val)
{
	if (count == size) resize();

	arr[count++] = val;
	int i = count - 1;
	Project temp = arr[i];
	while (i > 0 && temp > arr[(i - 1) / 2]) {
		arr[i] = arr[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	arr[i] = temp;
}


 void PriorityQueue::resize()
{
	if (arr == nullptr && size == 0)
	{
		arr = new Project[1];
		size = 1;
	}
	else
	{
		size = (size + 1) * 2 - 1; // 2^(n+1) - 1
		Project* temp = new Project[size];
		for (int i = 0; i < count; i++) {
			temp[i] = arr[i];
		}

		delete[] arr;
		arr = temp;
		temp = nullptr;
	}



}


 Project PriorityQueue::getNextProject()
{
	Project temp;
	if (count > 0) {
		temp = arr[0];
		arr[0] = arr[count - 1];
		count--;
		int i = 0, child = 2 * i + 1;
		while (child < count) {
			if (child + 1 < count && arr[child + 1] > arr[child]) child++;
			if (arr[i] < arr[child]) {
				swap(arr[i], arr[child]);
			}
			else
			{
				break;
			}
		}

	}
	return temp;
}


 void PriorityQueue::swap(Project& a, Project& b)
{
	Project temp = a;
	a = b;
	b = temp;
}


 int PriorityQueue::searchIndex(string name)
{
	for (int i = 0; i < count; i++) {
		if (arr[i].projectName == name) {
			return i;
		}
	}


	return -1;
}


 Project PriorityQueue::getSpecificProject(string name)
{
	int i = searchIndex(name);
	if (i > -1) {
		increaseProjectPriority(i);
		return getNextProject();
	}
	return Project();
}


 void PriorityQueue::increaseProjectPriority(int i)
{
	arr[i].projectID = arr[0].projectID + 1;
	Project temp = arr[i];
	while (i > 0 && temp > arr[(i - 1) / 2]) {
		arr[i] = arr[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	arr[i] = temp;
}

 int PriorityQueue::getLeftChild(int i)
 {
	 if (i > 0) {
		 if (2 * i + 1 < count) return 2 * i + 1;
		 else return -1;
	 }
	 else return -1;
 }

 int PriorityQueue::getRightChild(int i)
 {
	 if (i > 0) {
		 if (2 * i + 2 < count) return 2 * i + 2;
		 else return -1;
	 }
	 else return -1;
 }

 int PriorityQueue::getParent(int i)
 {
	 if (i > 0)
	 {
		 return (i - 1) / 2;
	 }
	 else return -1;
 }

 int PriorityQueue::getNodeCount()
 {
	 return count;
 }

 void PriorityQueue::displayAllProjects()
 {
	 int breaker = 1, j = 0;
	 for (int i = 0; i < count; i++,j++) {
		 if (j == breaker) {
			 cout << endl;
			 breaker *= 2;
			 j = 0;
		 }
		 for (int i = 0; i < count*2 / (breaker); i++) {
			 cout << " ";
		 }
		 cout << "(" << arr[i].projectID << "," << arr[i].projectName << ") ";
		 /*cout << "-| Name: " << arr[i].projectName << " ID: " << arr[i].projectID << " Team Lead: " << arr[i].teamLead << " Roll No.: " << arr[i].rollNumber << " |- ";*/
	 }
	 cout << endl;
 }
