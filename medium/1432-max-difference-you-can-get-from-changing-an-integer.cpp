/**
 * @file 1432-max-difference-you-can-get-from-changing-an-integer.cpp
 * @author Perry Huang
 * @date 2025-06-15
 * 1432. Max Difference You Can Get From Changing an Integer
 * You are given an integer num. You will apply the following steps to num two separate times:
 * Pick a digit x (0 <= x <= 9).
 * Pick another digit y (0 <= y <= 9). Note y can be equal to x.
 * Replace all the occurrences of x in the decimal representation of num by y.
 * Let a and b be the two results from applying the operation to num independently.
 * Return the max difference between a and b.
 * Note that neither a nor b may have any leading zeros, and must not be 0.
 */

#include <vector>

int maxDiff(int num) {
    std::vector<int> minDigits;
    while (num > 0) {
        minDigits.push_back(num % 10);
        num /= 10;
    }
    std::vector<int> maxDigits(minDigits);
    int minNum = 0;
    int maxNum = 0;
    int change = -1;
    int swap = -1;
    int firstDigit = -1;
    for (auto it = minDigits.rbegin(); it != minDigits.rend(); ++it) {
        if (it == minDigits.rbegin()) {
            firstDigit = *it;
            if (*it != 1) {
                swap = *it;
                change = 1;
                *it = change;
            }
        } else if (change == -1 && *it != firstDigit && *it != 0) {
            swap = *it;
            change = 0;
            *it = change;
        } else if (*it == swap) {
            *it = change;
        }
        minNum = minNum * 10 + *it;
    }
    change = -1;
    swap = -1;
    for (auto it = maxDigits.rbegin(); it != maxDigits.rend(); ++it) {
        if (it == maxDigits.rbegin()) {
            if (*it != 9) {
                swap = *it;
                change = 9;
                *it = change;
            }
        } else if (change == -1 && *it != 9) {
            swap = *it;
            change = 9;
            *it = change;
        } else if (*it == swap) {
            *it = change;
        }
        maxNum = maxNum * 10 + *it;
    }
    return maxNum - minNum;
}
