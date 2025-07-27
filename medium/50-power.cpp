/**
 * @file 50-power.cpp
 * @author Perry Huang
 * @date 2024-10-12
 * 50. Pow(x, n)
 * Calculate x raised to the power of n
 */

#include <cmath>

class Solution {
   public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == -1) return 1 / x;
        double halfPow = myPow(x, std::abs(n) / 2);
        double answer = halfPow * halfPow;
        if (std::abs(n) % 2 == 1) answer *= x;
        if (n < 0) return 1 / answer;
        return answer;
    }
};
