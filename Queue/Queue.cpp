//
// Created by Tariq on 4/9/2022.
//

#include "Queue.h"

template<typename T>
Queue<T>::Queue() : rear(0), front(0), capacity(0), noOfElements(0), data(nullptr)
{}

template<typename T>
Queue<T>::~Queue()
{
    if(data != nullptr)
    {
        delete[] data;
        data = nullptr;
        rear = front = capacity = noOfElements = 0;
    }
}

template<typename T>
void Queue<T>::enQueue(T val)
{
    // add resize logic
    if(capacity == noOfElements)
    {
        reSize(capacity*2 + 1);
    }
    rear++;
    if(rear == capacity)
    {
        rear = 0;
    }

    data[rear] = val;
    noOfElements++;
}

template<typename T>
T Queue<T>::deQueue() {
    // shrink
    T val;
    if(noOfElements != 0)
    {
        val = data[front];
        front++;
        if(front == capacity)
        {
            front = 0;
        }
        noOfElements--;
    }
    else
    {
        val = static_cast<T>(0);
    }

    if(noOfElements <= capacity/4)
    {
        reSize(capacity/2);
    }

    return val;
}

template<typename T>
void Queue<T>::reSize(int newSize)
{
    capacity = newSize;
    T * temp;
    if(capacity == 0)
    {
        temp = nullptr;
    }
    else
    {
        temp = new T[capacity];
        for(int i =0; i < noOfElements;i++)
        {
            temp[i] = data[(front + i)%capacity];
        }
    }


    front = 0;
    rear = (noOfElements == 0 )? 0 : noOfElements-1;
    delete[] data;
    data = temp;
    temp = nullptr;
}

template<typename T>
T Queue<T>::getElementAtFront() {
    return data[rear];
}

template<typename T>
bool Queue<T>::isEmpty() {
    return noOfElements == 0;
}

template<typename T>
bool Queue<T>::isFull() {
    return noOfElements == capacity;
}

template<typename T>
int Queue<T>::getNoOfElements() {
    return noOfElements;
}

template<typename T>
int Queue<T>::getCapacity() {
    return capacity;
}

