// Merge Sort
// Given head pointer of a linked sort, sort linked list (in ascending order)
// using merge sort and return new head pointer of sorted linked list.

#include "./lib/linkedList.h"
#include "./lib/linkedListNode.h"
#include <vector>
#include <iostream>

typedef LinkedListNode<int>* NodePtr;
typedef LinkedList<int> List;

void split(List& orig_list, List& l1, List& l2) {
    if (orig_list.size > 1) {
        NodePtr faster_ptr = orig_list.head->next;
        NodePtr slower_ptr = orig_list.head;
        while (faster_ptr != nullptr) {
            faster_ptr = faster_ptr->next;
            if (faster_ptr != nullptr) {
                faster_ptr = faster_ptr->next;
                slower_ptr = slower_ptr->next;
            }
        }    
        l1.head = orig_list.head;
        l1.size = int((orig_list.size + 1) / 2);
        l2.head = slower_ptr->next;
        l2.size = orig_list.size - l1.size;
        
        slower_ptr->next = nullptr; // Slice the list into two
        // l1.print();
        // l2.print();
    }
    else {
        l1.head = orig_list.head;
        l2.head = nullptr;
    }
}

List merge(List& l1, List& l2) {
    if (l1.size == 0)
        return l2;
    else if (l2.size == 0)
        return l1;

    List new_list;
    NodePtr temp1 = l1.head;
    NodePtr temp2 = l2.head;
    while (temp1 != nullptr && temp2 != nullptr) {
        if (temp1->value <= temp2->value) {
            new_list.append(temp1->value);
            temp1 = temp1->next;
        }
        else {
            new_list.append(temp2->value);
            temp2 = temp2->next;
        }
    }
    while (temp1 != nullptr) {
        new_list.append(temp1->value);
        temp1 = temp1->next;
    }
    while (temp2 != nullptr) {
        new_list.append(temp2->value);
        temp2 = temp2->next;
    }
    return new_list;
}

List merge_sort(List& l) {
    // std::cout << "Calling merge sort on ";
    // l.print();
    // std::cout << "Size: " << l.size << '\n';
    // std::cout << '\n';
    if (l.size > 1) {
        List l1;
        List l2;
        split(l, l1, l2);
        // std::cout << "Done splitting\n";
        l1 = merge_sort(l1);
        // std::cout << "recurse on the 2nd half \n";
        l2 = merge_sort(l2);
        // std::cout << "Done recurse on 2nd half\n";
        // std::cout << "l1 head: " << l1.head << '\n';
        // l1.print();
        // std::cout << "l1 head value: " << l1.head->value << '\n';
        // l1.print();
        // l2.print();
        return merge(l1, l2);
    }
    // std::cout << "len < 1\n";
    // std::cout << "paramter list: " << l.head << '\n';
    // List temp1 = List();
    // temp1.append(l.head->value);
    // std::cout << "new list: " << temp1.head << '\n';
    return l;

};

int main() {
    std::vector<int> v1 = {3,6,1,22,3,4,5,6,7,7,45,4};
    List l1 = List(v1);

    List r = merge_sort(l1);
    r.print();
}