// Problem: Insertion sort a unordered linked list
#include <iostream>
#include <vector>
#include "lib/linkedList.h"
#include "lib/linkedListNode.h"

using namespace std;

void insert(LinkedList<int>& sorted_list, int value) {
    cout << "Inserting: " << value << '\n';
    int index = 0;
    LinkedListNode<int>* cur = sorted_list.head;
    if (cur == nullptr) {
        sorted_list.insert(value, 0);
        return;
    }
    while (cur != nullptr) {
        if (cur->value > value) {
            sorted_list.insert(value, index);
            return;
        }
        cur = cur->next;
        ++index;
    }
    sorted_list.insert(value, index);
}

void insertion_sort(LinkedList<int>& unsorted, LinkedList<int>& sorted) {
    LinkedListNode<int>* cur = unsorted.head;
    while (cur != nullptr) {
        insert(sorted, cur->value);
        cur = cur->next;
    }
}

int main() {
    LinkedList<int> sorted = LinkedList<int>();
    vector<int> v = {2, 4, 1, 0, 10, 3, 2, -1};
    LinkedList<int> unsorted = LinkedList<int>(v);
    cout << "Original List: ";
    unsorted.print();
    insertion_sort(unsorted, sorted);
    cout << "Sorted: ";
    sorted.print();

}