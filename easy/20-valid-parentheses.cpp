/**
 * @file 20-valid-parentheses.cpp
 * @author Perry Huang
 * @date 2025-06-14
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
 * determine if the input string is valid.
 * An input string is valid if:
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * Every close bracket has a corresponding open bracket of the same type.
 */

#include <stack>
#include <string>

class Solution {
    bool isValid(const std::string& s) {
        std::stack<char> brackets;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                brackets.push(c);
            } else {
                if (brackets.empty()) {
                    return false;
                }
                if (brackets.top() == '(' && c == ')') {
                    brackets.pop();
                } else if (brackets.top() == '{' && c == '}') {
                    brackets.pop();
                } else if (brackets.top() == '[' && c == ']') {
                    brackets.pop();
                } else {
                    return false;
                }
            }
        }
        return brackets.empty();
    }
};
