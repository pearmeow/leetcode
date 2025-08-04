/**
 * @file 904-fruit-into-baskets.cpp
 * @author Perry Huang
 * @date 2025-08-03
 * 904. Fruit Into Baskets
 * You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are
 * represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces. You want to
 * collect as much fruit as possible. However, the owner has some strict rules that you must follow: You only have
 * two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each
 * basket can hold. Starting from any tree of your choice, you must pick exactly one fruit from every tree
 * (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets. Once
 * you reach a tree with fruit that cannot fit in your baskets, you must stop. Given the integer array fruits,
 * return the maximum number of fruits you can pick.
 */

#include <vector>

class Solution {
public:
    int totalFruit(const std::vector<int>& fruits) {
        std::vector<int> curr_types(2, -1);
        int max_fruits = 0;
        int curr_fruits = 0;
        int curr_chain = 0;
        int curr_type = -1;
        for (int type : fruits) {
            if (curr_types[0] == -1) {
                ++curr_fruits;
                ++curr_chain;
                curr_type = type;
                curr_types[0] = type;
                continue;
            } else if (curr_types[1] == -1 && type != curr_types[0]) {
                ++curr_fruits;
                curr_chain = 1;
                curr_type = type;
                curr_types[1] = type;
                continue;
            }
            if (type != curr_types[0] && type != curr_types[1]) {
                max_fruits = std::max(max_fruits, curr_fruits);
                curr_types[0] = curr_type;
                curr_types[1] = type;
                curr_type = type;
                curr_fruits = curr_chain;
                curr_chain = 1;
                ++curr_fruits;
            } else {
                ++curr_fruits;
                if (type != curr_type) {
                    curr_chain = 1;
                    curr_type = type;
                } else {
                    ++curr_chain;
                }
            }
        }
        max_fruits = std::max(max_fruits, curr_fruits);
        return max_fruits;
    }
};
