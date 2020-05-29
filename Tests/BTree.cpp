#include <gtest/gtest.h>

#include "../BTree.hpp"

TEST(BTree, Leaf) {
    BTree<int> tree{1};
    EXPECT_TRUE(tree.leaf());
}
