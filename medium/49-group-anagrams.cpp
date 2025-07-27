/**
 * @file 49-group-anagrams.cpp
 * @author Perry Huang
 * @date 2025-01-12
 * 49. Group Anagrams
 * Given an array of strings strs, group the anagrams together. You can return the answer in any order.
 */

#include <string>
#include <unordered_map>
#include <vector>

class Solution {
   public:
    std::string findFrequencies(const std::string& str) {
        std::vector<int> freq(26, 0);
        std::string res;
        for (char c : str) {
            ++freq[c - 'a'];
        }
        for (size_t i = 0; i < freq.size(); ++i) {
            res += freq[i];
            res += "#";
        }
        return res;
    }

    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::vector<std::vector<std::string>> res;
        std::unordered_map<std::string, int> anagrams;
        int counter = 0;
        for (size_t i = 0; i < strs.size(); ++i) {
            std::string freq = findFrequencies(strs[i]);
            if (anagrams.find(freq) == anagrams.end()) {
                anagrams[freq] = counter;
                ++counter;
                res.emplace_back(1, strs[i]);
            } else {
                res[anagrams[freq]].push_back(strs[i]);
            }
        }
        return res;
    }
};
