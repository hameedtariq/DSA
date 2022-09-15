/*
	Muhammad Hameed Tariq
	BCSF20A027
*/
#pragma once
#include <iostream>
#include <stdint.h>
using std::cout;
using std::endl;
template<typename T>
struct Node
{
	T data;
	Node* px;
	Node(T val, Node* ptr = nullptr) : data(val), px(ptr) {};
};


template<typename T>
class XorList
{
	Node<T>* head;
public:
	XorList();
	~XorList(); //
	void insertAtHead(T val);
	void insertAtTail(T val);
	void insertAfter(T key, T val);
	void deleteBefore(T val);
	void removeAtHead();
	void removeAtTail();
	void printList();
	Node<T>* calAddress(Node<T>* prev, Node<T>* next);
		
};
