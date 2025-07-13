/**
 * @file 2410-maximum-matching-of-players-with-trainers.cpp
 * @author Perry Huang
 * @date 2025-07-13
 * 2410. Maximum Matching of Players With Trainers
 * You are given a 0-indexed integer array players, where players[i] represents the ability of the ith player. You are
 * also given a 0-indexed integer array trainers, where trainers[j] represents the training capacity of the jth trainer.
 * The ith player can match with the jth trainer if the player's ability is less than or equal to the trainer's training
 * capacity. Additionally, the ith player can be matched with at most one trainer, and the jth trainer can be matched
 * with at most one player. Return the maximum number of matchings between players and trainers that satisfy these
 * conditions.
 */

#include <algorithm>
#include <vector>

int matchPlayersAndTrainers(std::vector<int>& players, std::vector<int>& trainers) {
    std::sort(players.begin(), players.end());
    std::sort(trainers.begin(), trainers.end());
    size_t thePlayer = 0;
    int res = 0;
    for (size_t i = 0; i < trainers.size() && thePlayer < players.size(); ++i) {
        if (trainers[i] >= players[thePlayer]) {
            ++thePlayer;
            ++res;
        }
    }
    return res;
}
