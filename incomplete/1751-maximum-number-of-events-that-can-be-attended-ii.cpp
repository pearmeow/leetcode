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
#include <set>
#include <vector>

int maxValue(std::vector<std::vector<int>>& events, int k) {
    std::sort(events.begin(), events.end(),
              [](const std::vector<int>& a, const std::vector<int>& b) { return a[0] > b[0]; });
}
