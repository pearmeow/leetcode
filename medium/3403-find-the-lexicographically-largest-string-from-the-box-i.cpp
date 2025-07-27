/**
 * @file 3403-find-the-lexicographically-largest-string-from-the-box-i.cpp
 * @author Perry Huang
 * @date 2025-06-04
 * 3403. Find the Lexicographically Largest String From the Box I
 * You are given a string word, and an integer numFriends.
 * Alice is organizing a game for her numFriends friends. There are multiple rounds in the game, where in each
 * round: word is split into numFriends non-empty strings, such that no previous round has had the exact same
 * split. All the split words are put into a box. Find the lexicographically largest string from the box after all
 * the rounds are finished.
 */

#include <string>
#include <vector>

class Solution {
   public:
    std::string largest(const std::string& word, int numFriends, size_t startIndex) {
        size_t remainingWord = word.size() - startIndex;
        size_t remainingFriends = numFriends - startIndex - 1;
        return word.substr(startIndex, remainingWord - remainingFriends);
    }

    bool lexComp(const std::string& word1, const std::string& word2) {
        size_t maxSize = std::max(word1.size(), word2.size());
        for (size_t i = 0; i < maxSize; ++i) {
            if (word1[i] != word2[i]) return word1[i] > word2[i];
        }
        return word1.size() > word2.size();
    }

    std::string answerString(const std::string& word, int numFriends) {
        if (numFriends == 1) return word;
        size_t maxInd = 0;
        std::vector<std::string> perms(word.size());
        for (size_t i = 0; i < perms.size(); ++i) {
            perms[i] = largest(word, numFriends, i);
        }
        for (size_t i = 1; i < perms.size(); ++i) {
            if (lexComp(perms[maxInd], perms[i]) == false) {
                maxInd = i;
            }
        }
        return perms[maxInd];
    }
};
