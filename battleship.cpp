#include <iostream>
#include <limits>
#include <vector>

void load_board(std::vector<std::vector<char>>& board, int& ship_count) {
    for (auto& row : board) {
        std::string line;
        std::getline(std::cin, line);
        for (int i = 0; i < row.size(); ++i) {
            if (line[i] == '#') ++ship_count;
            row[i] = line[i];
        }
    }
}

int main() {
    int case_count;
    std::cin >> case_count;

    for (int i = 0; i < case_count; ++i) {
        int width, height, shot_count;
        std::cin >> width >> height >> shot_count;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::vector<std::vector<char>> first_board;
        std::vector<std::vector<char>> second_board;
        int first_ship_count = 0;
        int second_ship_count = 0;

        first_board.resize(height, std::vector(width, ' '));
        second_board.resize(height, std::vector(width, ' '));
        load_board(first_board, first_ship_count);
        load_board(second_board, second_ship_count);

        short current_player = 1;
        bool finished = false;
        for (int j = 0; j < shot_count; ++j) {
            int x, y;
            std::cin >> x >> y;

            y = height - 1 - y;

            if (finished) continue;

            if (current_player == 1) {
                if (second_board[y][x] == '#') {
                    second_board[y][x] = '_';
                    --second_ship_count;

                    if (second_ship_count == 0) {
                        if (first_ship_count == 0) finished = true;
                        current_player = 2;
                    }
                } else current_player = 2;
            } else {
                if (first_board[y][x] == '#') {
                    first_board[y][x] = '_';
                    --first_ship_count;

                    if (first_ship_count == 0) finished = true;
                } else current_player = 1;
            }
        }

        if (first_ship_count == 0 && second_ship_count > 0)
            std::cout << "player two wins\n";
        else if (first_ship_count > 0 && second_ship_count == 0)
            std::cout << "player one wins\n";
        else std::cout << "draw\n";
    }

    return 0;
}
