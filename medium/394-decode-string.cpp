/**
 * @file 394-decode-string.cpp
 * @author Perry Huang
 * @date 2024-10-15
 * 394. Decode String
 * Given an encoded string, return its decoded string.
 * The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated
 * exactly k times. Note that k is guaranteed to be a positive integer. You may assume that the input string is
 * always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume
 * that the original data does not contain any digits and that digits are only for those repeat numbers, k. For
 * example, there will not be input like 3a or 2[4]. The test cases are generated so that the length of the output
 * will never exceed 105.
 */

#include <stack>
#include <string>

class Solution {
public:
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
};
