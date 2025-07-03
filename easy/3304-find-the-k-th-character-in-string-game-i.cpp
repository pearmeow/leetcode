/**
 * @file 3304-find-the-k-th-character-in-string-game-i.cpp
 * @author Perry Huang
 * @date 2025-07-02
 * 3304. Find the K-th Character in String Game I
 * Alice and Bob are playing a game. Initially, Alice has a string word = "a".
 * You are given a positive integer k.
 * Now Bob will ask Alice to perform the following operation forever:
 * Generate a new string by changing each character in word to its next character in the English alphabet, and append it
 * to the original word. For example, performing the operation on "c" generates "cd" and performing the operation on
 * "zb" generates "zbac". Return the value of the kth character in word, after enough operations have been done for word
 * to have at least k characters. Note that the character 'z' can be changed to 'a' in the operation.
 */

#include <cmath>

// Doesn't account for z case
char kthCharacter(int k) {
    if (k == 1) {
        return 'a';
    } else {
        int power = std::log2(k);
        int sub = std::pow(2, power);
        if (sub == k) {
            return kthCharacter(k / 2) + 1;
        } else {
            return kthCharacter(k - sub) + 1;
        }
    }
}
