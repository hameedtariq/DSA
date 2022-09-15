#include "MemoryManager.h"

MemoryManager::MemoryManager(int memorySize) {
    head = new MemoryBlock(0, memorySize);
};

MemoryBlock* MemoryManager::allocate(int size)
{
    MemoryBlock* p = head;

    while (p != nullptr) {
        if (p->length > size) {
            MemoryBlock* temp = new MemoryBlock(p->address,size);
            p->address += size;
            p->length -= size;
            return temp;
        }
        else if (p->length == size)
        {
            if (p == head)
            {
                head = p->next;
                head->prev = nullptr;
            }
            else {
                p->prev->next = p->next;
                p->next->prev = p->prev;
            }
            p->next = nullptr;
            p->prev = nullptr;
            return p;
        }
        p = p->next;
    }
    return p;
}

void MemoryManager::free(MemoryBlock* block)
{
    MemoryBlock* p = head;
    while (p != nullptr) {
        if (p->address > block->address) { //merge
            if (block->address + block->length == p->address) {
                p->address -= block->length;
                p->length += block->length;
            }
            else {  // add block to list
                if (p == head) {
                    head = block;
                }
                block->prev = p->prev;
                if (block->prev) block->prev->next = block;
                block->next = p;
                p->prev = block;
            }
            break;
        }
       
        p = p->next;
        
    }
    freeFragmentation();
}

void MemoryManager::freeFragmentation()
{
    MemoryBlock* p = head;
    while (p->next != nullptr) {
        if (p->address + p->length == p->next->address) {
            p->length += p->next->length;
            deleteNode(p->next);
        }
        p = p->next;
    }
}

void MemoryManager::deleteNode(MemoryBlock* block)
{
    if (!block) return;
    if (block == head) {
        head = block->next;
        head->prev = nullptr;
    }
    else
    {
        if (!block->next) {
            block->prev->next = block->next;
        }
        else
        {
            block->prev->next = block->next;
            block->next->prev = block->prev;
        }
        
    }
    delete block;
}

void MemoryManager::printMemory()
{
    MemoryBlock* p = head;
    while (p != nullptr) {
        cout << "| address: " << p->address << ", size: " << p->length << " |";
        if (p->next != nullptr) cout << "->";
        p = p->next;
    }
    cout << endl;
}


    //if (!head) { // head is null
    //    head = new MemoryBlock(0, size);
    //}
    //else
    //{
    //    MemoryBlock* p = head;
    //    while (p != nullptr) {
    //        if (!p->next)
    //        {
    //            p->next = new MemoryBlock(p->address + p->length, size);
    //            p->next->prev = p;
    //            break;
    //        }
    //        else {
    //            if (((p->address + p->length) - (p->next->address)) >= size) {
    //                p->next = new MemoryBlock(p->address + p->length, size);
    //                p->next->prev = p;
    //                break;
    //            }
    //            
    //        }
    //    }
    //}

