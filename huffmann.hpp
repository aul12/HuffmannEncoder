/**
 * @file huffmann.hpp
 * @author paul
 * @date 27.05.20
 * Description here TODO
 */
#ifndef HUFFMAN_HUFFMANN_HPP
#define HUFFMAN_HUFFMANN_HPP

#include <map>

#include "BTree.hpp"

namespace huffman {
    using Elem = std::pair<std::optional<char>, float>;
    using Tree = BTree<Elem>;

    auto build(const std::map<char, float> &probs) -> Tree;

    auto getMapping(const Tree &tree, const std::string &prefix = "") -> std::map<char, std::string>;
}

#endif //HUFFMAN_HUFFMANN_HPP
