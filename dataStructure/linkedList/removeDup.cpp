// Problem: Remove duplicate nodes in a linked list

#include <iostream>
#include <vector>
#include <unordered_set>
#include "lib/linkedList.h"
#include "lib/linkedListNode.h"

using namespace std;

void remove_duplicates(LinkedList<int>& list) {
    int index = 0;
    unordered_set<int> unique_values;
    unordered_set<int>::iterator result;
    LinkedListNode<int>* cur = list.head;
    while (cur != nullptr) {
        result = unique_values.find(cur->value);
        if (result == unique_values.end()) {
            unique_values.insert(cur->value);
            cur = cur->next;
            ++index;
        }
        else {
            cur = cur->next;
            list.remove(index);
        }
    }
}

int main() {
    vector<int> v1 = {1, 2, 2, 3, 4, 3};
    vector<int> v2 = {3, 3, 3};
    vector<int> v3 = {1};

    vector<int> test_cases[] = {v1, v2, v3};
    int n_test_cases = sizeof(test_cases) / sizeof(vector<int>);

    for (int i=0; i<n_test_cases; ++i) {
        LinkedList<int> list = LinkedList<int>(test_cases[i]);
        cout << "Original List: ";
        list.print();
        remove_duplicates(list);
        cout << "After Removal: ";
        list.print();
    }
}