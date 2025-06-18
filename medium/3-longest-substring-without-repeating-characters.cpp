/**
 * @file 3-longest-substring-without-repeating-characters.cpp
 * @author Perry Huang
 * @date 2025-06-18
 * Given a string s, find the length of the longest substring without duplicate characters.
 */

#include <map>
#include <string>

int lengthOfLongestSubstring(const std::string& s) {
    std::map<char, size_t> positions;
    size_t maxSize = 0;
    size_t currSize = 0;
    size_t startPos = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        if (positions.find(s[i]) == positions.end()) {
            ++currSize;
            positions[s[i]] = i;
        } else if (positions[s[i]] < startPos) {
            ++currSize;
            positions[s[i]] = i;
        } else {
            maxSize = std::max(currSize, maxSize);
            currSize = i - positions[s[i]];
            startPos = positions[s[i]] + 1;
            positions[s[i]] = i;
        }
    }
    maxSize = std::max(currSize, maxSize);
    return maxSize;
}
