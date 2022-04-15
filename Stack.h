//
// Created by Tariq on 4/7/2022.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

template<typename T>
class Stack {
private:
    T * data;
    int capacity;
    int top;
    void reSize(int);
public:
    Stack();
    Stack(const Stack<T> &);
    Stack &operator=(const Stack<T> &);
    ~Stack();
    void push(T);
    T pop();
    T stackTop();
    bool isFull();
    bool isEmpty();
    int getCapacity();
    int getNumberOfElements();
};


#endif //STACK_STACK_H
