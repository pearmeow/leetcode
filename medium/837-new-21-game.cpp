/**
 * @file 837-new-21-game.cpp
 * @author Perry Huang
 * @date 2025-08-16
 * 837. New 21 Game
 * Alice plays the following game, loosely based on the card game "21".
 * Alice starts with 0 points and draws numbers while she has less than k points. During each draw, she gains an
 * integer number of points randomly from the range [1, maxPts], where maxPts is an integer. Each draw is
 * independent and the outcomes have equal probabilities. Alice stops drawing numbers when she gets k or more
 * points. Return the probability that Alice has n or fewer points. Answers within 10-5 of the actual answer are
 * considered accepted.
 */

#include <vector>

class Solution {
public:
    double new21Game(int n, int k, int max_pts) {
        std::vector<double> dp(n + 1, -1);  // accounts for 0 to n points
        double prob = 0;
        int num_probs = 0;
        for (size_t decr = 1; decr <= dp.size(); ++decr) {
            size_t curr_pts = dp.size() - decr;
            if (curr_pts > n) {
                dp[curr_pts] = 0;
            } else if (curr_pts >= k && curr_pts <= n) {
                dp[curr_pts] = 1;
            } else {
                dp[curr_pts] = prob / max_pts;
            }
            if (num_probs == max_pts) {
                prob -= dp[curr_pts + max_pts];
            } else {
                ++num_probs;
            }
            prob += dp[curr_pts];
        }
        return dp[0];
    }
};
