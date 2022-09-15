/*
	Muhammad Hameed Tariq
	BCSF20A027
*/
#include "XorList.h"

template<typename T>
 XorList<T>::XorList() : head(nullptr)
{
}

template<typename T>
 XorList<T>::~XorList()
{
	if (!head) return;
	Node<T>* temp, * prev = nullptr;
	while (true) {
		temp = head;
		head = calAddress(prev, head->px);
		prev = temp;
		delete temp;
		if (head->px == prev)
		{
			delete head;
			head = nullptr;
			break;
		}
	}
}

template<typename T>
 void XorList<T>::insertAtHead(T val)
{
	if (!head) head = new Node<T>(val, calAddress(nullptr, nullptr));
	else
	{
		head = new Node<T>(val, calAddress(nullptr, head));
		head->px->px = calAddress(head, head->px->px);
	}
}

template<typename T>
 void XorList<T>::insertAtTail(T val)
{
	if (!head)
	{
		insertAtHead(val);
	}
	else
	{
		Node<T>* curr = head, * prev = nullptr, * temp;
		while (true)
		{
			if (curr->px == prev)
			{
				temp = new Node<T>(val, curr);
				curr->px = calAddress(prev, temp);
				break;
			}
			temp = calAddress(prev, curr->px);
			prev = curr;
			curr = temp;
		}

	}
}

template<typename T>
 void XorList<T>::insertAfter(T key, T val)
{
	if (!head) return;
	Node<T>* prev = nullptr, * curr = head, * temp, * next;
	while (true) {
		if (curr->data == key) {
			// we need to update current nodes px, set px for new node and
			// also update px for the node after current node because previous of that node is new node;
			next = calAddress(prev, curr->px);
			temp = new Node<T>(val, calAddress(curr, next));
			next->px = calAddress(temp, calAddress(curr, next->px));
			curr->px = calAddress(prev, temp);
			break;
		}

		temp = calAddress(prev, curr->px);
		prev = curr;
		curr = temp;
		if (curr->px == prev) {
			if (curr->data == key) insertAtTail(val);
			break;
		}
	};

}

template<typename T>
 void XorList<T>::deleteBefore(T val)
{
	if (!head || !head->px) return;
	Node<T>* prev = nullptr, * curr = head, * temp;
	while (true) {
		if (curr->data == val) {
			if (prev == head) removeAtHead();

		}

		temp = calAddress(prev, curr->px);
		prev = curr;
		curr = temp;
		if (curr->px == prev) {
			cout << curr->data << ":";
			break;
		}
	};

}

template<typename T>
 void XorList<T>::removeAtHead()
{
	if (head)
	{
		Node<T>* p = head;
		head = head->px;
		head->px = calAddress(p, head->px);
		delete p;
	}
}

template<typename T>
 void XorList<T>::removeAtTail()
{
	if (!head) return;
	else if (!head->px) {
		delete head;
		head = nullptr;
		return;
	}
	Node<T>* prev = nullptr, * curr = head, * temp;
	while (true) {


		temp = calAddress(prev, curr->px);
		prev = curr;
		curr = temp;
		if (curr->px == prev) {
			prev->px = calAddress(prev->px, curr);
			break;
		}
	};
}

template<typename T>
 void XorList<T>::printList()
{
	if (!head) return;
	Node<T>* prev = nullptr, * curr = head, * temp;
	while (true) {
		cout << curr->data << ":";

		temp = calAddress(prev, curr->px);
		prev = curr;
		curr = temp;
		if (curr->px == prev) {
			cout << curr->data << endl;
			break;
		}
	};
}

template<typename T>
 Node<T>* XorList<T>::calAddress(Node<T>* prev, Node<T>* next)
{
	uintptr_t ptr = (reinterpret_cast<uintptr_t>(prev) ^ reinterpret_cast<uintptr_t>(next));
	return ((Node<T>*)ptr);
}
