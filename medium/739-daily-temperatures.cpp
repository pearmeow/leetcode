/**
 * @file 739-daily-temperatures.cpp
 * @author Perry Huang
 * @date 2025-06-26
 * 739. Daily Temperatures
 * Given an array of integers temperatures represents the daily temperatures, return an array answer such that
 * answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no
 * future day for which this is possible, keep answer[i] == 0 instead.
 */

#include <stack>
#include <vector>

class Solution {
public:
    std::vector<int> dailyTemperatures(const std::vector<int>& temperatures) {
        std::vector<int> res(temperatures.size(), 0);
        std::stack<std::pair<int, size_t>> monDecStack;
        for (size_t i = 0; i < temperatures.size(); ++i) {
            if (monDecStack.empty()) {
                monDecStack.push(std::make_pair(temperatures[i], i));
            } else if (temperatures[i] > monDecStack.top().first) {
                while (!monDecStack.empty()) {
                    if (monDecStack.top().first < temperatures[i]) {
                        size_t day = monDecStack.top().second;
                        res[day] = i - day;
                        monDecStack.pop();
                    } else {
                        break;
                    }
                }
                monDecStack.push(std::make_pair(temperatures[i], i));
            } else {
                monDecStack.push(std::make_pair(temperatures[i], i));
            }
        }
        while (!monDecStack.empty()) {
            size_t ind = monDecStack.top().second;
            res[ind] = 0;
            monDecStack.pop();
        }
        return res;
    }
};
