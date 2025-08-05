/**
 * @file 3477-fruits-into-baskets-ii.cpp
 * @author Perry Huang
 * @date 2025-08-04
 * 3477. Fruits Into Baskets II
 * You are given two arrays of integers, fruits and baskets, each of length n, where fruits[i] represents the
 * quantity of the ith type of fruit, and baskets[j] represents the capacity of the jth basket. From left to right,
 * place the fruits according to these rules: Each fruit type must be placed in the leftmost available basket with
 * a capacity greater than or equal to the quantity of that fruit type. Each basket can hold only one type of
 * fruit. If a fruit type cannot be placed in any basket, it remains unplaced. Return the number of fruit types
 * that remain unplaced after all possible allocations are made.
 */

#include <vector>

class Solution {
public:
    int numOfUnplacedFruits(std::vector<int>& fruits, std::vector<int>& baskets) {
        int res = 0;
        for (int quantity : fruits) {
            bool can_place = false;
            for (int& capacity : baskets) {
                if (capacity >= quantity) {
                    capacity = 0;
                    can_place = true;
                    break;
                }
            }
            if (!can_place) {
                ++res;
            }
        }
        return res;
    }
};
