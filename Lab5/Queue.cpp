#include "Queue.h"
template<typename T>
void Queue<T>::enQueue(T val)
{
    if(!pStack.empty())
    {
        while(!pStack.empty())
        {
            sStack.push(pStack.top()); pStack.pop();
        }
        pStack.push(val);
        while(!sStack.empty())
        {
            pStack.push(sStack.top()); sStack.pop();
        }
    }
    else
    {
        pStack.push(val);
    }
}

template<typename T>
T Queue<T>::deQueue() {
    T val =  pStack.top();
    pStack.pop();
    return val;
}

template<typename T>
int Queue<T>::size() {
    return pStack.size();
}