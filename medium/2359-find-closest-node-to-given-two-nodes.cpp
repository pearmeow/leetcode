/**
 * @file 2359-find-closest-node-to-given-two-nodes.cpp
 * @author Perry Huang
 * @date 2025-05-29
 * 2359. Find Closest Node to Given Two Nodes
 * You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing
 * edge. The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed
 * edge from node i to node edges[i]. If there is no outgoing edge from i, then edges[i] == -1. You are also given
 * two integers node1 and node2. Return the index of the node that can be reached from both node1 and node2, such
 * that the maximum between the distance from node1 to that node, and from node2 to that node is minimized. If
 * there are multiple answers, return the node with the smallest index, and if no possible answer exists, return
 * -1. Note that edges may contain cycles.
 */

#include <vector>

class Solution {
public:
    int closestMeetingNode(std::vector<int>& edges, int node1, int node2) {
        if (node1 == node2) return node1;
        std::vector<bool> firstPath(edges.size());
        std::vector<bool> secondPath(edges.size());
        firstPath[node1] = true;
        secondPath[node2] = true;
        int first = node1;
        int second = node2;
        while (edges[first] != -1 && firstPath[edges[first]] == false && edges[second] != -1 &&
               secondPath[edges[second]] == false) {
            first = edges[first];
            second = edges[second];
            firstPath[first] = true;
            secondPath[second] = true;
            if (firstPath[second] == true && secondPath[first] == true) return std::min(first, second);
            if (firstPath[second] == true) return second;
            if (secondPath[first] == true) return first;
        }
        while (edges[first] != -1 && firstPath[edges[first]] == false) {
            first = edges[first];
            firstPath[first] = true;
            if (secondPath[first] == true) return first;
        }
        while (edges[second] != -1 && secondPath[edges[second]] == false) {
            second = edges[second];
            secondPath[second] = true;
            if (firstPath[second] == true) return second;
        }
        return -1;
    }
};
