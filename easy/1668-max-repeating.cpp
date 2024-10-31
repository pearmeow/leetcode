/**
 * @file 1668-max-repeating.cpp
 * @author Perry Huang
 * @date 2024-10-30
 */

#include <string>

int maxRepeating(std::string sequence, std::string word) {
  int count = 0, tempCount = 0;
  for (size_t i = 0; i < word.size(); ++i) {
    for (size_t j = i; j < sequence.size(); j += word.size()) {
      if (sequence.compare(j, word.size(), word, 0, word.size()) == 0) {
        tempCount += 1;
      } else {
        count = std::max(tempCount, count);
        tempCount = 0;
      }
    }
    count = std::max(tempCount, count);
    tempCount = 0;
  }
  return count;
}
