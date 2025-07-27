/**
 * @file 2138-divide-a-string-into-groups-of-size-k.cpp
 * @author Perry Huang
 * @date 2025-06-21
 */

#include <string>
#include <vector>

class Solution {
    std::vector<std::string> divideString(const std::string& s, int k, char fill) {
        std::vector<std::string> res;
        for (size_t i = 0; i < s.size(); i += k) {
            if (i + k > s.size()) {
                res.push_back(s.substr(i, std::string::npos));
            } else {
                res.push_back(s.substr(i, k));
            }
        }
        if (res[res.size() - 1].size() != k) {
            while (res[res.size() - 1].size() != k) {
                res[res.size() - 1] += fill;
            }
        }
        return res;
    }
};
