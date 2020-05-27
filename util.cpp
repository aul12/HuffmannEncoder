/**
 * @file util.cpp
 * @author paul
 * @date 27.05.20
 * Description here TODO
 */
#include <fstream>
#include "util.hpp"

namespace util {
    auto buildHist(const std::string &filename) -> std::map<char, float> {
        std::map<char, float> res;

        std::size_t count = 0;
        std::ifstream stream(filename);

        using c_stream_it = std::istreambuf_iterator<char>;

        for (auto it = c_stream_it{stream}; it != c_stream_it{}; ++it) {
            res[*it] += 1;
            count += 1;
        }

        for (auto &[c, p] : res) {
            p /= count;
        }

        return res;
    }
}
