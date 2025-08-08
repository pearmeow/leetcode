/**
 * @file 808-soup-servings.cpp
 * @author Perry Huang
 * @date 2025-08-07
 * 808. Soup Servings
 * Companies
 * You have two soups, A and B, each starting with n mL. On every turn, one of the following four serving
 * operations is chosen at random, each with probability 0.25 independent of all previous turns: pour 100 mL from
 * type A and 0 mL from type B pour 75 mL from type A and 25 mL from type B pour 50 mL from type A and 50 mL from
 * type B pour 25 mL from type A and 75 mL from type B Note: There is no operation that pours 0 mL from A and 100
 * mL from B. The amounts from A and B are poured simultaneously during the turn. If an operation asks you to pour
 * more than you have left of a soup, pour all that remains of that soup. The process stops immediately after any
 * turn in which one of the soups is used up. Return the probability that A is used up before B, plus half the
 * probability that both soups are used up in the same turn. Answers within 10-5 of the actual answer will be
 * accepted.
 */

#include <cmath>
#include <vector>

class Solution {
public:
    double soupServings(long long n) {
        if (n > 4800) {
            return 1;
        }
        std::vector<std::vector<std::pair<double, double>>> dp(
            n / 25 + 2, std::vector<std::pair<double, double>>(n / 25 + 2, {-1, -1}));
        std::pair<double, double> chances = helper(n, n, dp);
        return chances.first + chances.second / 2;
    }
    // returns [a used up chance, both used up chance]
    std::pair<double, double> helper(long long a_ml, long long b_ml,
                                     std::vector<std::vector<std::pair<double, double>>>& dp) {
        if (a_ml <= 0) {
            a_ml = 0;
        }
        if (b_ml <= 0) {
            b_ml = 0;
        }
        if (a_ml <= 0 && b_ml <= 0) {
            dp[a_ml][b_ml] = {0, 1};
        } else if (a_ml <= 0) {
            dp[a_ml][std::ceil(b_ml / 25.0)] = {1, 0};
        } else if (b_ml <= 0) {
            dp[std::ceil(a_ml / 25.0)][b_ml] = {0, 0};
        }
        if (dp[std::ceil(a_ml / 25.0)][std::ceil(b_ml / 25.0)].first != -1) {
            return dp[std::ceil(a_ml / 25.0)][std::ceil(b_ml / 25.0)];
        }
        auto chances1 = helper(a_ml - 100, b_ml, dp);
        auto chances2 = helper(a_ml - 75, b_ml - 25, dp);
        auto chances3 = helper(a_ml - 50, b_ml - 50, dp);
        auto chances4 = helper(a_ml - 25, b_ml - 75, dp);
        double a_before_b = (chances1.first + chances2.first + chances3.first + chances4.first) / 4;
        double both = (chances1.second + chances2.second + chances3.second + chances4.second) / 4;
        dp[std::ceil(a_ml / 25.0)][std::ceil(b_ml / 25.0)] = {a_before_b, both};
        return dp[std::ceil(a_ml / 25.0)][std::ceil(b_ml / 25.0)];
    }
};

int main() {
    Solution sol;
    sol.soupServings(400);
}
