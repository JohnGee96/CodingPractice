#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <vector>
#include <iostream>
#include "linkedListNode.h"

template <typename T>
class LinkedList {
public:
    LinkedList();
    LinkedList(std::vector<T>);
    ~LinkedList();

    LinkedListNode<T>* head;
    LinkedListNode<T>* tail;
    
    void remove(int index);
    void insert(int value, int index);
    bool isEmpty();
    void print();

    int size;
};

template <typename T>
LinkedList<T>::LinkedList() {
    head = tail = nullptr;
    size = 0;
}

template <typename T>
LinkedList<T>::LinkedList(std::vector<T> v) {
    if (v.size() > 0) {
        typename std::vector<T>::iterator it = v.begin();
        // Initialize head pointer
        LinkedListNode<T>* curr = new LinkedListNode<T>(*it);
        LinkedListNode<T>* prev = curr;
        head = curr;
        it++;
        for (; it != v.end(); ++it) {
            curr = new LinkedListNode<T>(*it);
            prev->next = curr;
            prev = curr;
        }
        tail = curr;
        tail->next = nullptr;
        size = v.size();
    }
    else {
        head = tail = nullptr;
        size = 0;
    }
}

template <typename T>
LinkedList<T>::~LinkedList() {
    // std::cout << "Destructor, head: " << head << '\n';
    if (size != 0) {
        LinkedListNode<T>* nextPtr;
        LinkedListNode<T>* cur = head;
        while (cur != nullptr) {
            nextPtr = cur->next;
            delete cur;
            cur = nextPtr;
        }
        head = tail = nullptr;
        size = 0;
    } 
}

template <typename T>
void LinkedList<T>::remove(int index) {
    LinkedListNode<T>* prev = nullptr;
    LinkedListNode<T>* cur = head;
    if (index < 0) {
        std::cout << "ERROR: Invalid negative index\n";
        return;
    }
    else if (index >= size) {
        std::cout << "ERROR: Out-of-bound index\n";
        return;
    }
    for (int i=0; i<index; ++i) {
        prev = cur;
        cur = cur->next;
    }
    if (index == 0) {
        cur = head;
        head = head->next;
    }
    else prev->next = cur->next;
    if (index == size - 1) tail = prev;
    --size;
    delete cur;
    return;
}

template <typename T>
void LinkedList<T>::insert(int value, int index) {
    LinkedListNode<T>* prev = nullptr;
    LinkedListNode<T>* cur = head;
    if (index < 0) {
        std::cout << "ERROR: Invalid negative index\n";
        return;
    }
    else if (index > size) {
        std::cout << "ERROR: Out-of-bound index\n";
        return;
    }
    // Traverse through the list
    for (int i=0; i<index; ++i) {
        prev = cur;
        cur = cur->next;
    }
    LinkedListNode<int>* new_node = new LinkedListNode<int>(value); 
    if (index == 0) 
        head = new_node;
    else 
        prev->next = new_node;
    if (index == size) {
        tail = new_node;
        new_node->next = nullptr;
    }
    else
        new_node->next = cur;
    ++size;
    return;
}

template <typename T>
bool LinkedList<T>::isEmpty() {
    if (head == nullptr && tail == nullptr)
        return true;
    return false;
}

template <typename T>
void LinkedList<T>::print() {
    LinkedListNode<T>* curr = head;
    while (curr != nullptr) {
        std::cout << curr->value << ' ';
        curr = curr->next;
    }
    std::cout << '\n';
}

#endif