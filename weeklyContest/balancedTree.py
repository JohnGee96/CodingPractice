# Complete Binary Tree Inserter

# A complete binary tree is a binary tree in which every level, 
# except possibly the last, is completely filled, and all nodes 
# are as far left as possible.

# Write a data structure CBTInserter that is initialized with a
# complete binary tree and supports the following operations:

# CBTInserter(TreeNode root) initializes the data structure on 
# a given tree with head node root;

# CBTInserter.insert(int v) will insert a TreeNode into the 
# tree with value node.val = v so that the tree remains complete,
# and returns the value of the parent of the inserted TreeNode;

# CBTInserter.get_root() will return the head node of the tree.

# Example 1:

# Input: inputs = ["CBTInserter","insert","get_root"], inputs = [[[1]],[2],[]]
# Output: [null,1,[1,2]]
# Example 2:

# Input: inputs = ["CBTInserter","insert","insert","get_root"], inputs = [[[1,2,3,4,5,6]],[7],[8],[]]
# Output: [null,3,4,[1,2,3,4,5,6,7,8]]

# Definition for a binary tree node.

# We can use an array to implement this tree
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class CBTInserter:

    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.tree = [root]
        for node in self.tree:
            if node.left: self.tree.append(node.left)
            if node.right: self.tree.append(node.right)

    def insert(self, v):
        """
        :type v: int
        :rtype: int
        """
        tree_size = len(self.tree)
        self.tree.append(TreeNode(v))
        if tree_size % 2:
            self.tree[int((tree_size - 1) / 2)].left = self.tree[-1]
        else:
            self.tree[int((tree_size - 1) / 2)].right = self.tree[-1]
        return self.tree[int((tree_size - 1) / 2)].val
        
    def get_root(self):
        """
        :rtype: TreeNode
        """
        return self.tree[0]

# Your CBTInserter object will be instantiated and called as such:
# obj = CBTInserter(root)
# param_1 = obj.insert(v)
# param_2 = obj.get_root()