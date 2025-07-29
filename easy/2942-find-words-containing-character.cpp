/**
 * @file 2942-find-words-containing-character.cpp
 * @author Perry Huang
 * @date 2025-05-23
 * 2942. Find Words Containing Character
 * You are given a 0-indexed array of strings words and a character x.
 * Return an array of indices representing the words that contain the character x.
 * Note that the returned array may be in any order.
 */

#include <string>
#include <vector>

class Solution {
public:
    bool hasChar(const std::string& word, char x) {
        for (size_t i = 0; i < word.size(); ++i) {
            if (word[i] == x) return true;
        }
        return false;
    }

    std::vector<int> findWordsContaining(std::vector<std::string>& words, char x) {
        std::vector<int> res;
        for (size_t i = 0; i < words.size(); ++i) {
            if (hasChar(words[i], x)) res.push_back(i);
        }
        return res;
    }
};
