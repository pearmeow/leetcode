/**
 * @file 647-palindromic-substrings.cpp
 * @author Perry Huang
 * @date 2025-07-23
 * 647. Palindromic Substrings
 * Given a string s, return the number of palindromic substrings in it.
 * A string is a palindrome when it reads the same backward as forward.
 * A substring is a contiguous sequence of characters within the string.
 */

#include <string>
#include <vector>

class Solution {
   public:
    int countSubstrings(const std::string& s) {
        // substr_palinds[x][y] represents the palindromes in [x, y]
        std::vector<std::vector<int>> substr_palinds(s.size(), std::vector<int>(s.size(), 0));
        for (size_t xy = 0; xy < substr_palinds.size(); ++xy) {
            substr_palinds[xy][xy] = 1;  // all length 1 substrings are palindromes
        }
        int res = s.size();
        for (size_t y = 1; y < substr_palinds.size(); ++y) {
            int incr = 0;
            for (size_t x = 0; x < substr_palinds.size(); ++x) {
                if (y + incr >= substr_palinds.size()) {
                    break;
                }
                if (s[x] == s[y + incr]) {
                    if (substr_palinds[x + 1][y + incr - 1] != 1 && x + 1 <= y + incr - 1) {
                        substr_palinds[x][y + incr] = 0;
                    } else {
                        substr_palinds[x][y + incr] = 1;
                        ++res;
                    }
                }
                ++incr;
            }
        }
        return res;
    }
};
