#pragma once
#include<stdint.h>
#include<iostream>
#include<stack>
#include <queue>
using std::cout;

template<typename T>
struct BSTnode {
	T data;
	BSTnode<T>* left;
	BSTnode<T>* right;
};

template<typename T>
class BST
{	
private:
	BSTnode<T>* root;
	uint32_t size;
	int height(BSTnode<T>* p);
	BSTnode<T>* remove(BSTnode<T>* p, T val);
public:
	BST() : root(nullptr), size(0) {};
	void insert(T data);
	BSTnode<T>* generateNode(T data);
	void preOrderPrint();
	void postOrderPrint();
	void inOrderPrint();
	void levelOrderPrint();
	BSTnode<T>* search(T val);
	void remove(T val);
	int getHeight();
	BSTnode<T>* inPred(BSTnode<T>* p);
	BSTnode<T>* inSuc(BSTnode<T>* p);
};

template<typename T>
inline void BST<T>::insert(T data)
{
	BSTnode<T>* node = generateNode(data);
	if (root == nullptr) {
		root = node;
	}
	else {
		BSTnode<T>* ptr = root;
		while (true) {
			if (data <= ptr->data) {
				if (ptr->left == nullptr) {
					ptr->left = node;
					break;
				}
				else {
					ptr = ptr->left;
				}
			}
			else {
				if (ptr->right == nullptr) {
					ptr->right = node;
					break;
				}
				else {
					ptr = ptr->right;
				}

			}
		}
	}
}

template<typename T>
inline BSTnode<T>* BST<T>::generateNode(T data)
{
	return new BSTnode<T>({ data,nullptr,nullptr });
}

template<typename T>
inline void BST<T>::preOrderPrint()
{
	if (root == nullptr)
		return;

	std::stack<BSTnode<T>*> traversal;
	traversal.push(root);

	while (!traversal.empty()) {
		BSTnode<T>* top = traversal.top();
		traversal.pop();
		cout << top->data<< ":";
		if(top->right)
			traversal.push(top->right);
		if(top->left)
			traversal.push(top->left);
	}
}

template<typename T>
inline void BST<T>::postOrderPrint()
{
	if (root == nullptr)
		return;

	std::stack<BSTnode<T>*> traversal;
	traversal.push(root);
	BSTnode<T>* top = traversal.top();
	while (!traversal.empty()) {
		if (traversal.top()->right == top) {
			top = traversal.top();
			cout << top->data << ":";
			traversal.pop();
			continue;
		}

		top = traversal.top();
		if (!top->left && !top->right) {
			cout << top->data << ":";
			traversal.pop();
			continue;
		}
		if (top->right) traversal.push(top->right);
		if (top->left) traversal.push(top->left);
		
		
	}
	
		
	
}

template<typename T>
inline void BST<T>::inOrderPrint()
{
	if (root == nullptr)
		return;

	std::stack<BSTnode<T>*> traversal;
	BSTnode<T>* top = root;

	while (top != nullptr || !traversal.empty()) {
		while (top) {
		traversal.push(top);
		top = top->left;
		}

		top = traversal.top();
		traversal.pop();
		cout << top->data << ":";

		top = top->right;
	}

}

template<typename T>
inline void BST<T>::levelOrderPrint()
{
	std::queue<BSTnode<T>*> q;
	q.push(root);
	while (!q.empty()) {
		BSTnode<T>* front = q.front();
		q.pop();
		cout << front->data << ":";
		if (front->left) q.push(front->left);
		if (front->right) q.push(front->right);
	}
}

template<typename T>
inline BSTnode<T>* BST<T>::search(T val)
{
	BSTnode<T>* p = root;

	while (p != nullptr) {
		if (p->data == val) {
			return p;
		}
		else if (val < p->data ) {
			p = p->left;
		}
		else {
			p = p->right;
		}
	}

	return nullptr;
	
}

template<typename T>
inline void BST<T>::remove(T val)
{
	if (root == nullptr) {
		return;
	}
	else {
		root = remove(root,val);
	}

}

template<typename T>
inline BSTnode<T>* BST<T>::remove(BSTnode<T>* p, T val)
{
	if (!p) return nullptr;
	BSTnode<T>* q = nullptr;
	
	if (p->data == val) {
		if (p->left == nullptr && p->right == nullptr) {
			delete p;
			return nullptr;
		}
		else if (height(p->left) > height(p->right)) {
			q = inPred(p);
			p->data = q->data;
			p->left = remove(p->left,q->data);
			return p;
		}
		else {
			q = inSuc(p);
			p->data = q->data;
			p->right = remove(p->right,q->data);
			return p;
		}
	}
	else if(p->data > val ) {
		p->left = remove(p->left, val);
	}
	else {
		p->right = remove(p->right, val);
	}

	return p;
	
}

template<typename T>
inline int BST<T>::height(BSTnode<T>* p)
{
	if (p == nullptr) return 0;
	if (p->left == nullptr && p->right == nullptr) return 1;
	else {
		int hleft = height(p->left);
		int hright = height(p->right);

		return hleft > hright ? hleft + 1 : hright + 1;
	}

}

template<typename T>
inline int BST<T>::getHeight()
{
	return height(root);
}

template<typename T>
inline BSTnode<T>* BST<T>::inPred(BSTnode<T>* p)
{
	if (!p || p->left == nullptr) return nullptr;
	p = p->left;
	while (p->right != nullptr) {
		p = p->right;
	}
	return p;
}

template<typename T>
inline BSTnode<T>* BST<T>::inSuc(BSTnode<T>* p)
{
	if (!p || p->right == nullptr) return nullptr;
	p = p->right;
	while (p->left != nullptr) {
		p = p->left;
	}
	return p;
}



/*
		if (top->right)
		traversal.push(top->right);
	traversal.push(top);
	if (top->left) {
		traversal.push(top->left);
		top = top->left;
	}


if (traversal.top()->left == top || (traversal.top()->left && traversal.top()->left->right == top)) {
			top = traversal.top();
			cout << top->data << ":";
			traversal.pop();
			continue;
		}
		top = traversal.top();
		if (!top->left && !top->right) {
			cout << top->data << ":";
			traversal.pop();
			continue;
		}
		traversal.pop();
		if (top->right) {
			traversal.push(top->right);
		}
		traversal.push(top);
		if (top->left) {
			traversal.push(top->left);
		}*/