// Given a singly linked list, return nth from last node. Return null if 'n' is out-of-bounds.

#include "./lib/linkedList.h"
#include "./lib/linkedListNode.h"
#include <vector>
#include <iostream>

LinkedListNode<int>* find_nth_from_last(
    LinkedList<int>& l,
    int n) {
    
    // if (l.head == nullptr || n < 1)
    //     return nullptr;

    LinkedListNode<int>* temp1 = l.head;
    LinkedListNode<int>* temp2 = l.head;

    while (temp1 != nullptr) {
        temp1 = temp1->next;
        --n;
        if (n < 0) {
            temp2 = temp2->next;
        }
    }
    if (n > 0) {
        return nullptr;
    }
    else {
        return temp2;
    }
}

int main() {
    std::vector<int> v1 = {1,2,3};
    std::vector<int> v2 = {};
    LinkedList<int> l1 = LinkedList<int>(v1);
    LinkedList<int> l2 = LinkedList<int>(v2);

    LinkedListNode<int>* r1 = find_nth_from_last(l1, 3);
    LinkedListNode<int>* r2 = find_nth_from_last(l1, 1);
    LinkedListNode<int>* r3 = find_nth_from_last(l1, 0);
    LinkedListNode<int>* r4 = find_nth_from_last(l1, 4);
    LinkedListNode<int>* r5 = find_nth_from_last(l2, 0);

    std::cout << "Expect 1: " << r1->value << '\n';
    std::cout << "Expect 3: " << r2->value << '\n';
    std::cout << "Expect nullptr: " << r3 << '\n';
    std::cout << "Expect nullptr: : " << r4 << '\n';
    std::cout << "Expect nullptr: " << r5 << '\n';
}
