/**
 * @file BTree.hpp
 * @author paul
 * @date 27.05.20
 * Description here TODO
 */
#ifndef HUFFMAN_BTREE_HPP
#define HUFFMAN_BTREE_HPP

#include <memory>
#include <optional>

template<typename T>
class BTree {
    public:
        using child_ptr = std::shared_ptr<BTree<T>>;

        explicit BTree(T elem) : elem{elem} {};

        BTree(T elem, child_ptr l, child_ptr r)
            : elem{elem}, children{std::make_pair(l, r)} {};

        auto get() const -> const T& {
            return elem;
        }

        auto left() const -> const child_ptr& {
            return children.value().first;
        }

        auto right() const -> const child_ptr& {
            return children.value().second;
        }

        [[nodiscard]] auto leaf() const -> bool {
            return !children.has_value();
        }

    private:
        T elem;
        std::optional<std::pair<child_ptr, child_ptr>> children;
};

#endif //HUFFMAN_BTREE_HPP
