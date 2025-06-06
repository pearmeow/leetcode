/**
 * @file 121-buy-stock.cpp
 * @author Perry Huang
 * @date 2024-10-28
 * 121. Best Time to Buy and Sell Stock
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.
 * You want to maximize your profit by choosing a single day to buy one stock
 * and choosing a different day in the future to sell that stock.
 * Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
 */

#include <vector>

int maxProfit(std::vector<int>& prices) {
    int profit = 0, minimum = prices[0];
    for (size_t i = 0; i < prices.size(); ++i) {
        profit = std::max(prices[i] - minimum, profit);
        if (prices[i] < minimum) minimum = prices[i];
    }
    return profit;
}
