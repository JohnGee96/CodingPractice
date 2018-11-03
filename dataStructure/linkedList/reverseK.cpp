// Problem: Reverse first K nodes in a linked list

#include <vector>
#include <iostream>
#include "lib/linkedList.h"
#include "lib/linkedListNode.h"

typedef LinkedListNode<int>* NodePtr;
typedef LinkedList<int> List;

NodePtr reverse_k(NodePtr head, int k) {
    if (k <= 1 || head == nullptr)
        return head;
    NodePtr tail = head;
    NodePtr cur = head;
    NodePtr prev = nullptr;
    NodePtr next;
    // std::cout << "About to reverse\n";
    while (k > 0 && cur != nullptr) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        --k;
        // std::cout << "loop\n";
    }
    if (cur != nullptr) 
        tail->next = cur;
        
    return prev; 
}

int main() {
    std::vector<int> v = {1,2,3,4,5};
    List l = List(v);

    l.head = reverse_k(l.head, 4);
    l.print();
}