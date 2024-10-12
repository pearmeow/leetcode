/**
 * @file 3304-kth-char-string-game.cpp
 * @author Perry Huang
 * @date 2024-10-12
 */

#include <string>

char kthCharacter(int k) {
  std::string start = "a";
  std::string add = "";
  while (start.size() < k) {
    add = "";
    for (std::size_t i = 0; i < start.size(); ++i) {
      add += start[i] == 'z' ? 'a' : start[i] + 1;
    }
    start.append(add);
  }
  return start[k-1];
}
