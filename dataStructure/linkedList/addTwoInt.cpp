// Add Two Integers
// Given head pointers of two linked lists where 
// each linked list represents an integer number 
// (each node is a digit), add them and return 
// the resulting linked list.

#include <vector>
#include <iostream>
#include "lib/linkedList.h"
#include "lib/linkedListNode.h"

typedef LinkedListNode<int>* NodePtr;
typedef LinkedList<int> List;

NodePtr add_integers_rec(NodePtr n1, NodePtr n2, bool carry) {
    int sum = 0;
    NodePtr n1_next = nullptr;
    NodePtr n2_next = nullptr;
    if (n1 == nullptr && n2 == nullptr) {
        if (!carry)
            return nullptr;
    }
    else if (n1 != nullptr && n2 != nullptr) {
        sum = n1->value + n2->value;
        n1_next = n1->next;
        n2_next = n2->next;
    }
    else if (n1 == nullptr) {
        sum = n2->value;
        n2_next = n2->next;
    }
    else {
        sum = n1->value;
        n1_next = n1->next;
    }

    if (carry)
        ++sum;
    
    NodePtr new_node = new LinkedListNode<int>(sum % 10);
    new_node->next = add_integers_rec(n1_next, n2_next, sum > 9);
    return new_node;
}

NodePtr add_integers(NodePtr n1, NodePtr n2) {
    return add_integers_rec(n1, n2, false);
}

int main() {
    std::vector<int> v1 = {0,2,9};
    std::vector<int> v2 = {9,8,1};
    List l1 = List(v1);
    List l2 = List(v2);

    l1.head = add_integers(l1.head, l2.head);
    l1.print();

}