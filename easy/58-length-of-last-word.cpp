/**
 * @file 58-length-of-last-word.cpp
 * @author Perry Huang
 * @date 2025-08-08
 * 58. Length of Last Word
 * Given a string s consisting of words and spaces, return the length of the last word in the string.
 * A word is a maximal substring consisting of non-space characters only.
 */

#include <string>

class Solution {
public:
    int lengthOfLastWord(const std::string& s) {
        int res = 0;
        for (size_t decr = 1; decr <= s.size(); ++decr) {
            if (s[s.size() - decr] == ' ' && res != 0) {
                break;
            } else if (s[s.size() - decr] != ' ') {
                ++res;
            }
        }
        return res;
    }
};
