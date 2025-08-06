/**
 * @file 3479-fruits-into-baskets-iii.cpp
 * @author Perry Huang
 * @date 2025-08-05
 * 3479. Fruits Into Baskets III
 * You are given two arrays of integers, fruits and baskets, each of length n, where fruits[i] represents the
 * quantity of the ith type of fruit, and baskets[j] represents the capacity of the jth basket. From left to right,
 * place the fruits according to these rules: Each fruit type must be placed in the leftmost available basket with
 * a capacity greater than or equal to the quantity of that fruit type. Each basket can hold only one type of
 * fruit. If a fruit type cannot be placed in any basket, it remains unplaced. Return the number of fruit types
 * that remain unplaced after all possible allocations are made.
 */

#include <vector>

class Segtree {
public:
    Segtree(const std::vector<int>& vec, int lbound, int rbound) {
        int mid = (rbound + lbound) / 2;
        if (lbound + 1 < rbound) {
            left = new Segtree(vec, lbound, mid);
            right = new Segtree(vec, mid, rbound);
            the_max = std::max(left->the_max, right->the_max);
        } else {
            the_max = vec[mid];
        }
    }
    bool place_fruits(int quantity) {
        if (the_max >= quantity) {
            if (lbound + 1 == rbound) {
                the_max = 0;
                return true;
            }
            int new_max = 0;
            if (left && left->the_max >= quantity) {
                left->place_fruits(quantity);
            } else if (right && right->the_max >= quantity) {
                right->place_fruits(quantity);
            }
            if (left) {
                new_max = left->the_max;
            }
            if (right) {
                new_max = std::max(new_max, right->the_max);
            }
            the_max = new_max;
            return true;
        }
        return false;
    }

private:
    int the_max = 0;
    int lbound = 0;
    int rbound = 0;
    Segtree* left = nullptr;
    Segtree* right = nullptr;
};

class Solution {
public:
    int numOfUnplacedFruits(std::vector<int>& fruits, std::vector<int>& baskets) {
        Segtree seg(baskets, 0, baskets.size());
        int res = 0;
        for (int i : fruits) {
            if (seg.place_fruits(i) == false) {
                ++res;
            }
        }
        return res;
    }
};
