/*
	Muhammad Hameed Tariq
	BCSF20A027
*/
#include <iostream>
#include "XorList.h"
#include "XorList.cpp"
using namespace std;

int main()
{
	XorList<int> a;
	a.insertAtHead(19);
	a.insertAtHead(29);
	a.insertAtHead(39);
	a.insertAtHead(49);
	a.insertAtHead(59);
	a.insertAtHead(69);
	a.insertAtTail(79);
	a.insertAtTail(89);
	a.insertAtTail(99);
	a.insertAfter(79, 100);

	a.printList();


	a.removeAtTail();
	a.removeAtTail();
	a.removeAtTail();
	a.removeAtTail();
	a.removeAtTail();
	a.removeAtTail();
	a.removeAtTail();
	a.removeAtTail();

	a.printList();

	return 0;
}