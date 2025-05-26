/**
 * @file 1857-largest-color-value-in-a-directed-graph.cpp
 * @author Perry Huang
 * @date 2025-05-25
 * 1857. Largest Color Value in a Directed Graph
 * There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.
 * You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in 
 * this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a 
 * directed edge from node aj to node bj.
 * A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from x
 * i to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most 
 * frequently occurring color along that path.
 * Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.
 */

#include <string>
#include <vector>
#include <iostream>

const int COLORS = 26;

// recursively finds out if a cycle exists but also updates dp table
// will take in colors to track the colors
// will take in adjacency list to subtract indegrees
// will take in indegrees to track indegrees
// will take in dp table to update it
// returns -1 if a cycle is detected
// otherwise returns the largest color value
int modifiedKahnTopoSort(const std::string& colors, const std::vector<std::vector<int>>& adjList,
    std::vector<int>& indegrees, std::vector<std::vector<int>>& pathValues) {
  // std::cout << "This is a recursive call. There should only be as many of these as the longest path\n";
  // push back vertices with zero to vector
  std::vector<int> parents;
  bool cyclePossible = false;
  // std::cout << "Indegrees: ";
  for (size_t i = 0; i < indegrees.size(); ++i) {
    // std::cout << indegrees[i] << " ";
    if (indegrees[i] == 0) {
      parents.push_back(i);
    } else if (indegrees[i] > 0) {
      cyclePossible = true;
    }
  }
  // std::cout << std::endl;
  // if no vertices are less than 0 then we have a cycle, return -1
  if (parents.size() == 0 && cyclePossible) {
    // std::cout << "The parent size 0 and possibility of cycle are both true\n";
    return -1;
  } else if (parents.size() == 0) {
    return 0;
  }
  // iterate through vector and subtract indegrees of child vertices
  // no need to "dequeue" parents because the "queue" is a vector created freshly every recursive case
  for (size_t i = 0; i < parents.size(); ++i) {
    for (size_t child = 0; child < adjList[parents[i]].size(); ++child) {
      --indegrees[adjList[parents[i]][child]];
    }
    indegrees[parents[i]] = -1; // set to -1 to prevent readding to vector in future recursions
  }
  // recursively call yourself with the same arguments
  int maxColor = modifiedKahnTopoSort(colors, adjList, indegrees, pathValues);
  if (maxColor == -1) {
    // std::cout << "The recursive call has returned -1\n";
    return maxColor;
  }
  // iterate through vector of parents and update dp table with new color values
  // update by looping over adjacency list and looping through the vectors of the children,
  // updating each color with the max
  for (size_t i = 0; i < parents.size(); ++i) {
    for (size_t child = 0; child < adjList[parents[i]].size(); ++child) {
      for (size_t color = 0; color < COLORS; ++color) {
        int parentMax = pathValues[parents[i]][color];
        int childMax = pathValues[adjList[parents[i]][child]][color];
        pathValues[parents[i]][color] = std::max(parentMax, childMax);
      }
    }
    ++pathValues[parents[i]][colors[parents[i]] - 'a'];
  }
  for (size_t i = 0; i < parents.size(); ++i) {
    for (size_t color = 0; color < COLORS; ++color) {
      maxColor = std::max(pathValues[parents[i]][color], maxColor);
    }
  }
  return maxColor;
}

int largestPathValue(const std::string& colors, std::vector<std::vector<int>>& edges) {
  std::vector<std::vector<int>> adjList(colors.size());
  std::vector<int> indegrees(colors.size());
  for (size_t i = 0; i < edges.size(); ++i) {
    int parent = edges[i][0];
    int child = edges[i][1];
    adjList[parent].push_back(child);
    ++indegrees[child];
  }
  // std::cout << "Adjacency List:\n";
  for (size_t i = 0; i < adjList.size(); ++i) {
    // std::cout << i << " ";
    for (size_t j = 0; j < adjList[i].size(); ++j) {
      // std::cout << adjList[i][j] << " ";
    }
    // std::cout << "\n";
  }
  std::vector<std::vector<int>> pathValues(colors.size(), std::vector<int>(COLORS));
  return modifiedKahnTopoSort(colors, adjList, indegrees, pathValues);
}

// int main() {
//   const std::string colors = "abaca";
//   std::vector<std::vector<int>> edges ={{0, 1}, {0, 2}, {2,3}, {3,4}};
//   // std::cout << largestPathValue(colors, edges) << std::endl;
// }
