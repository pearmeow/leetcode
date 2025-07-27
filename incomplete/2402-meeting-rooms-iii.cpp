/**
 * @file 2402-meeting-rooms-iii.cpp
 * @author Perry Huang
 * @date 2025-07-10
 * 2402. Meeting Rooms III
 * You are given an integer n. There are n rooms numbered from 0 to n - 1.
 * You are given a 2D integer array meetings where meetings[i] = [starti, endi] means that a meeting will be held
 * during the half-closed time interval [starti, endi). All the values of starti are unique. Meetings are allocated
 * to rooms in the following manner: Each meeting will take place in the unused room with the lowest number. If
 * there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should
 * have the same duration as the original meeting. When a room becomes unused, meetings that have an earlier
 * original start time should be given the room. Return the number of the room that held the most meetings. If
 * there are multiple rooms, return the room with the lowest number. A half-closed interval [a, b) is the interval
 * between a and b including a and not including b.
 */

#include <algorithm>
#include <queue>
#include <set>
#include <vector>

class Solution {
   public:
    long long mostBooked(long long n, std::vector<std::vector<int>>& meetings) {
        std::priority_queue<long long, std::vector<long long>, std::greater<long long>> freeRooms;
        std::vector<long long> bookCount(n, 0);
        for (long long i = 0; i < n; ++i) {
            freeRooms.push(i);
        }
        std::sort(meetings.begin(), meetings.end(), [](const auto& a, const auto& b) { return a[0] < b[0]; });
        auto comp = [](const std::pair<long long, long long>& a, const std::pair<long long, long long>& b) {
            return a.first > b.first;
        };
        std::priority_queue<std::pair<long long, long long>, std::vector<std::pair<long long, long long>>,
                            decltype(comp)>
            endTimes(comp);
        for (const std::vector<int>& meet : meetings) {
            long long delay = 0;
            long long start = meet[0];
            // pop meetings based on start time
            while (!endTimes.empty() && endTimes.top().first <= start) {
                freeRooms.push(endTimes.top().second);
                endTimes.pop();
            }
            // if no rooms are free, then increment delay based on next meeting's end
            if (freeRooms.empty()) {
                delay = endTimes.top().first - start;
                start += delay;
            }
            while (!endTimes.empty() && endTimes.top().first <= start) {
                freeRooms.push(endTimes.top().second);
                endTimes.pop();
            }
            long long end = meet[1] + delay;
            long long meetRoom = freeRooms.top();
            freeRooms.pop();
            endTimes.push({end, meetRoom});
            ++bookCount[meetRoom];
        }
        long long res = 0;
        long long currMax = 0;
        for (size_t i = 0; i < bookCount.size(); ++i) {
            if (bookCount[i] > currMax) {
                currMax = bookCount[i];
                res = i;
            }
        }
        return res;
    }

    int main() {
        std::vector<std::vector<int>> meetings = {{39, 49}, {28, 39}, {9, 29},  {10, 36}, {22, 47},
                                                  {2, 3},   {4, 49},  {46, 50}, {45, 50}, {17, 33}};
        mostBooked(3, meetings);
    }
};
