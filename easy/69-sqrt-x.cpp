/**
 * @file 69-sqrt-x.cpp
 * @author Perry Huang
 * @date 2025-08-09
 * 69. Sqrt(x)
 * Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned
 * integer should be non-negative as well. You must not use any built-in exponent function or operator. For
 * example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 */

class Solution {
public:
    long long mySqrt(long long x) {
        if (x == 0 || x == 1) {
            return x;
        }
        long long low = 0;
        long long high = x;
        long long mid = low + (high - low) / 2;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (mid * mid < x) {
                if ((mid + 1) * (mid + 1) > x) {
                    return mid;
                }
                low = mid;
            } else if (mid * mid > x) {
                high = mid;
            } else {
                return mid;
            }
        }
        return mid;
    }
};
