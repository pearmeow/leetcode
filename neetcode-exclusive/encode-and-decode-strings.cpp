/**
 * @file encode-and-decode-strings.cpp
 * @author Perry Huang
 * @date 2025-06-12
 * Encode and Decode Strings
 * Design an algorithm to encode a list of strings to a single string.
 * The encoded string is then decoded back to the original list of strings.
 * Please implement encode and decode
 */

#include <string>
#include <vector>

class Solution {
public:
    std::string encode(const std::vector<std::string>& strs) {
        std::string res;
        for (const std::string& s : strs) {
            res += std::to_string(s.size()) + "#" + s;
        }
        return res;
    }

    std::vector<std::string> decode(const std::string& s) {
        size_t curr = 0;
        size_t currSize = 0;
        std::string sizeStr;
        std::vector<std::string> res;
        while (curr < s.size()) {
            if (s[curr] != '#') {
                sizeStr += s[curr];
                ++curr;
            } else {
                currSize = std::stoi(sizeStr);
                if (currSize != 0) {
                    res.push_back(s.substr(curr + 1, currSize));
                } else {
                    res.push_back("");
                }
                curr += currSize + 1;
                currSize = 0;
                sizeStr.clear();
            }
        }
        return res;
    }
};
