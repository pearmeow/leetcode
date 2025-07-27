/**
 * @file 3439-reschedule-meetings-for-maximum-free-time-i.cpp
 * @author Perry Huang
 * @date 2025-07-08
 * 3439. Reschedule Meetings for Maximum Free Time I
 * You are given an integer eventTime denoting the duration of an event, where the event occurs from time t = 0 to
 * time t = eventTime. You are also given two integer arrays startTime and endTime, each of length n. These
 * represent the start and end time of n non-overlapping meetings, where the ith meeting occurs during the time
 * [startTime[i], endTime[i]]. You can reschedule at most k meetings by moving their start time while maintaining
 * the same duration, to maximize the longest continuous period of free time during the event. The relative order
 * of all the meetings should stay the same and they should remain non-overlapping. Return the maximum amount of
 * free time possible after rearranging the meetings. Note that the meetings can not be rescheduled to a time
 * outside the event.
 */

#include <algorithm>
#include <vector>

class Solution {
public:
    int maxFreeTime(int eventTime, size_t k, std::vector<int>& startTime, std::vector<int>& endTime) {
        std::vector<std::pair<int, int>> events;
        // sentinel to represent the beginning of event
        events.emplace_back(0, 0);
        for (size_t i = 0; i < startTime.size(); ++i) {
            events.emplace_back(startTime[i], endTime[i]);
        }
        // sentinel to represent end of event
        events.emplace_back(eventTime, eventTime);
        // free time between 0 and first event
        int currMax = events[1].first;
        int res = currMax;
        size_t front = 1;
        size_t end = 1;
        while (end + 1 < events.size()) {
            if (end - front < k) {
                currMax += (events[end + 1].first - events[end].second);
                ++end;
                res = std::max(res, currMax);
            } else if (end - front == k) {
                currMax -= (events[front].first - events[front - 1].second);
                ++front;
                currMax += (events[end + 1].first - events[end].second);
                ++end;
                res = std::max(res, currMax);
            }
        }
        return res;
    }
};
