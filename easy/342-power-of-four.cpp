/**
 * @file 342-power-of-four.cpp
 * @author Perry Huang
 * @date 2025-08-14
 * 342. Power of Four
 * Given an integer n, return true if it is a power of four. Otherwise, return false.
 * An integer n is a power of four, if there exists an integer x such that n == 4x.
 */

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n < 0) return false;
        long long pow_four = 1;
        while (pow_four <= n) {
            if (pow_four == n) {
                return true;
            }
            pow_four *= 4;
        }
        return false;
    }
};
