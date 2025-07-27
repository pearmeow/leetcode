/**
 * @file 70-climbing-stairs.cpp
 * @author Perry Huang
 * @date 2024-03-02
 * 70. Climbing Stairs
 * You are climbing a staircase. It takes n steps to reach the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you
 * climb to the top?
 */

#include <vector>

class Solution {
    int helper(int n, std::vector<int>& memo) {
        if (memo[n] != 0) return memo[n];
        if (n <= 2) {
            memo[n] = n;
            return n;
        }
        memo[n] = helper(n - 1, memo) + helper(n - 2, memo);
        return memo[n];
    }

    int climbStairs(int n) {
        std::vector<int> memo(n + 1, 0);  // 1 stair: 1 way, 2 stairs: 2 ways
        return helper(n, memo);
    }
};
