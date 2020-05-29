/**
 * @file util.hpp
 * @author paul
 * @date 27.05.20
 * Declaration of the util namespace
 */
#ifndef HUFFMAN_UTIL_HPP
#define HUFFMAN_UTIL_HPP

#include <map>

/**
 * Namespace for utility functions
 */
namespace util {
    /**
     * Read a file and estimate the character probability using relative frequencies.
     * Characters consisting of multiple bytes are not handled separately.
     * @param filename the file from which to read
     * @return the probability of every character that is in the file.
     */
    auto buildHist(const std::string &filename) -> std::map<char, float>;
}

#endif //HUFFMAN_UTIL_HPP
