#pragma once
#include <iostream>


struct SLLNode {
	int data;
	SLLNode* next;
	SLLNode() = default;
	SLLNode(int data, SLLNode* next) : data(data), next(next) {};
};

class SLL
{
	SLLNode* head;
public:
	SLL() : head(nullptr) {};
	SLLNode* genNode(int val);
	void insertAtHead(int val); //inserts at head
	void printList();
	void insert(int index, int val);
	int search(int val); // Search a value
	bool remove(int val);	// removes a value
	void reverse();
	~SLL();
};

