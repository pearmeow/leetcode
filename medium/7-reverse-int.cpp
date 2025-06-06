/**
 * @file 7-reverse-int.cpp
 * @author Perry Huang
 * @date 2024-10-12
 * 7. Reverse Integer
 * Given a signed 32-bit integer x, return x with its digits reversed. If reversing
 * x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 -
 * 1], then return 0.
 * Assume the environment does not allow you to store 64-bit integers (signed or
 * unsigned).
 */
#include <iostream>
#include <vector>

int reverse(int x) {
    unsigned int rvrs = 0, orig = 0, count = 0, negative = 1;
    int maximum[] = {2, 1, 4, 7, 4, 8, 3, 6, 4, 8};
    int curr[10];
    if (x < 0) {
        maximum[9] = 7;
        negative = -1;
        orig = x * negative;
    } else {
        orig = x;
    }

    while (orig) {
        rvrs *= 10;
        rvrs += orig % 10;
        curr[count] = orig % 10;
        orig /= 10;
        count += 1;
    }
    if (count < 10) {
        return rvrs * negative;
    }
    for (int i = 0; i < 10; ++i) {
        if (curr[i] > maximum[i]) {
            return 0;
        } else if (curr[i] < maximum[i]) {
            return rvrs * negative;
        }
    }
    return rvrs * negative;
}
