#include "gtest/gtest.h"
#include "treeNode.h"
#include "tree.h"

TEST(TreeNode, DefaultInit) {
    TreeNode<int> node = TreeNode<int>();
    EXPECT_EQ(node.value, -1);
    EXPECT_EQ(node.l, nullptr);
    EXPECT_EQ(node.r, nullptr);
}

TEST(TreeNode, ParamInit) {
    TreeNode<int> node = TreeNode<int>(2);
    EXPECT_EQ(node.value, 2);
    EXPECT_EQ(node.l, nullptr);
    EXPECT_EQ(node.r, nullptr);
}

TEST(Tree, DefaultInit) {
    Tree<int> t = Tree<int>();
    EXPECT_EQ(t.root, nullptr);
}

TEST(Tree, InitWithArray) {
    std::vector<int> v = {1, 2, 3};
    Tree<int> t = Tree<int>(v);
    EXPECT_EQ(t.root->value, 1);
    EXPECT_EQ(t.root->l->value, 2);
    EXPECT_EQ(t.root->r->value, 3);
    EXPECT_EQ(t.root->l->l, nullptr);
    EXPECT_EQ(t.root->l->r, nullptr);
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}