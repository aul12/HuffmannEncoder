/**
 * @file huffmann.hpp
 * @author paul
 * @date 27.05.20
 * Description here TODO
 */
#ifndef HUFFMAN_HUFFMAN_HPP
#define HUFFMAN_HUFFMAN_HPP

#include <map>

#include "BTree.hpp"

namespace huffman {
    struct HuffmannElem {
        std::optional<char> character{};
        float prob{};
    };

    using Tree = BTree<HuffmannElem>;

    auto build(const std::map<char, float> &probs) -> Tree;

    auto getMapping(const Tree &tree, const std::string &prefix = "") -> std::map<char, std::string>;
}

#endif //HUFFMAN_HUFFMAN_HPP
