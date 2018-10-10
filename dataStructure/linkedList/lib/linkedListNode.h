#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

template <typename T>
class LinkedListNode {
public:
    LinkedListNode(T);

    T value;
    LinkedListNode<T>* next;
};

template <typename T>
LinkedListNode<T>::LinkedListNode(T data) {
    value = data;
}

#endif