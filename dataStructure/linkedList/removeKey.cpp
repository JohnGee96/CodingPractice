// Problem remove key in a linked list
#include <iostream>
#include <vector>
#include "lib/linkedList.h"
#include "lib/linkedListNode.h"

using namespace std;

void delete_node(LinkedListNode<int>*& head, int key) {
    LinkedListNode<int>* prev = nullptr;
    LinkedListNode<int>* cur = head;
    while (cur != nullptr) {
        if (cur->value == key) {
            if (cur == head) {
                head = head->next;
                delete cur;
                cur = head;
            }
            else {
                prev->next = cur->next;
                delete cur;
                cur = prev->next;
            }
        }
        else {
            prev = cur;
            cur = cur->next;
        }
    }
}

int main() {
    vector<int> v1 = {1, 2, 3, 3, 3, 4, 5, 6, 7};
    LinkedList<int> list1 = LinkedList<int>(v1);
    cout << "Original List: ";
    list1.print();
    delete_node(list1.head, 3);
    cout << "After Removing 3: ";
    list1.print();

    vector<int> v2 = {1, 2, 3, 4, 5, 6, 7};
    LinkedList<int> list2 = LinkedList<int>(v2);
    cout << "Original List: ";
    list2.print();
    delete_node(list2.head, 1);
    cout << "After Removing 1: ";
    list2.print();

    vector<int> v3 = {1, 2, 3, 4, 5, 6, 7};
    LinkedList<int> list3 = LinkedList<int>(v3);
    cout << "Original List: ";
    list3.print();
    delete_node(list3.head, 7);
    cout << "After Removing 7: ";
    list3.print();
}