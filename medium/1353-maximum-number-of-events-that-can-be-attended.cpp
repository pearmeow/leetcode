/**
 * @file 1353-maximum-number-of-events-that-can-be-attended.cpp
 * @author Perry Huang
 * @date 2025-07-06
 * 1353. Maximum Number of Events That Can Be Attended
 * You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends
 * at endDayi. You can attend an event i at any day d where startTimei <= d <= endTimei. You can only attend one event
 * at any time d. Return the maximum number of events you can attend.
 */

#include <algorithm>
#include <queue>
#include <vector>

int maxEvents(std::vector<std::vector<int>>& events) {
    auto comp = [](const std::vector<int>& a, const std::vector<int>& b) { return a[0] < b[0]; };
    std::sort(events.begin(), events.end(), comp);
    std::priority_queue<int, std::vector<int>, std::greater<int>> deadlines;
    int currDay = 0;
    int nextDay = 0;
    int res = 0;
    for (size_t i = 0; i < events.size(); ++i) {
        currDay = events[i][0];
        nextDay = currDay;
        deadlines.push(events[i][1]);
        for (size_t j = i + 1; j < events.size(); ++j) {
            if (events[j][0] == currDay) {
                deadlines.push(events[j][1]);
            } else {
                nextDay = events[j][0];
                i = j - 1;
                break;
            }
        }
        if (currDay == nextDay) { // account for last event
            nextDay = 0;
            i = events.size();
        }
        while (currDay != nextDay && !deadlines.empty()) {
            deadlines.pop();
            ++res;
            if (!deadlines.empty()) {
                while (deadlines.top() <= currDay) {
                    deadlines.pop();
                    if (deadlines.empty()) {
                        break;
                    }
                }
            }
            ++currDay;
        }
    }
    return res;
}
