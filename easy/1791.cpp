/**
 * @file 1791.cpp
 * @name Perry Huang
 * @date 4/11/2024
 */

#include <vector>

int findCenter(std::vector<std::vector<int>>& edges) {
  if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) { 
    return edges[0][0];
  } else {
    return edges[0][1];
  }
}
