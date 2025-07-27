/**
 * @file 3136-valid-word.cpp
 * @author Perry Huang
 * @date 2025-07-14
 * 3136. Valid Word
 * A word is considered valid if:
 * It contains a minimum of 3 characters.
 * It contains only digits (0-9), and English letters (uppercase and lowercase).
 * It includes at least one vowel.
 * It includes at least one consonant.
 * You are given a string word.
 * Return true if word is valid, otherwise, return false.
 * Notes:
 * 'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
 * A consonant is an English letter that is not a vowel.
 */

#include <bitset>
#include <set>
#include <string>

class Solution {
    bool isValid(const std::string& word) {
        if (word.size() < 3) {
            return false;
        }
        std::bitset<2> bits(0b00);
        std::set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for (char c : word) {
            if (c >= '0' && c <= '9') {
                continue;
            } else if (vowels.find(c) != vowels.end()) {
                bits[0] = true;
            } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                bits[1] = true;
            } else {
                return false;
            }
        }
        return bits[0] && bits[1];
    }
};
