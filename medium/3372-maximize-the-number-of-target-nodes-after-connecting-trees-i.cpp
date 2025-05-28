/**
 * @file 3372-maximize-the-number-of-target-nodes-after-connecting-trees-i.cpp
 * @author Perry Huang
 * @date 2025-05-27
 * 3372. Maximize the Number of Target Nodes After Connecting Trees I
 * There exist two undirected trees with n and m nodes, with distinct labels in ranges [0, n - 1] and [0, m - 1],
 * respectively.
 * You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively,
 * where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and
 * edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.
 * You are also given an integer k.
 * Node u is target to node v if the number of edges on the path from u to v is less than or equal to k.
 * Note that a node is always target to itself.
 * Return an array of n integers answer, where answer[i] is the maximum possible number of nodes target to node i of the
 * first tree if you have to connect one node from the first tree to another node in the second tree.
 * Note that queries are independent from each other. 
 * That is, for every query you will remove the added edge before proceeding to the next query.
 */

#include <vector>
#include <unordered_set>
#include <set>
#include <queue>

// returns nodes with distance less than or equal to k
int targetBFS(const std::vector<std::set<int>>& adjList, int k, int rootVertex) {
  std::unordered_set<int> visited;
  std::queue<int> visiting;
  visiting.push(rootVertex);
  visited.insert(rootVertex);
  int totalTargets = 0;
  int curr = 0;
  size_t qSize = 0;
  while (!visiting.empty() && k > -1) {
    qSize = visiting.size();
    for (size_t j = 0; j < qSize; ++j) {
      curr = visiting.front();
      for (int child : adjList[curr]) {
        if (visited.find(child) == visited.end()) {
          visiting.push(child);
          visited.insert(child);
        }
      }
      visiting.pop();
      ++totalTargets;
    }
    --k;
  }
  return std::max(1, totalTargets);
}

std::vector<int> maxTargetNodes(const std::vector<std::vector<int>>& edges1, const std::vector<std::vector<int>>& edges2, int k) {
  if (k == 0) return std::vector<int>(edges1.size() + 1, 1);
  std::vector<std::set<int>> adjList1(edges1.size() + 1);
  std::vector<std::set<int>> adjList2(edges2.size() + 1);
  for (size_t i = 0; i < edges1.size(); ++i) {
    adjList1[edges1[i][0]].insert(edges1[i][1]);
    adjList1[edges1[i][1]].insert(edges1[i][0]);
  }
  for (size_t i = 0; i < edges2.size(); ++i) {
    adjList2[edges2[i][0]].insert(edges2[i][1]);
    adjList2[edges2[i][1]].insert(edges2[i][0]);
  }
  int connectedTargets = 0;
  for (size_t i = 0; i < adjList2.size(); ++i) {
    connectedTargets = std::max(connectedTargets, targetBFS(adjList2, k - 1, i));
  }
  std::vector<int> maxTargets(adjList1.size(), connectedTargets);
  for (size_t i = 0; i < adjList1.size(); ++i) {
    maxTargets[i] += targetBFS(adjList1, k, i);
  }
  return maxTargets;
}
