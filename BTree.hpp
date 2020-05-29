/**
 * @file BTree.hpp
 * @author paul
 * @date 27.05.20
 * Definition of the BTree class
 */
#ifndef HUFFMAN_BTREE_HPP
#define HUFFMAN_BTREE_HPP

#include <memory>
#include <optional>

/**
 * Class template for binary trees. Both nodes and leafs contain an item of type T.
 * @tparam T the type of both nodes and leafs
 */
template<typename T>
class BTree {
    public:
        /**
         * Alias for the pointer to child nodes
         */
        using child_ptr = std::shared_ptr<BTree<T>>;

        /**
         * Leaf CTor, constructs a tree without children
         * @param elem the value of the leaf
         */
        explicit BTree(T elem) : elem{elem} {};

        /**
         * Node CTor, constructs a tree with children
         * @param elem the value of this node
         * @param l a pointer to the left child
         * @param r a pointer to the right child
         */
        BTree(T elem, child_ptr l, child_ptr r)
            : elem{elem}, children{std::make_pair(l, r)} {};

        /**
         * Get the value of the node
         * @return a const reference to the value of the node
         */
        auto get() const -> const T& {
            return elem;
        }

        /**
         * Get the left child
         * @return a pointer to the left child
         */
        auto left() const -> const child_ptr& {
            return children.value().first;
        }

        /**
         * Get the right child
         * @return a pointer to the right child
         */
        auto right() const -> const child_ptr& {
            return children.value().second;
        }

        /**
         * Check wether the node is a leaf (i.e. no children)
         * @return true of the node is a leaf
         */
        [[nodiscard]] auto leaf() const -> bool {
            return !children.has_value();
        }

    private:
        T elem; ///< Value of the node

        /**
         * The pointer to the children, the pointers are always valid. There are either zero or two children.
         */
        std::optional<std::pair<child_ptr, child_ptr>> children;
};

#endif //HUFFMAN_BTREE_HPP
