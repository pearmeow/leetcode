/**
 * @file 2434-using-a-robot-to-print-the-lexicographically-smallest-string.cpp
 * @author Perry Huang
 * @date 2025-06-06
 * 2434. Using a Robot to Print the Lexicographically Smallest String
 * You are given a string s and a robot that currently holds an empty string t.
 * Apply one of the following operations until s and t are both empty:
 * Remove the first character of a string s and give it to the robot.
 * The robot will append this character to the string t.
 * Remove the last character of a string t and give it to the robot. The robot will write this character on paper.
 * Return the lexicographically smallest string that can be written on the paper.
 */

#include <stack>
#include <string>
#include <vector>

void findMins(const std::string& word, std::vector<char>& nextMins) {
    char curr = 'z';
    for (size_t i = word.size(); i != 0; --i) {
        if (word[i - 1] < curr) {
            curr = word[i - 1];
        }
        nextMins[i - 1] = curr;
    }
}

std::string robotWithString(const std::string& s) {
    std::stack<char> stackStr;
    std::string res = "";
    std::vector<char> nextMins(s.size());
    findMins(s, nextMins);
    size_t ind = 0;
    while (ind < s.size()) {
        if (stackStr.empty()) {
            stackStr.push(s[ind]);
            ++ind;
        } else if (nextMins[ind] < stackStr.top()) {
            stackStr.push(s[ind]);
            ++ind;
        } else {
            res += stackStr.top();
            stackStr.pop();
        }
    }
    while (!stackStr.empty()) {
        res += stackStr.top();
        stackStr.pop();
    }
    return res;
}
