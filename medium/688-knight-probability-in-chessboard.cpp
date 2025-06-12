/**
 * @file 688-knight-probability-in-chessboard.cpp
 * @author Perry Huang
 * @date 2024-10-12
 * 688. Knight Probability in Chessboard
 * On an n x n chessboard, a knight starts at the cell (row, column) and attempts
 * to make exactly k moves. The rows and columns are 0-indexed, so the top-left
 * cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).
 * A chess knight has eight possible moves it can make, as illustrated below.
 * Each move is two cells in a cardinal direction, then one cell in an orthogonal
 * direction.
 * Each time the knight is to move, it chooses one of eight possible moves
 * uniformly at random (even if the piece would go off the chessboard) and moves
 * there.
 * The knight continues moving until it has made exactly k moves or has moved off
 * the chessboard.
 * Return the probability that the knight remains on the board after it has stopped
 * moving.
 */

#include <vector>

const int X[8] = {2, 2, 1, 1, -1, -1, -2, -2};
const int Y[8] = {1, -1, 2, -2, 2, -2, 1, -1};

double helper(int boardLength, int moves, int r, int c,
        std::vector<std::vector<std::vector<double>>>& memo);

double knightProbability(int boardLength, int moves, int r, int c) {
    std::vector<std::vector<std::vector<double>>> memo(
            moves + 1, std::vector<std::vector<double>>(
                boardLength, std::vector<double>(boardLength, -1.0)));
    return helper(boardLength, moves, r, c, memo);
}

double helper(int boardLength, int moves, int r, int c,
        std::vector<std::vector<std::vector<double>>>& memo) {
    if (moves == 0) return 1.0;
    if (memo[moves][r][c] != -1) {
        return memo[moves][r][c];
    }
    double total = 0;
    for (int i = 0; i < 8; ++i) {
        int x = r + X[i];
        int y = c + Y[i];
        if (x >= 0 && x < boardLength && y >= 0 && y < boardLength) {
            total += helper(boardLength, moves - 1, x, y, memo);
        }
    }
    return memo[moves][r][c] = total / 8.0;
}
