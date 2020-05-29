#include <gtest/gtest.h>

#include "../BTree.hpp"

TEST(BTree, Leaf) {
    BTree<int> tree{1};
    EXPECT_TRUE(tree.leaf());
}

TEST(BTree, NoLeaf) {
    auto leafPtr = std::make_shared<BTree<int>>(2);
    BTree<int> tree{1, leafPtr, leafPtr}; // Technically not a tree but a graph
    EXPECT_FALSE(tree.leaf());
}

TEST(BTree, GetLeaf) {
    BTree<int> tree{17};
    EXPECT_EQ(tree.get(), 17);
}

TEST(BTree, GetNode) {
    auto leafPtr = std::make_shared<BTree<int>>(2);
    BTree<int> tree{17, leafPtr, leafPtr}; // Technically not a tree but a graph
    EXPECT_EQ(tree.get(), 17);
}

TEST(BTree, GetLeft) {
    auto lPtr = std::make_shared<BTree<int>>(2);
    auto rPtr = std::make_shared<BTree<int>>(3);
    BTree<int> tree{17, lPtr, rPtr};
    EXPECT_EQ(tree.left(), lPtr);
}

TEST(BTree, GetRight) {
    auto lPtr = std::make_shared<BTree<int>>(2);
    auto rPtr = std::make_shared<BTree<int>>(3);
    BTree<int> tree{17, lPtr, rPtr};
    EXPECT_EQ(tree.right(), rPtr);
}
