/**
 * @file 14-longest-common-prefix.cpp
 * @author Perry Huang
 * @date 2024-02-25
 * 14. Longest Common Prefix
 * Write a function to find the longest common prefix string amongst an array of
 * strings. If there is no common prefix, return an empty string "".
 */

#include <string>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(const std::vector<std::string>& strs) {
        std::string lcp;
        char curr = ' ';
        size_t min_size = strs[0].size();
        for (size_t i = 0; i < strs.size(); ++i) {
            min_size = std::min(strs[i].size(), min_size);
        }
        for (size_t i = 0; i < min_size; ++i) {
            for (size_t j = 0; j < strs.size(); ++j) {
                if (curr == ' ') {
                    curr = strs[j][i];
                } else if (curr != strs[j][i]) {
                    return lcp;
                }
            }
            lcp += curr;
            curr = ' ';
        }
        return lcp;
    }
};
