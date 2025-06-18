/**
 * @file 38-count-sand-say.cpp
 * @author Perry Huang
 * @date 2025-05-24
 * 38. Count and Say
 * The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
 * countAndSay(1) = "1"
 * countAndSay(n) is the run-length encoding of countAndSay(n - 1).
 * Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters
 * (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters
 * (length of the run). For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32"
 * replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".
 * Given a positive integer n, return the nth element of the count-and-say sequence.
 */

#include <string>

std::string countAndSay(int n) {
    if (n == 1) {
        return "1";
    }
    std::string res;
    std::string prevCase = countAndSay(n - 1);
    int reps = 0;
    char curr = prevCase[0];
    for (size_t i = 0; i < prevCase.size(); ++i) {
        if (prevCase[i] == curr) {
            ++reps;
        } else {
            res += std::to_string(reps);
            res.append(1, curr);
            reps = 1;
            curr = prevCase[i];
        }
    }
    res += std::to_string(reps);
    res.append(1, curr);
    return res;
}
