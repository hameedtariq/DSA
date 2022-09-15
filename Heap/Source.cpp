#include <iostream>
#include "PriorityQueue.h"
#include <string>
using namespace std;

int main()
{
	PriorityQueue q;
	char choice; int ch;
	int id; string name, roll, lead;
	do {
		cout << "1. Insert a Project\n";
		cout << "2. Search a Project's Index\n";
		cout << "3. Get Next Project\n";
		cout << "4. Get Specific Project\n";
		cout << "5. Display All Projects\n";

		cout << "Select a valid option: ";
		cin >> ch;

		switch (ch) {
		case 1:
			do {
				cout << "Project id: ";
				cin >> id;
				if (id < 0 && id > 999) {
					cout << "Invalid ID selected. Please choose again";
				}
			} while (id < 0 && id > 999);
			cout << "Project Name: ";
			cin >> name;
			cout << "Team Lead Name: ";
			cin >> lead;
			cout << "Lead Roll Number: ";
			cin >> roll;
			q.insert(Project(id, name, lead, roll));
			break;

		case 2:
			cout << "Project Name: ";
			cin >> name;
			id = q.searchIndex(name);
			cout << "Index: ";
			(id > -1 ? cout << id : cout << "NULL");
			cout << endl;
			break;
		case 3:
			q.getNextProject().display();
			cout << endl;
			break;
		case 4:
			cout << "Project Name: ";
			cin >> name;
			id = q.searchIndex(name);
			if (id < 0) cout << "Project with given ID doesn't exists! \n";
			else q.getSpecificProject(name).display();
			cout << endl;

			break;
		case 5:
			q.displayAllProjects();
			break;
		default:
			cout << "Invalid choice of option\n";
		}

		cout << "Do you want to quit?(Y/N): ";
		cin >> choice;
		system("cls");
	} while (choice != 'Y' || choice != 'y');


	cout << "Program Terminated. You may close the window now\n";



	return 0;
}