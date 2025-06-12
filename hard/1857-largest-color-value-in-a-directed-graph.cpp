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
#include <queue>

const int COLORS = 26;

int largestPathValue(const std::string& colors, const std::vector<std::vector<int>>& edges) {
    std::vector<std::vector<int>> adjList(colors.size());
    std::vector<int> indegrees(colors.size());
    for (const std::vector<int>& edge : edges) {
        int parent = edge[0];
        int child = edge[1];
        adjList[parent].push_back(child);
        ++indegrees[child];
    }
    std::vector<std::vector<int>> colorMaxes(colors.size(), std::vector<int>(COLORS));
    std::queue<int> parents;
    for (size_t i = 0; i < indegrees.size(); ++i) {
        if (indegrees[i] == 0) {
            parents.push(i);
        }
    }
    int maxColor = 0;
    int totalParents = 0;
    while (!parents.empty()) {
        ++totalParents;
        int currPar = parents.front();
        parents.pop();
        colorMaxes[currPar][colors[currPar] - 'a'] += 1;
        maxColor = std::max(colorMaxes[currPar][colors[currPar] - 'a'], maxColor);
        for (int child : adjList[currPar]) {
            indegrees[child] -= 1;
            if (indegrees[child] == 0) {
                parents.push(child);
            }
            for (size_t i = 0; i < COLORS; ++i) {
                colorMaxes[child][i] = std::max(colorMaxes[currPar][i], colorMaxes[child][i]);
                maxColor = std::max(colorMaxes[child][i], maxColor);
            }
        }
    }
    if (totalParents != colors.size()) return -1;
    return maxColor;
}
