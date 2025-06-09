/**
 * @file 386-lexicographical-numbers.cpp
 * @author Perry Huang
 * @date 2025-06-07
 * 386. Lexicographical Numbers
 * Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.
 * You must write an algorithm that runs in O(n) time and uses O(1) extra space. 
 */

#include <vector>

std::vector<int> lexicalOrder(int n) {
    std::vector<int> res(n);
    int curr = 1;
    size_t ind = 0;
    for (int i = 0; i < n; ++i) {
        res[ind] = curr;
        ++ind;
        if (curr * 10 <= n) {
            curr *= 10;
        } else {
            while (curr % 10 == 9 || curr >= n) {
                curr /= 10;
            }
            curr += 1;
        }
    }
    return res;
}
