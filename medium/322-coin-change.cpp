/**
 * @file 322-coin-change.cpp
 * @author Perry Huang
 * @date 2025-06-13
 * 322. Coin Change
 * You are given an integer array coins representing coins of different denominations and
 * an integer amount representing a total amount of money.
 * Return the fewest number of coins that you need to make up that amount.
 * If that amount of money cannot be made up by any combination of the coins, return -1.
 * You may assume that you have an infinite number of each kind of coin.
 */

#include <climits>
#include <vector>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        std::vector<int> leastAmounts(amount + 1, INT_MAX);
        leastAmounts[0] = 0;
        for (size_t i = 0; i < leastAmounts.size(); ++i) {
            for (int coinVal : coins) {
                if (i < coinVal) {
                    continue;
                }
                if (leastAmounts[i - coinVal] != INT_MAX) {
                    leastAmounts[i] = std::min(leastAmounts[i], leastAmounts[i - coinVal] + 1);
                }
            }
        }
        if (leastAmounts[amount] == INT_MAX) {
            return -1;
        }
        return leastAmounts[amount];
    }
};
