// Given roots of two binary trees, determine if these trees are identical or not.

#include "./lib/tree.h"
#include <iostream>
#include <vector>

bool are_identical(TreeNode<int>* root1, TreeNode<int>* root2) {
    if (root1 == nullptr && root2 == nullptr)
        return true;
    else if (root1 != nullptr && root2 != nullptr) {
        return (root1->value == root2->value) && 
                are_identical(root1->l, root2->l) &&
                are_identical(root1->r, root2->r);
    }
    return false;
}

int main() {
    std::vector<int> v1 = {100, 50, 200, -1, 25, 125, 350};
    std::vector<int> v2 = {100, 50, 200, 25, -1, 125, 350};

    Tree<int> t1 = Tree<int>(v1);
    Tree<int> t2 = Tree<int>(v2);

    std::cout << are_identical(t1.root, t1.root) << '\n';
}
