#include <gtest/gtest.h>

#include "../huffman.hpp"

TEST(huffman, build_invalid) {
    EXPECT_THROW(huffman::build({}), std::runtime_error);
}

TEST(huffman, build_simple) {
    std::map<char, float> probs{
            {'a', 0.5},
            {'b', 0.5}
    };
    auto tree = huffman::build(probs);

    ASSERT_FALSE(tree.leaf());
    EXPECT_FLOAT_EQ(tree.get().prob, 1);

    EXPECT_TRUE(tree.left()->leaf());
    EXPECT_FLOAT_EQ(tree.left()->get().prob, 0.5);
    ASSERT_TRUE(tree.left()->get().character.has_value());
    EXPECT_TRUE(tree.left()->get().character.value() == 'a' or tree.left()->get().character.value() == 'b');

    EXPECT_TRUE(tree.right()->leaf());
    EXPECT_FLOAT_EQ(tree.right()->get().prob, 0.5);
    ASSERT_TRUE(tree.right()->get().character.has_value());
    EXPECT_TRUE(tree.right()->get().character.value() == 'a' or tree.right()->get().character.value() == 'b');

    EXPECT_NE(tree.left()->get().character, tree.right()->get().character);
}

TEST(huffman, build_complex) {
    std::map<char, float> probs {
            {'a', 0.25},
            {'b', 0.25},
            {'c', 0.5}
    };

    auto tree = huffman::build(probs);

    ASSERT_FALSE(tree.leaf());
    EXPECT_FLOAT_EQ(tree.get().prob, 1.0);

    ASSERT_TRUE(tree.left()->leaf() or tree.right()->leaf());

    std::shared_ptr<huffman::Tree> contdTree, leaf;
    if (tree.left()->leaf()) {
        leaf = tree.left();
        contdTree = tree.right();
    } else {
        leaf = tree.right();
        contdTree = tree.left();
    }

    ASSERT_TRUE(leaf->leaf());
    EXPECT_FLOAT_EQ(leaf->get().prob, 0.5);
    ASSERT_TRUE(leaf->get().character.has_value());
    EXPECT_EQ(leaf->get().character.value(), 'c');

    EXPECT_TRUE(contdTree->left()->leaf());
    EXPECT_FLOAT_EQ(contdTree->left()->get().prob, 0.25);
    ASSERT_TRUE(contdTree->left()->get().character.has_value());
    EXPECT_TRUE(contdTree->left()->get().character.value() == 'a' or contdTree->left()->get().character.value() == 'b');

    EXPECT_TRUE(contdTree->right()->leaf());
    EXPECT_FLOAT_EQ(contdTree->right()->get().prob, 0.25);
    ASSERT_TRUE(contdTree->right()->get().character.has_value());
    EXPECT_TRUE(contdTree->right()->get().character.value() == 'a' or contdTree->right()->get().character.value() == 'b');

    EXPECT_NE(contdTree->left()->get().character, contdTree->right()->get().character);
}

TEST(huffman, mapping_simple) {
    auto leaf0 = std::make_shared<huffman::Tree>(huffman::HuffmanElem{'a', 0.5});
    auto leaf1 = std::make_shared<huffman::Tree>(huffman::HuffmanElem{'b', 0.5});
    huffman::Tree root{{std::nullopt, 1.0}, leaf0, leaf1};

    auto mapping = huffman::getMapping(root);

    ASSERT_NE(mapping.find('a'), mapping.end());
    ASSERT_NE(mapping.find('b'), mapping.end());

    EXPECT_NE(mapping['a'], mapping['b']);
    EXPECT_EQ(mapping['a'].size(), 1);
    EXPECT_EQ(mapping['b'].size(), 1);
}

TEST(huffman, mapping_complex) {
    auto leaf00 = std::make_shared<huffman::Tree>(huffman::HuffmanElem{'a', 0.25});
    auto leaf01 = std::make_shared<huffman::Tree>(huffman::HuffmanElem{'b', 0.25});
    auto leaf0 = std::make_shared<huffman::Tree>(huffman::HuffmanElem{'c', 0.5});
    auto leaf1 = std::make_shared<huffman::Tree>(huffman::HuffmanElem{std::nullopt, 0.5}, leaf00, leaf01);
    huffman::Tree root{huffman::HuffmanElem{std::nullopt, 1.0}, leaf0, leaf1};

    auto mapping = huffman::getMapping(root);
    ASSERT_NE(mapping.find('a'), mapping.end());
    ASSERT_NE(mapping.find('b'), mapping.end());
    ASSERT_NE(mapping.find('c'), mapping.end());

    EXPECT_EQ(mapping['a'].size(), 2);
    EXPECT_EQ(mapping['b'].size(), 2);
    EXPECT_EQ(mapping['c'].size(), 1);
    EXPECT_NE(mapping['a'], mapping['b']);
    EXPECT_NE(mapping['a'][0], mapping['c'][0]); // Prefix
    EXPECT_NE(mapping['b'][0], mapping['c'][0]);
    EXPECT_EQ(mapping['a'][0], mapping['b'][0]);
}
