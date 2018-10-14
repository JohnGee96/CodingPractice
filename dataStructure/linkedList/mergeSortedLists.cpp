// Given two sorted linked lists, merge them such that 
// resulting linked list is also sorted.

#include "./lib/linkedList.h"
#include "./lib/linkedListNode.h"
#include <vector>
#include <iostream>

typedef LinkedListNode<int>* NodePtr;

LinkedList<int> merge_sorted(NodePtr head1, NodePtr head2) {
    //TODO: Write - Your - Code
    LinkedList<int> newList;
    NodePtr temp1 = head1;
    NodePtr temp2 = head2;

    while (temp1 != nullptr && temp2 != nullptr) {
        if (temp1->value <= temp2->value) {
            newList.append(temp1->value);
            temp1 = temp1->next;
        }
        else {
            newList.append(temp2->value);
            temp2 = temp2->next;
        }
    } 

    // Append the rest of the lists
    while (temp1 != nullptr) {
        newList.append(temp1->value);
        temp1 = temp1->next;
    }
    while (temp2 != nullptr) {
        newList.append(temp2->value);
        temp2 = temp2->next;
    }

    return newList;
}

int main() {
    std::vector<int> v1 = {4, 6, 8, 10, 15};
    std::vector<int> v2 = {0, 4, 5, 6, 11};
    LinkedList<int> l1 = LinkedList<int>(v1);
    LinkedList<int> l2 = LinkedList<int>(v2);

    LinkedList<int> newList = merge_sorted(l1.head, l2.head);

    newList.print();
}