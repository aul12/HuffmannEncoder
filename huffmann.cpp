/**
 * @file huffmann.cpp
 * @author paul
 * @date 27.05.20
 * Description here TODO
 */
#include "huffmann.hpp"

#include <vector>

namespace huffman {
    auto build(const std::map<char, float> &probs) -> huffman::Tree {
        if (probs.empty()) {
            throw std::runtime_error{"probs not a valid PDF"};
        }

        std::vector<Tree> nodes;
        nodes.reserve(probs.size());

        for (const auto &[c, p] : probs) {
            nodes.emplace_back(std::make_pair(c, p));
        }

        while (nodes.size() >= 2) {
            std::sort(nodes.begin(), nodes.end(),
                      [](const auto &a, const auto &b) {
                          return a.get().second < b.get().second;
                      });

            const auto &l = nodes[0];
            const auto &r = nodes[1];
            const auto elem = std::make_pair<Elem::first_type, Elem::second_type>(std::nullopt,
                                                                            l.get().second + r.get().second);
            const auto lPtr = std::make_shared<Tree>(l);
            const auto rPtr = std::make_shared<Tree>(r);

            const Tree combined{elem, lPtr, rPtr};
            nodes.erase(nodes.begin(), nodes.begin()+2);
            nodes.emplace_back(combined);
        }

        return std::move(nodes.front());
    }

    auto getMapping(const Tree &tree, const std::string &prefix) -> std::map<char, std::string> {
        if (tree.leaf()) {
            return std::map<char, std::string>{{tree.get().first.value(), prefix}};
        } else {
            const auto lMap = getMapping(*tree.left(), prefix+"0");
            const auto rMap = getMapping(*tree.right(), prefix+"1");
            std::map<char, std::string> res = lMap;
            res.insert(rMap.cbegin(), rMap.cend());
            return res;
        }
    }
}
