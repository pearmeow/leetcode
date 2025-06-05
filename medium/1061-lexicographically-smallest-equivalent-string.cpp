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
#include <unordered_map>

std::string smallestEquivalentString(const std::string& s1, const std::string& s2, const std::string& baseStr) {
  std::vector<char> minimChars;
  std::unordered_map<char, size_t> whichSet;
  size_t newSet = 0;
  size_t currSet = 0;
  for (size_t i = 0; i < s1.size(); ++i) {
    if (whichSet.find(s1[i]) == whichSet.end() && whichSet.find(s2[i]) == whichSet.end()) {
      newSet = minimChars.size();
      whichSet[s1[i]] = newSet;
      whichSet[s2[i]] = newSet;
      if (s1[i] > s2[i]) {
        minimChars.push_back(s2[i]);
      } else {
        minimChars.push_back(s1[i]);
      }
    } else if (whichSet.find(s1[i]) == whichSet.end()) {
      whichSet[s1[i]] = whichSet[s2[i]];
      if (s1[i] < minimChars[whichSet[s1[i]]]) {
        minimChars[whichSet[s1[i]]] = s1[i];
      }
    } else {
      whichSet[s2[i]] = whichSet[s1[i]];
      if (s2[i] < minimChars[whichSet[s2[i]]]) {
        minimChars[whichSet[s2[i]]] = s2[i];
      }
    }
  }
  std::string result = baseStr;
  for (size_t i = 0; i < baseStr.size(); ++i) {
    if (whichSet.find(baseStr[i]) != whichSet.end()) {
      result[i] = minimChars[whichSet[baseStr[i]]];
    }
  }
  return result;
}
