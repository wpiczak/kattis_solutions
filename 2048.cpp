#include <array>
#include <iostream>

std::array<std::array<int, 4>, 4> rotate_left(const std::array<std::array<int, 4>, 4>& board) {
    std::array<std::array<int, 4>, 4> result{};
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            result[i][j] = board[j][3 - i];
    return result;
}

std::array<std::array<int, 4>, 4> rotate_right(const std::array<std::array<int, 4>, 4>& board) {
    std::array<std::array<int, 4>, 4> result{};
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            result[i][j] = board[3 - j][i];
    return result;
}

void move_left(std::array<std::array<int, 4>, 4>& board) {
    for (int i = 0; i < 4; ++i) {
        int k = 0;
        for (int j = 0; j < 4; ++j) {
            if (board[i][j] == 0) continue;
            if (k > 0 && board[i][j] == board[i][k - 1]) board[i][k - 1] *= -2;
            else board[i][k++] = board[i][j];
        }
        while (k < 4) board[i][k++] = 0;
    }

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            board[i][j] = std::abs(board[i][j]);
}

int main() {
    std::array<std::array<int, 4>, 4> board{};
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            std::cin >> board[i][j];

    int move;
    std::cin >> move;

    for (int i = 0; i < move; ++i)
        board = rotate_left(board);

    move_left(board);

    for (int i = 0; i < move; ++i)
        board = rotate_right(board);

    bool is_first_row = true;
    for (int i = 0; i < 4; ++i) {
        if (is_first_row) is_first_row = false;
        else std::cout << '\n';

        bool is_first_column = true;
        for (int j = 0; j < 4; ++j) {
            if (is_first_column) is_first_column = false;
            else std::cout << ' ';

            std::cout << board[i][j];
        }
    }

    return 0;
}
