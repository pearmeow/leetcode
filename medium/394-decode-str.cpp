/**
 * @file 394-decode-str.cpp
 * @author Perry Huang
 * @date 2024-10-15
 */

#include <stack>
#include <string>

std::string decodeString(const std::string& s) {
    std::string curr, res;
    std::stack<char> braces;
    int reps = 0, pos1 = 0, pos2 = 0;

    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] >= 0 && s[i] <= 9 && braces.empty()) {
            reps = reps * 10 + s[i] - '0';
        } else if (s[i] == '[') {
            if (braces.empty()) pos1 = i;
            braces.push('[');
        } else if (s[i] == ']') {
            braces.pop();
            if (braces.empty()) {
                pos2 = i;
                curr = decodeString(s.substr(pos1 + 1, pos2 - pos1));
                for (int j = 0; j < reps; ++j) {
                    res += curr;
                }
                pos1 = 0, pos2 = 0, reps = 0;
                curr = "";
            }
        } else if (braces.empty()) {
            res += s[i];
        }
    }

    return res;
}
