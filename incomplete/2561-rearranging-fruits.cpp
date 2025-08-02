/**
 * @file 2561-rearranging-fruits.cpp
 * @author Perry Huang
 * @date 2025-08-01
 * 2561. Rearranging Fruits
 * You have two fruit baskets containing n fruits each. You are given two 0-indexed integer arrays basket1 and
 * basket2 representing the cost of fruit in each basket. You want to make both baskets equal. To do so, you can
 * use the following operation as many times as you want: Chose two indices i and j, and swap the ith fruit of
 * basket1 with the jth fruit of basket2. The cost of the swap is min(basket1[i],basket2[j]). Two baskets are
 * considered equal if sorting them according to the fruit cost makes them exactly the same baskets. Return the
 * minimum cost to make both the baskets equal or -1 if impossible.
 */

#include <unordered_map>
#include <vector>

class Solution {
public:
    long long minCost(std::vector<int>& basket1, std::vector<int>& basket2) {
        std::unordered_map<int, int> freqs1;
        std::unordered_map<int, int> freqs2;
        for (size_t i = 0; i < basket1.size(); ++i) {
            if (freqs1.find(basket1[i]) == freqs1.end()) {
                freqs1[basket1[i]] = 1;
            } else {
                ++freqs1[basket1[i]];
            }
            if (freqs2.find(basket2[i]) == freqs2.end()) {
                freqs2[basket2[i]] = 1;
            } else {
                ++freqs2[basket2[i]];
            }
        }
        for (auto& [key, appearances] : freqs1) {
            if (freqs2[key] + appearances % 2 == 1) {
                return -1;
            }
        }
        for (auto& [key, appearances] : freqs2) {
            if (freqs1[key] + appearances % 2 == 1) {
                return -1;
            }
        }
    }
};
