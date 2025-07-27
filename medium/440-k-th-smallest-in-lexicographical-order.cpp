/**
 * @file 440-k-th-smallest-in-lexicographical-order.cpp
 * @author Perry Huang
 * @date 2025-06-09
 * 440. K-th Smallest in Lexicographical Order
 * Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].
 */

#include <vector>

class Solution {
   public:
    int findKthNumber(int n, int k) {
        if (n < 10) return k;
        int kthNum = 0;
        int digits = 0;
        int firstDigit = n;
        std::vector<int> nDigits;
        while (firstDigit >= 10) {
            nDigits.push_back(firstDigit % 10);
            firstDigit /= 10;
            ++digits;
        }
        nDigits.push_back(firstDigit);
        ++digits;
        int subSize = 0;
        for (int i = 1; i < 10; ++i) {
            if (i > firstDigit) {
                subSize = subtreeSize(digits - 1);
            } else if (i < firstDigit) {
                subSize = subtreeSize(digits);
            } else {
                int prevSize = (firstDigit - 1) * subtreeSize(digits);
                int nextSize = (9 - firstDigit) * subtreeSize(digits - 1);
                subSize = n - prevSize - nextSize;
            }
            if (k > subSize) {
                k -= subSize;
            } else {
                // if i is more, then there is 1 less level in its subtree
                if (i > firstDigit) {
                    --digits;
                }
                int mode = (i == firstDigit) ? 0 : 1;
                if (subSize == subtreeSize(digits)) mode = 1;  // full subtree edge case
                kthNum = kthNumHelper(subSize, k, i, digits - 1, mode, nDigits);
                break;
            }
        }
        return kthNum;
    }

    // mode: 0 equal, aka not full subtree
    // mode: 1 more or less, aka full subtree
    int kthNumHelper(int n, int k, int root, int digitsLeft, int mode, const std::vector<int>& nDigits) {
        if (k == 1) return root;
        k -= 1;  // subtract root from the count
        n -= 1;  // also subtract root from the total elems in subtree
        int subSize = subtreeSize(digitsLeft);
        int kthNum = 0;
        if (mode == 0) {
            int currDigit = nDigits[digitsLeft - 1];
            // do the same thing as findKthNumber but start with 0
            for (int i = 0; i < 10; ++i) {
                if (i > currDigit) {
                    subSize = subtreeSize(digitsLeft - 1);
                } else if (i < currDigit) {
                    subSize = subtreeSize(digitsLeft);
                } else {
                    int prevSize = currDigit * subtreeSize(digitsLeft);
                    int nextSize = (9 - currDigit) * subtreeSize(digitsLeft - 1);
                    subSize = n - prevSize - nextSize;
                }
                if (k > subSize) {
                    k -= subSize;
                } else {
                    // if i is more, then there is 1 less level in its subtree
                    if (i > currDigit) {
                        --digitsLeft;
                    }
                    mode = (i == currDigit) ? 0 : 1;
                    if (subSize == subtreeSize(currDigit)) mode = 1;  // full subtree edge case
                    kthNum = kthNumHelper(subSize, k, root * 10 + i, digitsLeft - 1, mode, nDigits);
                    break;
                }
            }
        } else {  // mode == 1
            // just iterate through the full subtrees and subtract k
            for (int i = 0; i < 10; ++i) {
                if (k > subSize) {
                    k -= subSize;
                } else {
                    kthNum = kthNumHelper(n, k, root * 10 + i, digitsLeft - 1, mode, nDigits);
                    break;
                }
            }
        }
        return kthNum;
    }

    int subtreeSize(int levels) {
        if (levels == 0) return 0;
        int res = 1;
        for (int i = 1; i < levels; ++i) {
            res = res * 10 + 1;
        }
        return res;
    }
};
