// Problem: Reverse a singly linked list

#include <stdlib.h>
#include "lib/linkedList.h"
#include "lib/linkedListNode.h"

using namespace std;

void reverse(LinkedList<int> list) {
    LinkedListNode<int>* prev = nullptr;
    LinkedListNode<int>* curr = list.head;
    LinkedListNode<int>* next;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    list.tail = list.head;
    list.head = prev;
}

int main() {
    std::vector<int> v = {1, 2, 3};
    LinkedList<int> list = LinkedList<int>(v);

    cout << "Original List: "; 
    list.print();
    reverse(list);
    cout << "After reverse: ";
    list.print();

    return 0;
}


