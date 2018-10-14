// Implement a class that implements an InOrder Iterator on a Binary Tree
// The expectation is to write two critical methods of any iterator: hasNext() and getNext().

#include "./lib/tree.h"
#include <iostream>
#include <vector>
#include <stack>

class InorderIterator {

public:

    TreeNode<int>* root{nullptr};
    TreeNode<int>* cur{nullptr};
    std::stack<TreeNode<int>*> s;

    // When iterator is initialized it is always
    // at the first element of tree in its in-order
    InorderIterator(TreeNode<int>* root) {
        root = root;
        cur = root;
        while (cur != nullptr) {
            s.push(cur);
            cur = cur->l;
        }
    }
    
    bool hasNext() {
        return not(s.empty());
    }

    // getNext returns null if there are no more elements in tree
    TreeNode<int>* getNext() {
        TreeNode<int>* temp;
        cur = s.top();
        s.pop();
        if (cur->r != nullptr) {
            s.push(cur->r);
            temp = cur->r->l;
            if(temp != nullptr) {
                s.push(temp);
            } 
        }
        return cur;
    }
};

int main() {
    std::vector<int> v1 = {100, 50, 200, -1, 25, 125, 350};

    Tree<int> t1 = Tree<int>(v1);

    InorderIterator it = InorderIterator(t1.root);

    while (it.hasNext()) {
        std::cout << it.getNext()->value << ' ';
    }
    std::cout << '\n';


}
