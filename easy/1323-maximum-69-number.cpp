/**
 * @file 1323-maximum-69-number.cpp
 * @author Perry Huang
 * @date 2025-08-15
 * 1323. Maximum 69 Number
 * You are given a positive integer num consisting only of digits 6 and 9.
 * Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).
 */

class Solution {
public:
    int maximum69Number(int num) {
        int multiple = 1;
        int victim = num;
        int add = 0;
        while (victim != 0) {
            if (victim % 10 == 6) {
                add = 3 * multiple;
            }
            victim /= 10;
            multiple *= 10;
        }
        return num + add;
    }
};
