/**
 * @file 67-add-binary.cpp
 * @author Perry Huang
 * @date 2025-08-08
 * 67. Add Binary
 * Given two binary strings a and b, return their sum as a binary string.
 */

#include <string>

class Solution {
public:
    std::string addBinary(const std::string& a, const std::string& b) {
        size_t max_size = std::max(a.size(), b.size());
        std::string res = "";
        int carry = 0;
        for (size_t decr = 1; decr <= max_size; ++decr) {
            if (decr <= a.size() && a[a.size() - decr] == '1') {
                ++carry;
            }
            if (decr <= b.size() && b[b.size() - decr] == '1') {
                ++carry;
            }
            if (carry == 3) {
                res += '1';
                carry = 1;
            } else if (carry == 2) {
                res += '0';
                carry = 1;
            } else if (carry == 1) {
                res += '1';
                carry = 0;
            } else if (carry == 0) {
                res += '0';
            }
        }
        if (carry == 1) {
            res += '1';
        }
        return std::string(res.rbegin(), res.rend());
    }
};
