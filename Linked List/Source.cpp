#include <iostream>
#include "SLL.h"
using namespace std;

int main() {
	SLL list;
	//list.printList();
	//list.insertAtHead(10);
	//list.insertAtHead(2);
	//list.insertAtHead(4);
	//list.insertAtHead(89);
	//list.insert(2, 44);
	//list.remove(4);
	//list.printList();
	//cout << endl;
	//cout << list.search(89);
	list.insert(0, 1);
	list.insert(1, 2);
	//list.insert(2, 3);
	//list.insert(3, 4);
	list.printList();
	cout << endl;
	list.reverse();
	list.printList();

	return 0;
}