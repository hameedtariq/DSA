#include <iostream>
#include <vector>
#include <algorithm>
#include "MemoryManager.h"
using namespace std;

int main() {
	int size, address; char choice; int option;
	//vector<MemoryBlock*> record;
	cout << "Please Enter the size of your memory pool: ";
	cin >> size;
	MemoryManager mem(size);
	cout << "Your current memory status: ";
	mem.printMemory();
	do {
		cout << "1- Do you want to allocate memory?\n";
		cout << "2- Do you want to free memory?\n";
		cout << "Please select the write option: ";
		cin >> option;
		if (option == 1)
		{
			cout << "Enter the size of memory you want to allocate: ";
			cin >> size;
			MemoryBlock* allocatedMem = mem.allocate(size);
			if (allocatedMem == nullptr) cout << "Could not allocate memory. Insufficient storage!\n";
			//else record.emplace_back(allocatedMem);
			cout << "Your current memory status: ";
			mem.printMemory();
		}
		else if (option == 2) {
			cout << "Enter the address of memory you want to deallocate: ";
			cin >> address;
			cout << "Enter the size of memory you want to deallocate: ";
			cin >> size;

			mem.free(new MemoryBlock(address, size));

			cout << "Your current memory status: ";
			mem.printMemory();
		}
		else
		{
			cout << "Invalid Option";
		}
		cout << "Do you want to try again?(Y/N) \n";
		cin >> choice;
	} while (choice == 'Y' || choice == 'y');
	cin >> choice;
	/*while () {
		
		cout << "Do you want to allocate more memory?\n";
		cin >> choice;
	}

	cout << "Do you want to free memory?\n";
	cin >> choice;


	while (choice == 'Y' || choice == 'y') {
		
		cout << "Do you want to allocate more memory?\n";
		cin >> choice;
	}*/

	/*MemoryBlock* p1 = mem.allocate(10);
	MemoryBlock* p3 = mem.allocate(20);
	mem.allocate(30);
	mem.allocate(30);
	MemoryBlock* p2 = mem.allocate(40);
	mem.free(p1);
	mem.free(p2);
	mem.free(p3);*/
	return 0;
}