/**
 * @file 3373-maximize-the-number-of-target-nodes-after-connecting-trees-ii.cpp
 * @author Perry Huang
 * @date 2025-05-28
 * 3373. Maximize the Number of Target Nodes After Connecting Trees II
 * There exist two undirected trees with n and m nodes, labeled from [0, n - 1] and [0, m - 1], respectively.
 * You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively,
 * where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and
 * edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.
 * Node u is target to node v if the number of edges on the path from u to v is even.
 * Note that a node is always target to itself.
 * Return an array of n integers answer, where answer[i] is the maximum possible number of nodes that are target to node 
 * i of the first tree if you had to connect one node from the first tree to another node in the second tree.
 * Note that queries are independent from each other.
 * That is, for every query you will remove the added edge before proceeding to the next query.
 */

#include <vector>

bool EVEN = true;
bool ODD = false;

int targetDFS(const std::vector<std::vector<int>>& adjList, std::vector<bool>& visited,
  bool parity, int root) {
  int res = 0;
  if (parity == EVEN) ++res;
  visited[root] = true;
  for (size_t i = 0; i < adjList[root].size(); ++i) {
    res += targetDFS(adjList, visited, !parity, adjList[root][i]);
  }
  return res;
}

void updateDFS(const std::vector<std::vector<int>>& adjList, std::vector<bool>& updated, std::vector<int>& maxTargets,
  bool parity, int root, int targetVal) {
  if (parity == EVEN) {
    maxTargets[root] += targetVal;
  } else {
    maxTargets[root] += adjList.size() - targetVal;
  }
  for (size_t i = 0; i < adjList[root].size(); ++i) {
    updateDFS(adjList, updated, maxTargets, !parity, adjList[root][i], targetVal);
  }
}

std::vector<int> maxTargetNodes(const std::vector<std::vector<int>>& edges1,
  const std::vector<std::vector<int>>& edges2) {
  std::vector<std::vector<int>> adjList1(edges1.size() + 1);
  std::vector<std::vector<int>> adjList2(edges2.size() + 1);
  for (size_t i = 0; i < edges1.size(); ++i) {
    int vertex = edges1[i][0];
    int otherVertex = edges1[i][1];
    adjList1[vertex].push_back(otherVertex);
    adjList1[otherVertex].push_back(vertex);
  }
  for (size_t i = 0; i < edges2.size(); ++i) {
    int vertex = edges2[i][0];
    int otherVertex = edges2[i][1];
    adjList2[vertex].push_back(otherVertex);
    adjList2[otherVertex].push_back(vertex);
  }
  std::vector<bool> visited2(adjList2.size(), false);
  int otherMax = targetDFS(adjList2, visited2, EVEN, 0);
  otherMax = std::max(otherMax, ((int)adjList2.size() - otherMax));
  std::vector<bool> visited1(adjList1.size(), false);
  int targets = targetDFS(adjList1, visited1, EVEN, 0);
  std::vector<bool> updated(adjList1.size(), false);
  std::vector<int> maxTargets(adjList1.size(), otherMax);
  updateDFS(adjList1, updated, maxTargets, EVEN, 0, targets);
  return maxTargets;
}
