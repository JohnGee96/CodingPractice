// Given a singly linked list, reverse nodes at even indices.
#include "./lib/linkedList.h"
#include "./lib/linkedListNode.h"
#include <vector>
#include <iostream>

typedef LinkedListNode<int>* NodePtr;
typedef LinkedList<int> List;


NodePtr reverse_even_nodes(NodePtr head) {
    NodePtr even_head, even_cur, cur;
    even_head = even_cur = nullptr;
    cur = head;
    int index = 1;

    while (cur != nullptr) {
        if (index % 2 == 1) {
            even_cur = cur->next;
            if (even_cur != nullptr) {
                 // push to the start of the list (reversing the order at the same time)
                cur->next = even_cur->next; 
                even_cur->next = even_head;
                even_head = even_cur;
            }            
        }
        else {
            cur = cur->next;
        }
        ++index;
    }
    
    NodePtr temp = head;
    cur = head;
    even_cur = even_head;
    // merge the even and odd linked list together
    while (cur != nullptr && even_cur != nullptr) {
        temp = cur->next;
        cur->next = even_cur;
        
        cur = temp; // update the current node
        temp = even_cur->next;
        
        even_cur->next = cur;
        even_cur = temp; // update even list current node
    }

    return head;
}    

int main() {
    std::vector<int> v1 = {};
    std::vector<int> v2 = {1};
    std::vector<int> v3 = {1,2,3,4,5};
    std::vector<int> v4 = {1,2,3,4,5,6};
    List l1 = List(v1);
    List l2 = List(v2);
    List l3 = List(v3);
    List l4 = List(v4);

    NodePtr r1 = reverse_even_nodes(l1.head);
    NodePtr r2 = reverse_even_nodes(l2.head);
    NodePtr r3 = reverse_even_nodes(l3.head);
    NodePtr r4 = reverse_even_nodes(l4.head);
    
    List result;
    result.head = r1;
    result.print();
    result.head = r2;
    result.print();
    result.head = r3;
    result.print();
    result.head = r4;
    result.print();
}