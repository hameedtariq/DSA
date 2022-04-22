
#ifndef LABTASK1_QUEUE_H
#define LABTASK1_QUEUE_H
#include <stack>
using namespace std;
template <typename T>
class Queue {
private:
    stack<T> pStack;
    stack<T> sStack;
public:
    void enQueue(T);
    T deQueue();
    int size();

};

#endif //LABTASK1_QUEUE_H
