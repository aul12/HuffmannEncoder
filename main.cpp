#include <iostream>

#include "util.hpp"
#include "huffman.hpp"

int main() {
    const auto probs = util::buildHist("main.cpp");
    const auto tree = huffman::build(probs);
    const auto mapping = huffman::getMapping(tree);

    for (const auto &[c, m] : mapping) {
        std::cout << c << " (" << static_cast<int>(c) << ") -> " << m << "\n";
    }

    return 0;
}
