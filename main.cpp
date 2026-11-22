
#include <array>
#include <iostream>
#include <sstream>
#include <string>
void printBoard(const std::array<char, 9>& board) {

    for (int row = 0; row < 3; ++row) {

        int start = row * 3;

        std::cout << board[start] << " | "
                  << board[start + 1] << " | "
                  << board[start + 2] << '\n';

        if (row < 2) {
            std::cout << "---------\n";
        }
    }
}

int main() {

    std::array<char, 9> board = {
        '1', '2', '3',
        '4', '5', '6',
        '7', '8', '9'
    };

    std::cout << "Tic-Tac-Toe\n\n";

    printBoard(board);
    int parseSquare(const std::string& line) {
        std::istringstream input(line);

        int square;
        char extra;

        if (!(input >> square) ||
            square < 1 ||
            square > 9 ||
            (input >> extra)) {
            return 0;
        }

        return square;
    }
    return 0;
}
