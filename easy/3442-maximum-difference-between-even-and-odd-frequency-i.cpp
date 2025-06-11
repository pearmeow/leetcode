/*
 * @file 3442-maximum-difference-between-even-and-odd-frequency-i.cpp
 * @author Perry Huang
 * @date 2025-06-09
 * 3442. Maximum Difference Between Even and Odd Frequency I
 * You are given a string s consisting of lowercase English letters.
 * Your task is to find the maximum difference diff = a1 - a2 between
 * the frequency of characters a1 and a2 in the string such that:
 * a1 has an odd frequency in the string.
 * a2 has an even frequency in the string.
 * Return this maximum difference.
 */

#include <string>
#include <vector>

int maxDifference(const std::string& s) {
    std::vector<int> freq(26);
    for (size_t i = 0; i < s.size(); ++i) {
        ++freq[s[i] - 'a'];
    }
    int evenMin = 0;
    int oddMax = 0;
    for (size_t i = 0; i < freq.size(); ++i) {
        if (freq[i] % 2 == 0) {
            if (evenMin == 0 || (evenMin > freq[i] && freq[i] != 0)) {
                evenMin = freq[i];
            }
        } else {
            oddMax = std::max(oddMax, freq[i]);
        }
    }
    return oddMax - evenMin;
}
