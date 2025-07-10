/**
 * @file 853-car-fleet.cpp
 * @author Perry Huang
 * @date 2025-07-10
 * 853. Car Fleet
 * There are n cars at given miles away from the starting mile 0, traveling to reach the mile target.
 * You are given two integer array position and speed, both of length n, where position[i] is the starting mile of the
 * ith car and speed[i] is the speed of the ith car in miles per hour. A car cannot pass another car, but it can catch
 * up and then travel next to it at the speed of the slower car. A car fleet is a car or cars driving next to each
 * other. The speed of the car fleet is the minimum speed of any car in the fleet. If a car catches up to a car fleet at
 * the mile target, it will still be considered as part of the car fleet. Return the number of car fleets that will
 * arrive at the destination.
 */

#include <algorithm>
#include <vector>
#include <stack>

int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
    std::stack<double> monInc;
    std::vector<std::pair<int, int>> sortedCars;
    for (size_t i = 0; i < position.size(); ++i) {
        sortedCars.emplace_back(position[i], speed[i]);
    }
    std::sort(sortedCars.begin(), sortedCars.end(), std::greater<std::pair<int, int>>());
    for (size_t i = 0; i < sortedCars.size(); ++i) {
        double remDist = target - sortedCars[i].second;
        double eta = (remDist / (double)sortedCars[i].second);
        while (!monInc.empty() && eta <= monInc.top()) {
            monInc.pop();
        }
        monInc.push(eta);
    }
    int res = monInc.size();
    return res;
}
