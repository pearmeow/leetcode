/**
 * @file 150-evaluate-reverse-polish-notation.cpp
 * @author Perry Huang
 * @date 2025-06-15
 * 150. Evaluate Reverse Polish Notation
 * You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
 * Evaluate the expression. Return an integer that represents the value of the expression.
 * Note that:
 * The valid operators are '+', '-', '*', and '/'.
 * Each operand may be an integer or another expression.
 * The division between two integers always truncates toward zero.
 * There will not be any division by zero.
 * The input represents a valid arithmetic expression in a reverse polish notation.
 * The answer and all the intermediate calculations can be represented in a 32-bit integer.
 */

#include <stack>
#include <string>
#include <vector>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> nums;
        int op1 = 0;
        int op2 = 0;
        for (const std::string& s : tokens) {
            if (s != "+" && s != "-" && s != "*" && s != "/") {
                nums.push(std::stoi(s));
            } else {
                op2 = nums.top();
                nums.pop();
                op1 = nums.top();
                nums.pop();
                switch (s[0]) {
                    case ('+'):
                        nums.push(op1 + op2);
                        break;
                    case ('-'):
                        nums.push(op1 - op2);
                        break;
                    case ('*'):
                        nums.push(op1 * op2);
                        break;
                    case ('/'):
                        nums.push(op1 / op2);
                        break;
                }
            }
        }
        return nums.top();
    }
};
