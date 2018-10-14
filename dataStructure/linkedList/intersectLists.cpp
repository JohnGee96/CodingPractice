// Given head nodes of two linked lists that may or 
// may not intersect, find out if they intersect and 
// return the point of intersection; return null otherwise.

#include "./lib/linkedList.h"
#include "./lib/linkedListNode.h"
#include <vector>
#include <iostream>

LinkedListNode<int>* intersect(
    LinkedList<int>& l1,
    LinkedList<int>& l2) {
    
    int l1_len = l1.size;
    int l2_len = l2.size;
    int len_diff = 0;
    LinkedListNode<int>* longerNode; 
    LinkedListNode<int>* shorterNode;

    if (l1_len >= l2_len) {
        len_diff = l1_len - l2_len;
        longerNode = l1.head;
        shorterNode = l2.head;
    }
    else {
        len_diff = l2_len - l1_len;
        longerNode = l2.head;
        shorterNode = l1.head;
    }
    
    for (unsigned i=0; i<len_diff; ++i) {
        longerNode = longerNode->next;
    }

    while (shorterNode != nullptr) {
        if (longerNode == shorterNode){
            return longerNode;
        }
        longerNode = longerNode -> next;
        shorterNode = shorterNode -> next;
    }
}


int main() {
    std::vector<int> v1 = {-1,0};
    std::vector<int> v2 = {0};
    std::vector<int> v3 = {1,2,3};
    
    LinkedList<int> l1 = LinkedList<int>(v1);
    LinkedList<int> l2 = LinkedList<int>(v2);
    LinkedList<int> l3 = LinkedList<int>(v3);

    // append the shared list
    l1.tail->next = l3.head;
    l1.tail = l3.tail;
    l2.tail->next = l3.head;
    l2.tail = l3.tail;

    LinkedListNode<int>* r1 = intersect(l1, l2);
    LinkedListNode<int>* r2 = intersect(l1, l1);

    std::cout << "Expect to print 1: " << r1->value << '\n';
    std::cout << "Expect to print -1: " << r2->value << '\n';
}