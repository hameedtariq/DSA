//
// Created by Tariq on 4/7/2022.
//
#include "Stack.h"

template<typename T>
Stack<T>::Stack() : capacity(0), top(0), data(nullptr)
{
    capacity = 5;
    data = new T[capacity];

}

template<typename T>
Stack<T>::~Stack() {
    delete[] data;
    data =  nullptr;
    capacity=0;
    top=0;

}

template<typename T>
Stack<T>::Stack(const Stack<T> &rhs) :top(0)
{
    capacity = rhs.capacity;
    data = new T[capacity];
    for(auto &a: rhs.data)
    {
        data[top++] = data[top];
    }

}

template<typename T>
Stack<T> &Stack<T>::operator=(const Stack<T> &rhs) {
    delete[] data;
    data =  nullptr;
    capacity=0;
    top=0;

    capacity = rhs.capacity;
    data = new T[capacity];
    for(auto &a: rhs.data)
    {
        data[top++] = data[top];
    }
    return *this;
}

template<typename T>
void Stack<T>::push(T val) {
    if(top == capacity)
    {
        reSize(capacity*2);
        data[top++] = val;
    }
    else
    {
        data[top++] = val;
    }

}

template<typename T>
T Stack<T>::pop() {
    if(top == 0)
    {
        return static_cast<T>(0);
    }
    else
    {
        top--;
        if(top <= capacity/4)
        {
            reSize(capacity/2);
        }
        return data[top];
    }

}

template<typename T>
T Stack<T>::stackTop() {
    if(top == 0)
    {
        return static_cast<T>(0);
    }
    else
    {
        return data[top-1];
    }
}

template<typename T>
bool Stack<T>::isFull() {
    return top == capacity;
}

template<typename T>
bool Stack<T>::isEmpty() {
    return top == 0;
}

template<typename T>
int Stack<T>::getCapacity() {
    return capacity;
}

template<typename T>
int Stack<T>::getNumberOfElements() {
    return top;
}

template<typename T>
void Stack<T>::reSize(int s) {
    capacity= s;
    T * temp = new T[capacity];
    for(int i =0; i < top; i++)
    {
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
    temp = nullptr;

}


