/**
 * @file 1298-maximum-candies-you-can-get-from-boxes
 * @author Perry Huang
 * @date 2025-06-02
 * 1298. Maximum Candies You Can Get from Boxes
 * You have n boxes labeled from 0 to n - 1. You are given four arrays: status, candies, keys, and containedBoxes where:
 * status[i] is 1 if the ith box is open and 0 if the ith box is closed,
 * candies[i] is the number of candies in the ith box,
 * keys[i] is a list of the labels of the boxes you can open after opening the ith box.
 * containedBoxes[i] is a list of the boxes you found inside the ith box.
 * You are given an integer array initialBoxes that contains the labels of the boxes you initially have
 * You can take all the candies in any open box and you can use the keys in it to open new boxes and you
 * also can use the boxes you find in it.
 * Return the maximum number of candies you can get following the rules above.
 */

#include <queue>
#include <vector>

int OPEN = 1;
int CLOSED = 0;

int maxCandies(std::vector<int>& status, std::vector<int>& candies, std::vector<std::vector<int>>& keys,
               std::vector<std::vector<int>>& containedBoxes, std::vector<int>& initialBoxes) {
    int totalCandies = 0;
    int opened = 1;
    int currBox = 0;
    size_t qSize = 0;
    std::vector<bool> ownedKeys(status.size());
    std::vector<bool> visited(status.size());
    std::queue<int> visiting;
    for (int box : initialBoxes) {
        visiting.push(box);
    }
    while (!visiting.empty() && opened > 0) {
        opened = 0;
        qSize = visiting.size();
        for (size_t i = 0; i < qSize; ++i) {
            currBox = visiting.front();
            visiting.pop();
            if (status[currBox] == CLOSED && ownedKeys[currBox] == false && !visited[currBox]) {
                visiting.push(currBox);
            } else if (!visited[currBox]) {
                visited[currBox] = true;
                ++opened;
                totalCandies += candies[currBox];
                for (int box : containedBoxes[currBox]) {
                    visiting.push(box);
                }
                for (int key : keys[currBox]) {
                    ownedKeys[key] = true;
                }
            }
        }
    }
    return totalCandies;
}
