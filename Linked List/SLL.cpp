#include "SLL.h"

SLLNode* SLL::genNode(int val)
{
    return new SLLNode(val,nullptr);
}

void SLL::insertAtHead(int val)
{
    if (head == nullptr) {
        head = genNode(val);
    }
    else {
        SLLNode* tempHead = head;
        head = genNode(val);
        head->next = tempHead;
        tempHead = nullptr;
    }
}

void SLL::printList()
{
    if (head == nullptr) return;

    SLLNode* p = head;
    while (p != nullptr)
    {
        std::cout << p->data << ":";
        p = p->next;
    }
}

void SLL::insert(int index, int val)
{
    if (index == 0) {
        insertAtHead(val);
        return;
    }
    SLLNode* p = head;
    int ind = 1;
    while (p != nullptr) {
        if (index == ind) {
            SLLNode* tempNode = p->next;
            p->next = genNode(val);
            p->next->next = tempNode;
            break;
        }
        else {
            ind++;
            p = p->next;
        }
    }
}

int SLL::search(int val)
{
    if (head == nullptr) {
        return -1;
    }
    SLLNode* p = head;
    int index = 0;
    while (p != nullptr) {
        if (p->data == val) {
            return index;
        }
        index++;
        p = p->next;
    }

    return -1;
}

bool SLL::remove(int val)
{
    if (head == nullptr) {
        return false;
    }
    if (head && head->data == val) {
        SLLNode* tempHead = head->next;
        delete head;
        head = tempHead;
        return true;
    }
    SLLNode* p = head, * q = head->next;
    while (q != nullptr) {
        if (q->data == val) {
            p->next = q->next;
            delete q;
            return true;
        }
        else {
            p = q;
            q = q->next;
        }
    }

    return false;

}

void SLL::reverse()
{
    if (head == nullptr) return;

    SLLNode *p = nullptr, *q = head, *r;
    while (q != nullptr) {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
        if (r == nullptr) {
            head = p;
        }
    }


}

SLL::~SLL()
{
    if (head == nullptr) return;
    SLLNode* p;
    while (head != nullptr) {
        p = head;
        head = head->next;
        delete p;
    }
}
