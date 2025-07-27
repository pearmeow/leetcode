/**
 * @file 399-evaluate-division.cpp
 * @author Perry Huang
 * @date 2025-06-15
 * 399. Evaluate Division
 * You are given an array of variable pairs equations and an array of real
 * numbers values, where equations[i] = [Ai, Bi] and values[i] represent the
 * equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a
 * single variable. You are also given some queries, where queries[j] = [Cj, Dj]
 * represents the jth query where you must find the answer for Cj / Dj = ?.
 * Return the answers to all queries. If a single answer cannot be determined,
 * return -1.0. Note: The input is always valid. You may assume that evaluating
 * the queries will not result in division by zero and that there is no
 * contradiction. Note: The variables that do not occur in the list of equations
 * are undefined, so the answer cannot be determined for them.
 */

#include <map>
#include <queue>
#include <string>
#include <vector>

class Solution {
public:
    double findEqValue(const std::vector<std::vector<std::string>>& equations, const std::vector<double>& values,
                       const std::string& s1, const std::string& s2) {
        for (size_t i = 0; i < equations.size(); ++i) {
            const std::string& dividend = equations[i][0];
            const std::string& divisor = equations[i][1];
            if (dividend == s1 && divisor == s2) {
                return values[i];
            } else if (dividend == s2 && divisor == s1) {
                return 1.0 / values[i];
            }
        }
        return -1.0;
    }

    double solveQuery(const std::vector<std::vector<std::string>>& equations, const std::vector<double>& values,
                      const std::vector<std::string>& query,
                      const std::map<std::string, std::vector<const std::string*>>& adjList,
                      std::map<std::string, bool>& visited,
                      std::queue<std::tuple<const std::string*, const std::string*, double>>& theQueue) {
        if (adjList.find(query[0]) == adjList.end() || adjList.find(query[1]) == adjList.end()) {
            return -1.0;
        } else if (query[0] == query[1]) {
            return 1.0;
        }
        double res = -1.0;
        double initVal = 0.0;
        for (size_t i = 0; i < adjList.at(query[0]).size(); ++i) {
            const std::string* word = adjList.at(query[0])[i];
            initVal = findEqValue(equations, values, query[0], *word);
            theQueue.push(std::make_tuple(&query[0], word, initVal));
        }
        visited[query[0]] = true;
        while (!theQueue.empty()) {
            auto tup = theQueue.front();
            theQueue.pop();
            const std::string* nextStr = std::get<1>(tup);
            if (visited[*nextStr]) {
                continue;
            }
            visited[*nextStr] = true;
            if (*nextStr == query[1]) {
                res = std::get<2>(tup);
                break;
            }
            for (size_t i = 0; i < adjList.at(*nextStr).size(); ++i) {
                const std::string* child = adjList.at(*nextStr)[i];
                double multVal = std::get<2>(tup);
                multVal *= findEqValue(equations, values, *nextStr, *child);
                theQueue.push(std::make_tuple(nextStr, child, multVal));
            }
        }
        // clean up visited for usage in later solves
        for (auto& [key, val] : visited) {
            val = false;
        }
        // empty queue
        theQueue = {};
        return res;
    }

    std::vector<double> calcEquation(const std::vector<std::vector<std::string>>& equations,
                                     const std::vector<double>& values,
                                     const std::vector<std::vector<std::string>>& queries) {
        std::map<std::string, std::vector<const std::string*>> adjList;
        std::map<std::string, bool> visited;
        for (size_t i = 0; i < equations.size(); ++i) {
            const std::string& dividend = equations[i][0];
            const std::string& divisor = equations[i][1];
            adjList[dividend].push_back(&divisor);
            adjList[divisor].push_back(&dividend);
            visited[dividend] = false;
            visited[divisor] = false;
        }
        std::queue<std::tuple<const std::string*, const std::string*, double>> theQueue;
        std::vector<double> res(queries.size(), -1.0);
        for (size_t i = 0; i < res.size(); ++i) {
            res[i] = solveQuery(equations, values, queries[i], adjList, visited, theQueue);
        }
        return res;
    }
};
