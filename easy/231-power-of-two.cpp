/**
 * @file 231-power-of-two.cpp
 * @author Perry Huang
 * @date 2025-08-08
 * 231. Power of Two
 * Given an integer n, return true if it is a power of two. Otherwise, return false.
 * An integer n is a power of two, if there exists an integer x such that n == 2x.
 */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 1) {
            return false;
        }
        while ((n & 1) == 0) {
            n = n >> 1;
        }
        return n == 1;
    }
};
