/**
 * @file 909-snakes-and-ladders.cpp
 * @author Perry Huang
 * @date 20025-05-30
 * 909. Snakes and Ladders
 * You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style
 * starting from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.
 * You start on square 1 of the board. In each move, starting from square curr, do the following:
 * Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
 * This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations,
 * regardless of the size of the board.
 * If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
 * The game ends when you reach the square n2.
 * A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or
 * ladder is board[r][c]. Squares 1 and n2 are not the starting points of any snake or ladder.
 * Note that you only take a snake or ladder at most once per dice roll. If the destination to a snake or ladder is the
 * start of another snake or ladder, you do not follow the subsequent snake or ladder.
 * For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2.
 * You follow the ladder to square 3, but do not follow the subsequent ladder to 4.
 * Return the least number of dice rolls required to reach the square n2.
 * If it is not possible to reach the square, return -1.
 */

#include <vector>
#include <queue>

size_t calcPos(size_t rowSize, size_t index) {
    bool onReverseRow = (index / rowSize) % 2 != 0;
    if (onReverseRow) {
        return rowSize - (index % rowSize) - 1;
    }
    return index % rowSize;
}

int snakesAndLadders(std::vector<std::vector<int>>& board) {
    std::vector<bool> visited(board.size() * board.size(), false);
    std::vector<std::vector<int>> reverseBoard(board.rbegin(), board.rend());
    std::queue<int> visiting;
    visiting.push(0);
    visited[0] = true;
    int moves = 0;
    int curr = 0;
    size_t qSize = 0;
    while (!visiting.empty()) {
        qSize = visiting.size();
        for (size_t i = 0; i < qSize; ++i) {
            curr = visiting.front();
            visiting.pop();
            for (size_t d6 = 1; d6 <= 6; ++d6) {
                if (curr + d6 > visited.size() - 1) continue;
                size_t row = (curr + d6) / board.size();
                size_t pos = calcPos(board.size(), curr + d6);
                if (reverseBoard[row][pos] != -1 && !visited[reverseBoard[row][pos] - 1]) {
                    visited[reverseBoard[row][pos] - 1] = true;
                    visiting.push(reverseBoard[row][pos] - 1);
                } else if (reverseBoard[row][pos] == -1 && !visited[curr + d6]) {
                    visited[curr + d6] = true;
                    visiting.push(curr + d6);
                }
            }
        }
        ++moves;
        if (visited[visited.size() - 1]) return moves;
    }
    return -1;
}
