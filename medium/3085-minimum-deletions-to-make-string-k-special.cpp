/**
 * @file 3085-minimum-deletions-to-make-string-k-special.cpp
 * @author Perry Huang
 * @date 2025-06-20
 * 3085. Minimum Deletions to Make String K-Special
 * You are given a string word and an integer k.
 * We consider word to be k-special if |freq(word[i]) - freq(word[j])| <= k for all indices i and j in the string.
 * Here, freq(x) denotes the frequency of the character x in word, and |y| denotes the absolute value of y.
 * Return the minimum number of characters you need to delete to make word k-special.
 */

#include <algorithm>
#include <climits>
#include <string>
#include <vector>

class Solution {
   public:
    int minimumDeletions(const std::string& word, int k) {
        std::vector<int> freqs(26, 0);
        for (char c : word) {
            ++freqs[c - 'a'];
        }
        int minDels = INT_MAX;
        int currMin = 0;
        int prevDels = 0;
        size_t start = 0;
        size_t end = 0;
        std::sort(freqs.begin(), freqs.end());
        for (size_t i = 0; i < freqs.size(); ++i) {
            if (freqs[i] == 0) {
                continue;
            }
            currMin = prevDels;
            for (size_t j = i + 1; j < freqs.size(); ++j) {
                if (freqs[j] - freqs[i] > k) {
                    currMin += freqs[j] - freqs[i] - k;
                }
            }
            minDels = std::min(minDels, currMin);
            prevDels += freqs[i];
        }
        return minDels;
    }
};
