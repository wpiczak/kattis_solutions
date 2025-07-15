#include <iostream>

std::pair<int, int> angle_to_direction(const int angle) {
    if (angle == 0) return {1, 0};
    if (angle == 90) return {0, -1};
    if (angle == 180) return {-1, 0};
    if (angle == 270) return {0, 1};

    return {0, 0};
}

bool is_valid_position(const int x, const int y) { return 0 <= x && x < 8 && 0 <= y && y < 8; }

int main() {
    char board[8][8];
    for (auto& row : board)
        for (char& cell : row)
            std::cin >> cell;

    std::string program;
    std::cin >> program;

    int angle = 0;
    int x = 0;
    int y = 7;
    bool error_occurred = false;
    for (const char& instruction : program) {
        if (instruction == 'F') {
            auto [direction_x, direction_y] = angle_to_direction(angle);
            x += direction_x;
            y += direction_y;

            if (!is_valid_position(x, y)) error_occurred = true;
            if (board[y][x] == 'C' || board[y][x] == 'I') error_occurred = true;
        }

        if (instruction == 'L') angle = (angle + 90) % 360;
        if (instruction == 'R') {
            angle -= 90;
            if (angle < 0) angle += 360;
        }

        if (instruction == 'X') {
            auto [direction_x, direction_y] = angle_to_direction(angle);
            const int target_x = x + direction_x;
            const int target_y = y + direction_y;

            if (!is_valid_position(target_x, target_y) || board[target_y][target_x] != 'I')
                error_occurred = true;
            else board[target_y][target_x] = '.';
        }

        if (error_occurred) break;
    }

    if (!error_occurred && board[y][x] == 'D') std::cout << "Diamond!\n";
    else std::cout << "Bug!\n";

    return 0;
}
