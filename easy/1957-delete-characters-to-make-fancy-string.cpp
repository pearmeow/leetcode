/**
 * @file 1957-delete-characters-to-make-fancy-string.cpp
 * @author Perry Huang
 * @date 2025-07-20
 * 1957. Delete Characters to Make Fancy String
 * A fancy string is a string where no three consecutive characters are equal.
 * Given a string s, delete the minimum possible number of characters from s to make it fancy.
 * Return the final string after the deletion. It can be shown that the answer will always be unique.
 */

#include <string>

class Solution {
public:
    std::string makeFancyString(const std::string& s) {
        int count = 0;
        char curr = s[0];
        std::string res = "";
        for (char c : s) {
            if (c == curr) {
                if (count != 2) {
                    ++count;
                    res += c;
                }
            } else {
                curr = c;
                count = 1;
                res += c;
            }
        }
        return res;
    }
};
