/**
 * @file 338-counting-bits.cpp
 * @author Perry Huang
 * @date 2024-10-27
 * 338. Counting Bits
 * Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n)
 * ans[i] is the number of 1's in the binary representation of i.
 */

#include <vector>

class Solution {
public:
    std::vector<int> countBits(int n) {
        size_t size = 1, curr = 1, index = 0;
        std::vector<int> bits(n + 1, 0);
        while (curr < bits.size()) {
            if (curr == size) {
                size = size * 2;
                index = 0;
            }
            bits[curr] = bits[index] + 1;
            ++index;
            ++curr;
        }
        return bits;
    }
};
