/*
	Muhammad Hameed Tariq
	BCSF20A027
*/

#pragma once
#include<stack>
#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class AVL;

template<typename T>
class AVLNode
{
	friend AVL<T>;
	T data;
	int height;
	AVLNode* left;
	AVLNode* right;
public:
	AVLNode(T val, AVLNode* left= nullptr, AVLNode*right = nullptr,int height=0): data(val), left(left), right(right), height(height) {};
};

template<typename T>
class AVL
{
	AVLNode<T>* root;
public:
	AVL();
	~AVL();
	AVL(const AVL<T>& rhs);
	void insert(T val);
	int calHeight(AVLNode<T>* node);
	int balanceFactor(AVLNode<T>* node);
	AVLNode<T>* LLRotation(AVLNode<T>* p);
	AVLNode<T>* RRRotation(AVLNode<T>* p);
	AVLNode<T>* LRRotation(AVLNode<T>* p);
	AVLNode<T>* RLRotation(AVLNode<T>* p);
	void deleteNode(AVLNode<T>* p);
	AVLNode<T>* search(T key);
	AVLNode<T>* inOrderPredecessor(AVLNode<T>* p);
	AVLNode<T>* inOrderSuccessor(AVLNode<T>* p);
	AVLNode<T>* getParent(AVLNode<T> *p);
	void printNodes();
	void printTree();
};
