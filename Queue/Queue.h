//
// Created by Tariq on 4/9/2022.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

template<typename T>
class Queue {
private:
    int rear;
    int front;
    int capacity;
    int noOfElements;
    T * data;
    void reSize(int newSize);
public:
    Queue();
    ~Queue();
    void enQueue(T val);
    T deQueue();
    T getElementAtFront();
    bool isEmpty();
    bool isFull();
    int getNoOfElements();
    int getCapacity();
};

#endif //QUEUE_QUEUE_H
