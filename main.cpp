
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

bool hasWon(const std::array<char, 9>& board, char player) {

    constexpr int winningLines[8][3] = {

        // Rows
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},

        // Columns
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},

        // Diagonals
        {0, 4, 8},
        {2, 4, 6}
    };

    for (const auto& line : winningLines) {

        if (board[line[0]] == player &&
            board[line[1]] == player &&
            board[line[2]] == player) {

            return true;
        }
    }

    return false;
}

int main() {

    char playAgain;

    do {

        // Reset game state for every new match
        std::array<char, 9> board = {
            '1', '2', '3',
            '4', '5', '6',
            '7', '8', '9'
        };

        char player = 'X';
        int movesPlayed = 0;
        bool gameOver = false;

        std::cout << "\n===== TIC-TAC-TOE =====\n\n";

        printBoard(board);

        // Current match loop
        while (!gameOver) {

            std::cout << "\nPlayer " << player
                      << ", choose a square (1-9): ";

            std::string line;

            if (!std::getline(std::cin, line)) {
                return 0;
            }

            int square = parseSquare(line);

            if (square == 0) {

                std::cout << "Invalid input! Enter 1-9.\n";

                continue;
            }

            int index = square - 1;

            if (board[index] == 'X' || board[index] == 'O') {

                std::cout << "Square already occupied!\n";

                continue;
            }

            board[index] = player;

            ++movesPlayed;

            std::cout << '\n';

            printBoard(board);

            // Check winner
            if (hasWon(board, player)) {

                std::cout << "\nPlayer " << player << " wins!\n";

                gameOver = true;
            }

            // Check draw
            else if (movesPlayed == 9) {

                std::cout << "\nIt's a draw!\n";

                gameOver = true;
            }

            // Switch player only if game is not over
            if (!gameOver) {

                player = (player == 'X') ? 'O' : 'X';
            }
        }

        // Ask whether players want another match
        while (true) {

            std::cout << "\nDo you want to play again? (y/n): ";

            std::string choice;

            if (!std::getline(std::cin, choice)) {
                return 0;
            }

            if (choice == "y" || choice == "Y") {

                playAgain = 'y';
                break;
            }

            else if (choice == "n" || choice == "N") {

                playAgain = 'n';
                break;
            }

            else {

                std::cout << "Invalid choice! Enter y or n.\n";
            }
        }

    } while (playAgain == 'y');

    std::cout << "\nThanks for playing!\n";

    return 0;
}
