#ifndef TREE_NODE_H
#define TREE_NODE_H

template<typename T>
struct TreeNode
{   
    TreeNode() {}
    TreeNode(T v) : value(v) {} // init value
    // Default values
    T value{ -1 };
    TreeNode<T>* l{ nullptr };
    TreeNode<T>* r{ nullptr };
};

#endif