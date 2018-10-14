// Swap Nth Node with Head
// Given the head of a singly linked list and 'N', 
// swap the head with Nth node. Return the head of the new linked list.

#include "./lib/linkedList.h"
#include "./lib/linkedListNode.h"
#include <vector>
#include <iostream>

LinkedListNode<int>*
swap_nth_node(LinkedList<int>& l, int n) {
    // Node indices starts from 1.
    if (n > 1) {
        LinkedListNode<int>* prev;
        LinkedListNode<int>* tail = l.head;
        while (n > 1) {
            prev = tail;
            tail = tail->next;
            --n;
        }
        // store tail's next temperally
        prev->next = tail->next;
        tail->next = l.head->next;
        l.head->next = prev->next;
        prev->next = l.head;
        l.head = tail;
    }
    else if (n < 1) {
        return nullptr;
    }
    return l.head;
}

int main() {
    std::vector<int> v = {1,2,3,4};
    LinkedList<int> l = LinkedList<int>(v);

    LinkedListNode<int>* r = swap_nth_node(l, 3);
    std::cout << "Expect 3: " << r->value << '\n';
}