/**
 * @file util.hpp
 * @author paul
 * @date 27.05.20
 * Description here TODO
 */
#ifndef HUFFMAN_UTIL_HPP
#define HUFFMAN_UTIL_HPP

#include <map>

namespace util {
    auto buildHist(const std::string &filename) -> std::map<char, float>;
}

#endif //HUFFMAN_UTIL_HPP
