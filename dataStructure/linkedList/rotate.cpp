// Rotate a Linked List
// Given head node of a singly linked list and an integer 'n', rotate linked list by 'n'.

#include "./lib/linkedList.h"
#include "./lib/linkedListNode.h"
#include <vector>
#include <iostream>

typedef LinkedListNode<int>* NodePtr;
typedef LinkedList<int> List;

NodePtr rotate_list(NodePtr head, int n) {
    if (n != 0) {
        int list_len = 0;
        int tail_index = 0;
        NodePtr tail = nullptr;
        NodePtr cur = head;

        while (cur != nullptr) { // pretend we don't know the length
            tail = cur;
            cur = cur->next;
            ++list_len;
        }
        
        if (n < 0) {
            return rotate_list(head, list_len + n);
        }
        else {
            n = n % list_len;
            tail_index = list_len - n; // new tail index
        }
        std::cout << n << ' ' << tail_index << '\n';
        
        cur = head;
        // shift the temp ptr to the new tail
        for (int i=1; i<tail_index; ++i) {
            cur = cur->next;
        }

        NodePtr temp = nullptr;
        // swap the two segments
        temp = head;
        head = cur->next;
        tail->next = temp; // stitch the tail segment onto the head

        cur->next = nullptr;
    }
    return head;
}

int main() {
    std::vector<int> v = {1,2,3,4,5};
    List l = List(v);

    NodePtr r = rotate_list(l.head, 6);

    List result;
    result.head = r;
    result.print();

}