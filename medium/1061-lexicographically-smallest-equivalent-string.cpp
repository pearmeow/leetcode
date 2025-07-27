/**
 * @file 1061-lexicographically-smallest-equivalent-string.cpp
 * @author Perry Huang
 * @date 2025-06-05
 * 1061. Lexicographically Smallest Equivalent String
 * You are given two strings of the same length s1 and s2 and a string baseStr.
 * We say s1[i] and s2[i] are equivalent characters.
 * For example, if s1 = "abc" and s2 = "cde", then we have 'a' == 'c', 'b' == 'd', and 'c' == 'e'.
 * Equivalent characters follow the usual rules of any equivalence relation:
 * Reflexivity: 'a' == 'a'.
 * Symmetry: 'a' == 'b' implies 'b' == 'a'.
 * Transitivity: 'a' == 'b' and 'b' == 'c' implies 'a' == 'c'.
 * For example, given the equivalency information from s1 = "abc" and s2 = "cde", "acd" and "aab"
 * are equivalent strings of baseStr = "eed", and "aab" is the lexicographically smallest equivalent
 * string of baseStr.
 * Return the lexicographically smallest equivalent string of baseStr by using the equivalency
 * information from s1 and s2.
 */

#include <string>
#include <vector>

class Solution {
   public:
    void unionize(std::vector<std::vector<int>>& adjList, char merger, char mergee) {
        char curr = ' ';
        for (size_t i = 0; i < adjList[mergee - 'a'].size(); ++i) {
            curr = adjList[mergee - 'a'][i];
            adjList[curr][0] = merger - 'a';
            adjList[merger - 'a'].push_back(curr);
        }
        adjList[mergee - 'a'].clear();
        adjList[mergee - 'a'].push_back(merger - 'a');
        adjList[merger - 'a'].push_back(mergee - 'a');
    }

    std::string smallestEquivalentString(const std::string& s1, const std::string& s2,
                                         const std::string& baseStr) {
        std::vector<std::vector<int>> adjList(26);
        for (size_t i = 0; i < s1.size(); ++i) {
            bool s1IsParent = adjList[s1[i] - 'a'].size() > 1;
            bool s2IsParent = adjList[s2[i] - 'a'].size() > 1;
            char s1Parent = s1[i];
            char s2Parent = s2[i];
            if (!s1IsParent && adjList[s1[i] - 'a'].size() != 0) {
                if (adjList[s1[i] - 'a'][0] < s1[i] - 'a') {
                    s1Parent = adjList[s1[i] - 'a'][0] + 'a';
                }
            }
            if (!s2IsParent && adjList[s2[i] - 'a'].size() != 0) {
                if (adjList[s2[i] - 'a'][0] < s2[i] - 'a') {
                    s2Parent = adjList[s2[i] - 'a'][0] + 'a';
                }
            }
            if (s1Parent < s2Parent) {
                unionize(adjList, s1Parent, s2Parent);
            } else if (s1Parent > s2Parent) {
                unionize(adjList, s2Parent, s1Parent);
            }
        }
        std::string smallest = baseStr;
        for (size_t i = 0; i < baseStr.size(); ++i) {
            if (adjList[baseStr[i] - 'a'].size() == 1) {
                if (adjList[baseStr[i] - 'a'][0] < baseStr[i] - 'a') {
                    smallest[i] = adjList[baseStr[i] - 'a'][0] + 'a';
                }
            }
        }
        return smallest;
    }
};
