/*
 * @file 223.cpp
 * @name Perry Huang
 * @date 2024-10-11
 */

#include <unordered_set>
#include <iostream>

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
  std::unordered_set<int> xVals, yVals;
  int xOverlap = 0, yOverlap = 0, xCtr = 0, yCtr = 0;
  for (int i = ax1; i < ax2; ++i) {
    xVals.insert(i);
  }
  for (int i = ay1; i < ay2; ++i) {
    yVals.insert(i);
  }
  for (int i = bx1; i < bx2; ++i) {
    if (xVals.find(i) != xVals.end()) {
      ++xOverlap;
    }
  }
  for (int i = by1; i < by2; ++i) {
    if (yVals.find(i) != yVals.end()) {
      ++yOverlap;
    }
  }
  return (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1) - xOverlap * yOverlap;
}

int main() {
  computeArea(-3, 0, 3, 4, 0, -1, 9, 2);
}
