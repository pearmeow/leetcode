/**
 * @file 746-min-cost-climbing-stairs.cpp
 * @author Perry Huang
 * @date 2024-10-27
 * 746. Min Cost Climbing Stairs
 * You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost,
 * you can either climb one or two steps. You can either start from the step with index 0, or the step with
 * index 1. Return the minimum cost to reach the top of the floor.
 */

#include <vector>

class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        for (size_t i = cost.size() - 2; i > 0; --i) {
            cost[i - 1] = cost[i - 1] + std::min(cost[i], cost[i + 1]);  // determine the minimum as you go
        }  // the min of cost at index x has to be it's positional cost plus the least cost between pos x + 1 and x
           // + 2
        return std::min(cost[0],
                        cost[1]);  // since you can start at 0 or 1, the least cost is between the two positions
    }

    // memory hungry memoization solution

    int minCostClimbingStairsMemo(std::vector<int>& cost) {
        std::vector<int> memo(cost.size(), 0);
        return std::min(helper(memo, cost, 0), helper(memo, cost, 1));
    }

    int helper(std::vector<int>& memo, std::vector<int>& cost, int pos) {
        if (pos == cost.size()) return 0;
        if (memo[pos] != 0) return memo[pos];
        if (pos == cost.size() - 1) {  // prevents going over the size by 1 for the pos + 2 case
            memo[pos] = cost[pos];
            return cost[pos];
        }
        int minCost = std::min(helper(memo, cost, pos + 1), helper(memo, cost, pos + 2));
        memo[pos] = cost[pos] + minCost;  // current cost plus minCost of taking either 1 step or 2
        return memo[pos];
    }
};
