#include "gtest/gtest.h"
#include "linkedList.h"
#include <vector>
#include <iostream>

TEST(LinkedListNodeTest, Init) {
    int v = 11;
    LinkedListNode<int> node = LinkedListNode<int>(v);
    EXPECT_EQ(v, node.value);
}

TEST(LinkedList, Init) {
    std::vector<int> v = {1, 2, 3};
    LinkedList<int>list = LinkedList<int>(v);
    EXPECT_EQ(list.head->value, v[0]);
    EXPECT_EQ(list.head->next->value, v[1]);
    EXPECT_EQ(list.tail->value, v[v.size() - 1]);
}

TEST(LinkedList, removeHead) {
    std::vector<int> v = {1, 2, 3};
    LinkedList<int> list = LinkedList<int>(v);
    list.remove(0);
    EXPECT_EQ(list.head->value, v[1]);
}

TEST(LinkedList, removeMiddle) {
    std::vector<int> v = {1, 2, 3};
    LinkedList<int> list = LinkedList<int>(v);
    list.remove(1);
    EXPECT_EQ(list.head->next->value, 3);
    EXPECT_EQ(list.tail->value, 3);
}

TEST(LinkedList, removeTail) {
    std::vector<int> v = {1, 2, 3};
    LinkedList<int> list = LinkedList<int>(v);
    list.remove(2);
    EXPECT_EQ(list.tail->value, v[1]);
}

TEST(LinkedList, insertHead) {
    std::vector<int> v = {1, 2, 3};
    LinkedList<int> list = LinkedList<int>(v);
    list.insert(0, 0);
    EXPECT_EQ(list.head->value, 0);
}

TEST(LinkedList, insertMiddle) {
    std::vector<int> v = {1, 2, 4};
    LinkedList<int> list = LinkedList<int>(v);
    list.insert(3, 2);
    EXPECT_EQ(list.head->next->next->value, 3);
    EXPECT_EQ(list.head->next->next->next->value, 4);
    EXPECT_EQ(list.tail->value, 4);
}

TEST(LinkedList, insertTail) {
    std::vector<int> v = {1, 2, 3};
    LinkedList<int> list = LinkedList<int>(v);
    list.insert(4, 3);
    EXPECT_EQ(list.tail->value, 4);
}

TEST(LinkedList, insertEmpty) {
    std::vector<int> v = {};
    LinkedList<int> list = LinkedList<int>(v);
    list.insert(0, 0);
    EXPECT_EQ(list.head->value, 0);
    EXPECT_EQ(list.tail->value, 0);
}

TEST(LinkedList, appendEmpty) {
    std::vector<int> v = {};
    LinkedList<int> list = LinkedList<int>(v);
    list.append(0);
    EXPECT_EQ(list.head->value, 0);
    EXPECT_EQ(list.tail->value, 0);
}

TEST(LinkedList, appendNonEmpty) {
    std::vector<int> v = {1};
    LinkedList<int> list = LinkedList<int>(v);
    list.append(2);
    EXPECT_EQ(list.head->next->value, 2);
    EXPECT_EQ(list.tail->value, 2);
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
