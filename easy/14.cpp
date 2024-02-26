/*
@file: 4.cpp
@author: Perry Huang
@date: 2/25/2024


*/

#include <iostream>
#include <vector>

std::string longestCommonPrefix(std::vector<std::string>& strs) {
  std::string lcp;
  char curr = ' ';
  size_t min_size = strs[0].size();
  for (size_t i = 0; i < strs.size(); ++i) {
    min_size = std::min(strs[i].size(), min_size);
    std::cout << "pos" << i << " " << min_size << "\n";
  }
  for (size_t i = 0; i < min_size; ++i) { 
    for (size_t j = 0; j < strs.size(); ++j) {
      if (curr == ' ') curr = strs[j][i];
      else if (curr != strs[j][i]) return lcp;
    }
    lcp += curr;
    curr = ' ';
  }
  return lcp;
}

int main() {
  std::vector<std::string> vec = {"flowwww", "flowwww", "flowwww", "flowwww"};
  std::cout << longestCommonPrefix(vec);
}