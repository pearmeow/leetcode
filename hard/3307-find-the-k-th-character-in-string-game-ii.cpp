/**
 * @file 3307-find-the-k-th-character-in-string-game-ii.cpp
 * @author Perry Huang
 * @date 2025-07-04
 * 3307. Find the K-th Character in String Game II
 * Alice and Bob are playing a game. Initially, Alice has a string word = "a".
 * You are given a positive integer k. You are also given an integer array operations, where operations[i]
 * represents the type of the ith operation. Now Bob will ask Alice to perform all operations in sequence: If
 * operations[i] == 0, append a copy of word to itself. If operations[i] == 1, generate a new string by changing
 * each character in word to its next character in the English alphabet, and append it to the original word. For
 * example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".
 * Return the value of the kth character in word after performing all the operations.
 * Note that the character 'z' can be changed to 'a' in the second type of operation.
 */

#include <cmath>
#include <vector>

class Solution {
public:
    char kthCharacter(long long k, std::vector<int>& operations) {
        if (k == 1) {
            return 'a';
        }
        long long power = std::log2(k);
        long long sub = std::pow(2, power);
        long long currOp = 0;
        if (sub == k) {
            k = k / 2;
            currOp = operations[power - 1];
        } else {
            k -= sub;
            currOp = operations[power];
        }
        char newChar = kthCharacter(k, operations);
        if (newChar == 'z' && currOp == 1) {
            return 'a';
        } else {
            return newChar + currOp;
        }
    }
};
