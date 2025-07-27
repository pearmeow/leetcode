/**
 * @file 22-generate-parentheses.cpp
 * @author Perry Huang
 * @date 2025-06-19
 * 22. Generate Parentheses
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 */

#include <string>
#include <vector>

class Solution {
   public:
    void genParen(std::vector<std::string>& combins, std::string curr, int left, int right, int n) {
        if (left == n && right == n) {
            combins.push_back(curr);
        } else if (left == n) {
            genParen(combins, curr + ')', left, right + 1, n);
        } else if (left > right) {
            genParen(combins, curr + '(', left + 1, right, n);
            genParen(combins, curr + ')', left, right + 1, n);
        } else {
            genParen(combins, curr + '(', left + 1, right, n);
        }
    }

    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> combins;
        genParen(combins, "", 0, 0, n);
        return combins;
    }
};
