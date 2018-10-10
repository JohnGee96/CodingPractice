#ifndef TREE_H
#define TREE_H

#include <vector>
#include "treeNode.h"

template<typename T>
class Tree {
public:
    Tree() {};
    Tree(std::vector<T> v);
    ~Tree();

    TreeNode<T>* root{ nullptr};

private:
    TreeNode<T>* build_(TreeNode<T>* p, std::vector<T>& v, int lvl);
};

template <typename T>
Tree<T>::Tree(std::vector<T> v) {
    if (v.size() > 0) {
        root = build_(nullptr, v, 0);
    }
}

template <typename T>
TreeNode<T>* Tree<T>::build_(TreeNode<T>* parent, std::vector<T>& v, int lvl) {
    if (lvl < v.size()) {
        parent = new TreeNode<T>(v[lvl]);

        parent->l = build_(parent->l, v, 2 * lvl + 1);
        parent->r = build_(parent->r, v, 2 * lvl + 2);
    }
    return parent;
}

template <typename T>
Tree<T>::~Tree() {}
#endif