/*
@file : 9.cpp
@author : Perry Huang
@brief : is the number a palindrome
*/

#include <iostream>

bool isPalindrome(int x) {
  if (x < 0) return false;
  std::size_t rvrs = 0, count = 0, orig = x;
  while (orig) {
    rvrs *= 10;
    rvrs += orig % 10;
    orig /= 10;
  }
  while (x) {
    if (!(rvrs % 10 == x % 10)) return false;
    rvrs /= 10;
    x /= 10;
  }
  return true;
}

int main(int argc, char* argv[]) { return 0; }