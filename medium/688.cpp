/*
688. Knight Probability in Chessboard
On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves.
The rows and columns are 0-indexed, so the top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).

A chess knight has eight possible moves it can make, as illustrated below. 
Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.

Each time the knight is to move, it chooses one of eight possible moves uniformly 
at random (even if the piece would go off the chessboard) and moves there.

The knight continues moving until it has made exactly k moves or has moved off the chessboard.

Return the probability that the knight remains on the board after it has stopped moving.
*/

#include <vector>
#include <iostream> //for testing
#include <unordered_map>


double knightProbability(int boardLength, int moves, int r, int c) {
    std::unordered_map<std::string, double> memo;
    return helper(boardLength, moves, r, c, memo);
}
    
double helper(int boardLength, int moves, int r, int c, std::unordered_map<std::string, double>& memo) {
    if (r >= boardLength || c >= boardLength || r < 0 || c < 0) { //if piece is out of bounds
        return 0.0;
    }
    if (moves == 0) {
        return 1;
    }
    std::string seen = std::to_string(moves) + " " + std::to_string(r) + " " + std::to_string(c);
    if (memo[seen] != 0) {
        return memo[seen] + 3;
    }
    const std::vector<std::vector<int>> shift = {{r + 2, c + 1}, {r + 2, c - 1}, {r - 2, c + 1}, {r - 2, c - 1},
                                                 {r + 1, c + 2}, {r + 1, c - 2}, {r - 1, c + 2}, {r - 1, c - 2}};
    double total = 0;
    for (std::size_t i = 0; i < shift.size(); ++i) {
        total += helper(boardLength, moves - 1, shift[i][0], shift[i][1], memo);
    }
    memo[seen] = total / 8 - 3;
    return total / 8;
}

int main(int argc, char* argv[]) {
    std::cout << knightProbability(8, 30, 6, 4) << std::endl;
}