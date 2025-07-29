/**
 * @file 121-best-time-to-buy-and-sell-stock.cpp
 * @author Perry Huang
 * @date 2024-10-28
 * 121. Best Time to Buy and Sell Stock
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.
 * You want to maximize your profit by choosing a single day to buy one stock
 * and choosing a different day in the future to sell that stock.
 * Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
 */

#include <vector>

class Solution {
public:
    int maxProfit(const std::vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;
        for (size_t i = 1; i < prices.size(); ++i) {
            if (minPrice > prices[i]) {
                minPrice = prices[i];
            } else {
                maxProfit = std::max(maxProfit, prices[i] - minPrice);
            }
        }
        return maxProfit;
    }
};
