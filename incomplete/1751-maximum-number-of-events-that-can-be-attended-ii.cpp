/**
 * @file 1751-maximum-number-of-events-that-can-be-attended-ii.cpp
 * @author Perry Huang
 * @date 2025-07-07
 * 1751. Maximum Number of Events That Can Be Attended II
 * You are given an array of events where events[i] = [startDayi, endDayi, valuei]. The ith event starts at startDayi
 * and ends at endDayi, and if you attend this event, you will receive a value of valuei. You are also given an integer
 * k which represents the maximum number of events you can attend. You can only attend one event at a time. If you
 * choose to attend an event, you must attend the entire event. Note that the end day is inclusive: that is, you cannot
 * attend two events where one of them starts and the other ends on the same day. Return the maximum sum of values that
 * you can receive by attending events.
 */

#include <algorithm>
#include <vector>

int maxValue(std::vector<std::vector<int>>& events, int k) {
    std::sort(events.begin(), events.end(),
              [](const std::vector<int>& a, const std::vector<int>& b) { return a[0] < b[0]; });
    std::vector<int> uniqueStarts;
    uniqueStarts.push_back(events[0][0]);
    for (size_t i = 1; i < events.size(); ++i) {
        if (events[i][0] != uniqueStarts[uniqueStarts.size() - 1]) {
            uniqueStarts.push_back(events[i][0]);
        }
    }
    std::vector<std::vector<int>> dp(uniqueStarts.size(), std::vector<int>(k, 0));
    size_t lastDay = uniqueStarts.size() - 1;
    int maxVal = 0;
    int endDay = 0;
    for (size_t offset = 1; offset <= events.size(); ++offset) {
        std::vector<int>& currEvent = events[events.size() - offset];
        if (currEvent[0] != uniqueStarts[lastDay]) {
            --lastDay;
        }
        endDay = currEvent[1];
        for (size_t j = 0; j < k; ++j) {
            dp[lastDay][j] = std::max(dp[lastDay][j], currEvent[2]);
        }
        auto nextEvent = std::upper_bound(uniqueStarts.begin(), uniqueStarts.end() - 1, endDay);
        if (uniqueStarts[nextEvent - uniqueStarts.begin()] > endDay) {
            for (size_t j = 1; j < k; ++j) {
                dp[lastDay][j] = std::max(dp[lastDay][j], currEvent[2] + dp[nextEvent - uniqueStarts.begin()][j - 1]);
            }
        }
        if (lastDay + 1 != uniqueStarts.size()) {
            for (size_t j = 0; j < k; ++j) {
                dp[lastDay][j] = std::max(dp[lastDay][j], dp[lastDay + 1][j]);
            }
        }
    }
    for (const std::vector<int>& vec : dp) {
        for (int i : vec) {
            maxVal = std::max(maxVal, i);
        }
    }
    return maxVal;
}
