/**
 * @file huffmann.hpp
 * @author paul
 * @date 27.05.20
 * Declaration of the huffman related functions
 */
#ifndef HUFFMAN_HUFFMAN_HPP
#define HUFFMAN_HUFFMAN_HPP

#include <map>

#include "BTree.hpp"

/**
 * Namespace for huffman related functions
 */
namespace huffman {
    /**
     * Struct which is used as element in the huffman tree
     */
    struct HuffmanElem {
        std::optional<char> character{}; ///< Character, only set for leafs
        float prob{}; ///< Probability of the character, set for both leafs and nodes
    };

    using Tree = BTree<HuffmanElem>; ///< A huffman tree is a tree of HuffmanElems

    /**
     * Construct the huffman tree from a given pdf.
     * @param probs the probability distribution for the characters
     * @return the constructed huffman tree
     * @throws std::runtime_error if probs is empty
     */
    auto build(const std::map<char, float> &probs) -> Tree;

    /**
     * Get the mapping for a given tree.
     * @param tree the huffman tree
     * @param prefix an optional prefix, can be ignored if not required
     * @return the mapping from character to corresponding (binary) string
     */
    auto getMapping(const Tree &tree, const std::string &prefix = "") -> std::map<char, std::string>;
}

#endif //HUFFMAN_HUFFMAN_HPP
