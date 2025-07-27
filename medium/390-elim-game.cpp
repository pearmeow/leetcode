/**
 * @file 390-elim-game.cpp
 * @author Perry Huang
 * @date 2024-10-14
 * 390. Elimination Game
 * You have a list arr of all integers in the range [1, n] sorted in a strictly increasing order.
 * Apply the following algorithm on arr:
 * Starting from left to right, remove the first number and every other number afterward until
 * you reach the end of the list.
 * Repeat the previous step again, but this time from right to left, remove the rightmost number
 * and every other number from the remaining numbers.
 * Keep repeating the steps again, alternating left to right and right to left, until a single number remains.
 * Given the integer n, return the last number that remains in arr.
 */

class Solution {
   public:
    bool RIGHT = true;
    bool LEFT = false;

    int lastRemaining(int n) {
        int remaining = n;
        int head = 1;
        int step = 1;
        bool direction = RIGHT;
        while (remaining > 1) {
            if (direction == RIGHT || (direction == LEFT && remaining % 2 == 1)) {
                head += step;
            }
            direction = !direction;
            remaining = remaining / 2;
            step *= 2;
        }
        return head;
    }
};
