#pragma once
#include <iostream>
using namespace std;
class MemoryManager;
class MemoryBlock
{
	friend MemoryManager;
	int address;
	int length;
	MemoryBlock* next;
	MemoryBlock* prev;
public:
	MemoryBlock(int address, int length, MemoryBlock* prev = nullptr, MemoryBlock* next = nullptr) : address(address), length(length), prev(prev), next(next) {};
	void printBlock() {
		cout << "| address: " << address << ", size: " << length << " |";
	}
};



class MemoryManager
{
	MemoryBlock* head;
public:
	MemoryManager(int memorySize);
	MemoryBlock* allocate(int size);
	void free(MemoryBlock* block);
	void freeFragmentation();
	void deleteNode(MemoryBlock* block);
	void printMemory();
};

