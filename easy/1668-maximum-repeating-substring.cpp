/**
 * @file 1668-maximum-repeating-substring.cpp
 * @author Perry Huang
 * @date 2024-10-30
 * 1668. Maximum Repeating Substring
 * For a string sequence, a string word is k-repeating if word concatenated k times is a substring of sequence
 * The word's maximum k-repeating value is the highest value k where word is k-repeating in sequence
 * If word is not a substring of sequence, word's maximum k-repeating value is 0
 * Given strings sequence and word, return the maximum k-repeating value of word in sequence.
 */

#include <string>

class Solution {
public:
    int maxRepeating(std::string sequence, std::string word) {
        int count = 0, tempCount = 0;
        for (size_t i = 0; i < word.size(); ++i) {
            for (size_t j = i; j < sequence.size(); j += word.size()) {
                if (sequence.compare(j, word.size(), word, 0, word.size()) == 0) {
                    tempCount += 1;
                } else {
                    count = std::max(tempCount, count);
                    tempCount = 0;
                }
            }
            count = std::max(tempCount, count);
            tempCount = 0;
        }
        return count;
    }
};
