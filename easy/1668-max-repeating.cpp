/**
 * @file 1668-max-repeating.cpp
 * @author Perry Huang
 * @date 2024-10-30
 */

#include <string>

int maxRepeating(std::string sequence, std::string word) {
  int count = 0, tempCount = 0, tempInd = 0;
  for (size_t i = 0; i < sequence.size(); ++i) {
    if (word[tempInd] == sequence[i]) {
      if (tempInd == word.size() - 1) {
        ++tempCount;
        tempInd = 0;
      } else {
        ++tempInd;
      }
    } else {
      count = std::max(tempCount, count);
      tempInd = 0;
      tempCount = 0;
    }
  }
  count = std::max(tempCount, count);
  return count;
}
