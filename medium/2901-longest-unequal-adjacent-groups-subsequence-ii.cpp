/**
 * @file 2901-longest-unequal-adjacent-groups-subsequence-ii.cpp
 * @author Perry Huang
 * @date 2025-05-16
 * 2901. Longest Unequal Adjacent Groups Subsequence II
 * You are given a string array words, and an array groups, both arrays having length n.
 * The hamming distance between two strings of equal length is the number of positions at which the corresponding
 * characters are different.
 * You need to select the longest subsequence from an array of indices [0, 1, ..., n - 1], such that for the
 * subsequence denoted as [i0, i1, ..., ik-1] having length k, the following holds: For adjacent indices in the
 * subsequence, their corresponding groups are unequal, i.e., groups[ij] != groups[ij+1], for each j where 0 < j +
 * 1 < k. words[ij] and words[ij+1] are equal in length, and the hamming distance between them is 1, where 0 < j +
 * 1 < k for all indices in the subsequence. Return a string array containing the words corresponding to the
 * indices (in order) in the selected subsequence. If there are multiple answers, return any of them. Note: strings
 * in words may be unequal in length.
 */

#include <string>
#include <utility>
#include <vector>

class Solution {
public:
    int hamm_dist(const std::string& str1, const std::string& str2) {
        if (str1.size() != str2.size()) return -1;
        int res = 0;
        for (size_t i = 0; i < str1.size(); ++i) {
            if (str1[i] != str2[i]) ++res;
        }
        return res;
    }

    std::vector<std::string> getWordsInLongestSubsequence(std::vector<std::string>& words,
                                                          std::vector<int>& groups) {
        std::vector<std::string> res;
        std::vector<std::pair<int, int>> dp(words.size(),
                                            std::pair<int, int>{-1, 1});  // first=nextIndex, second=maxLength
        int maxLen = 1;
        size_t start = 0;
        for (size_t i = dp.size(); i > 0; --i) {
            for (size_t j = i - 1; j > 0; --j) {
                if (groups[j - 1] != groups[i - 1] &&
                    hamm_dist(words[j - 1], words[i - 1]) == 1  // subsequence eligibility
                    && dp[i - 1].second + 1 >
                           dp[j - 1].second) {  // can form longer subsequence if this one is linked to i
                    dp[j - 1].first = i - 1;    // link
                    dp[j - 1].second = dp[i - 1].second + 1;
                    if (dp[j - 1].second > maxLen) {
                        maxLen = dp[j - 1].second;
                        start = j - 1;
                    }
                }
            }
        }
        size_t curr = start;
        while (dp[curr].first != -1) {
            res.push_back(words[curr]);
            curr = dp[curr].first;
        }
        res.push_back(words[curr]);
        return res;
    }
};
