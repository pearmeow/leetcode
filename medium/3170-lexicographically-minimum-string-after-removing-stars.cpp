/**
 * @file 3170-lexicographically-minimum-string-after-removing-stars.cpp
 * @author Perry Huang
 * @date 2025-06-06
 * 3170. Lexicographically Minimum String After Removing Stars
 * You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.
 * While there is a '*', do the following operation:
 * Delete the leftmost '*' and the smallest non-'*' character to its left.
 * If there are several smallest characters, you can delete any of them.
 * Return the lexicographically smallest resulting string after removing all '*' characters.
 */

#include <string>
#include <queue>
#include <utility>

std::string clearStars(std::string s) {
    auto lexComp = [](const std::pair<char, int>& a, const std::pair<char, int>& b) {
        if (a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    };
    std::priority_queue<std::pair<char, size_t>, std::vector<std::pair<char, size_t>>,
        decltype(lexComp)> minChars(lexComp);
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == '*') {
            size_t leastInd = minChars.top().second;
            s[leastInd] = '*';
            minChars.pop();
        } else {
            minChars.push({s[i], i});
        }
    }
    std::string res = "";
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] != '*') {
            res += s[i];
        }
    }
    return res;
}
