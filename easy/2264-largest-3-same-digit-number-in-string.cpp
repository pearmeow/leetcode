/**
 * @file 2264-largest-3-same-digit-number-in-string.cpp
 * @author Perry Huang
 * @date 2025-08-13
 * You are given a string num representing a large integer. An integer is good if it meets the following
 * conditions: It is a substring of num with length 3. It consists of only one unique digit. Return the maximum
 * good integer as a string or an empty string "" if no such integer exists. Note: A substring is a contiguous
 * sequence of characters within a string. There may be leading zeroes in num or a good integer.
 */

#include <string>

class Solution {
public:
    std::string largestGoodInteger(const std::string& num) {
        char prev = ' ';
        int prev_count = 0;
        char max_good = ' ';
        for (char c : num) {
            if (c != prev) {
                prev = c;
                prev_count = 1;
                continue;
            }
            ++prev_count;
            if (prev_count >= 3) {
                max_good = std::max(prev, max_good);
            }
        }
        if (max_good == ' ') return "";
        return std::string(3, max_good);
    }
};
