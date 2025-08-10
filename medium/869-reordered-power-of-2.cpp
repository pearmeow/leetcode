/**
 * @file 869-reordered-power-of-2.cpp
 * @author Perry Huang
 * @date 2025-08-09
 * 869. Reordered Power of 2
 * You are given an integer n. We reorder the digits in any order (including the original order) such that the
 * leading digit is not zero. Return true if and only if we can do this so that the resulting number is a power of
 * two.
 */

#include <vector>

class Solution {
public:
    bool reorderedPowerOf2(long long n) {
        long long curr_num = 1;
        std::vector<long long> num_digits(10, 0);
        long long temp_n = n;
        while (temp_n != 0) {
            ++num_digits[temp_n % 10];
            temp_n /= 10;
        }
        while (curr_num < n * 10) {
            if (curr_num < n / 10) {
                curr_num *= 2;
                continue;
            }
            std::vector<long long> temp_digits = num_digits;
            long long temp_curr = curr_num;
            while (temp_curr != 0) {
                --temp_digits[temp_curr % 10];
                temp_curr /= 10;
            }
            bool can_reorder = true;
            for (long long i : temp_digits) {
                if (i != 0) {
                    can_reorder = false;
                    break;
                }
            }
            if (can_reorder) {
                return true;
            }
            curr_num *= 2;
        }
        return false;
    }
};
