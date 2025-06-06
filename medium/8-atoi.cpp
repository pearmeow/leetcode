/**
 * @file 8-atoi.cpp
 * @author Perry Huang
 * @date 2/24/2024
 *
 * 8. String to Integer (atoi)
 * Description of problem:
 * The algorithm for myAtoi(string s) is as follows:
 * Read in and ignore any leading whitespace.
 * Check if the next character (if not already at the end of the string) is '-' or
 * '+'. Read this character in if it is either. This determines if the final result
 * is negative or positive respectively. Assume the result is positive if neither
 * is present. Read in next the characters until the next non-digit character or
 * the end of the input is reached. The rest of the string is ignored. Convert
 * these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits
 * were read, then the integer is 0. Change the sign as necessary. If the integer
 * is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the
 * integer so that it remains in the range. Specifically, integers less than -231
 * should be clamped to -231, and integers greater than 231 - 1 should be clamped
 * to 231 - 1. Return the integer as the final result.
 */

#include <iostream>

int myAtoi(const std::string& s) {
    long long res = 0;
    bool negative = false;
    size_t pos = 0;
    while (s[pos] == ' ' && pos < s.size()) ++pos;
    if (pos == s.size()) return res;
    if (s[pos] == '-') {
        negative = true;
        ++pos;
    } else if (s[pos] == '+') {
        ++pos;
    }

    for (size_t i = pos; i < s.size(); ++i) {
        std::cout << s[pos] << " at position " << i << std::endl;
        if (s[i] >= '0' && s[i] <= '9') {
            res *= 10;
            res += (s[i] - '0');
            if (res > 2147483647 && !negative) {
                return 2147483647;
            } else if (negative && res * -1 < -2147483648) {
                return -2147483648;
            }
        } else {
            break;
        }
    }
    if (negative) res *= -1;
    return (int)res;
}
