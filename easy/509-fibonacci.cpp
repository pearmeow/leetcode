/**
 * @file 509-fibonacci.cpp
 * @author Perry Huang
 * @date 2024-03-02
 * 509. Fibonacci Number
 * The Fibonacci numbers, commonly denoted F(n) form a sequence,
 * called the Fibonacci sequence, such that each number is the
 * sum of the two preceding ones, starting from 0 and 1. That is,
 * F(0) = 0, F(1) = 1
 * F(n) = F(n - 1) + F(n - 2), for n > 1.
 * Given n, calculate F(n).
 */

#include <cstdio>  // for size_t

class Solution {
    int fib(int n) {
        if (n == 0 || n == 1) return n;
        int curr = 1, prev = 0, temp = 0;
        for (std::size_t i = 0; i < n - 1; ++i) {
            temp = prev;
            prev = curr;
            curr += temp;
        }
        return curr;
    }
};
