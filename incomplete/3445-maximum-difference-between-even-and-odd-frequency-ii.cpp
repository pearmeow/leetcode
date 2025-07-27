/**
 * @file 3445-maximum-difference-between-even-and-odd-frequency-ii.cpp
 * @author Perry Huang
 * @date 2025-06-11
 * 3445. Maximum Difference Between Even and Odd Frequency II
 * You are given a string s and an integer k. Your task is to find the
 * maximum difference between the frequency of two characters, freq[a] - freq[b], in a substring subs of s, such
 * that: subs has a size of at least k. Character a has an odd frequency in subs. Character b has an even frequency
 * in subs. Return the maximum difference. Note that subs can contain more than 2 distinct characters.
 */

#include <string>
#include <vector>

class Solution {
public:
    int maxDifference(const std::string& s, int k) {
        std::vector<int> nums(5, 0);
        int res = 0;
        for (size_t x = 0; x < s.size(); ++x) {
            for (int& num : nums) {
                num = 0;
            }
            for (size_t y = x; y < s.size(); ++y) {
                ++nums[s[y] - '0'];
                if (y - x + 1 < k) {
                    continue;
                }
                int oddMax = 0;
                int evenMin = 0;
                for (int num : nums) {
                    if (num % 2 == 0) {  // even
                        if (num != 0) {
                            if (evenMin == 0) {
                                evenMin = num;
                            } else {
                                evenMin = std::min(num, evenMin);
                            }
                        }
                    } else {
                        oddMax = std::max(oddMax, num);
                    }
                }
                if (oddMax == 0 || evenMin == 0) {
                    continue;
                } else {
                    if (res == 0) {
                        res = oddMax - evenMin;
                    } else {
                        res = std::max(res, oddMax - evenMin);
                    }
                }
            }
        }
        return res;
    }
};
