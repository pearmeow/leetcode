/**
 * @file 3440-reschedule-meetings-for-maximum-free-time-ii.cpp
 * @author Perry Huang
 * @date 2025-07-10
 * 3440. Reschedule Meetings for Maximum Free Time II
 * You are given an integer eventTime denoting the duration of an event. You are also given two integer arrays
 * startTime and endTime, each of length n. These represent the start and end times of n non-overlapping meetings
 * that occur during the event between time t = 0 and time t = eventTime, where the ith meeting occurs during the
 * time [startTime[i], endTime[i]]. You can reschedule at most one meeting by moving its start time while
 * maintaining the same duration, such that the meetings remain non-overlapping, to maximize the longest continuous
 * period of free time during the event. Return the maximum amount of free time possible after rearranging the
 * meetings. Note that the meetings can not be rescheduled to a time outside the event and they should remain
 * non-overlapping. Note: In this version, it is valid for the relative ordering of the meetings to change after
 * rescheduling one meeting.
 */

#include <map>
#include <vector>

class Solution {
public:
    int maxFreeTime(int eventTime, std::vector<int>& startTime, std::vector<int>& endTime) {
        std::map<int, int> distances;
        int prevEnd = 0;
        for (size_t i = 0; i < startTime.size(); ++i) {
            ++distances[startTime[i] - prevEnd];
            prevEnd = endTime[i];
        }
        ++distances[eventTime - endTime[endTime.size() - 1]];
        int res = 0;
        int currMax = 0;
        for (size_t i = 0; i < startTime.size(); ++i) {
            int leftSpace = 0;
            if (i != 0) {
                leftSpace = startTime[i] - endTime[i - 1];
            } else {
                leftSpace = startTime[i];
            }
            int rightSpace = 0;
            if (i != startTime.size() - 1) {
                rightSpace = startTime[i + 1] - endTime[i];
            } else {
                rightSpace = eventTime - endTime[i];
            }
            --distances[leftSpace];
            --distances[rightSpace];
            bool hasSpace = false;
            // minus one because upper bound finds the first space greater than needed
            int neededSpace = endTime[i] - startTime[i] - 1;
            while (!hasSpace && distances.upper_bound(neededSpace) != distances.end()) {
                auto it = distances.upper_bound(neededSpace);
                if (it->second == 0) {
                    neededSpace = it->first;
                } else {
                    hasSpace = true;
                }
            }
            currMax = leftSpace + rightSpace;
            if (hasSpace) {
                currMax += endTime[i] - startTime[i];
            }
            res = std::max(res, currMax);
            ++distances[leftSpace];
            ++distances[rightSpace];
        }
        return res;
    }
};
