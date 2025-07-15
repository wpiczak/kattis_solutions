#include <array>
#include <iostream>

bool check_victory(const std::array<std::array<char, 3>, 3>& board, const char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

bool is_valid_board(std::array<std::array<char, 3>, 3>& board, const int x_count, const int o_count) {
    if (o_count != x_count && o_count != x_count - 1) return false;
    if (!check_victory(board, 'X') && !check_victory(board, 'O')) return true;

    if (check_victory(board, 'X') && x_count == o_count) return false;
    if (check_victory(board, 'O') && x_count == o_count + 1) return false;

    if (x_count == o_count) {
        bool result = false;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = '.';
                    result = result || is_valid_board(board, x_count, o_count - 1);
                    board[i][j] = 'O';
                }
            }
        }
        return result;
    }

    if (x_count == o_count + 1) {
        bool result = false;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 'X') {
                    board[i][j] = '.';
                    result = result || is_valid_board(board, x_count - 1, o_count);
                    board[i][j] = 'X';
                }
            }
        }
        return result;
    }

    return false;
}

int main() {
    int case_count;
    std::cin >> case_count;

    while (case_count--) {
        std::array<std::array<char, 3>, 3> board{};
        int x_count = 0;
        int o_count = 0;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cin >> board[i][j];
                if (board[i][j] == 'X') ++x_count;
                if (board[i][j] == 'O') ++o_count;
            }
        }

        if (is_valid_board(board, x_count, o_count))
            std::cout << "yes\n";
        else std::cout << "no\n";
    }

    return 0;
}
