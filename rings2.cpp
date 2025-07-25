#include <iostream>
#include <vector>

bool has_neighbor(const std::vector<std::vector<int>>& grid, const int i, const int j, const int n) {
    if (i == 0 && n == 0) return true;
    if (j == 0 && n == 0) return true;
    if (i + 1 == grid.size() && n == 0) return true;
    if (j + 1 == grid[i].size() && n == 0) return true;
    if (i > 0 && grid[i - 1][j] == n) return true;
    if (j > 0 && grid[i][j - 1] == n) return true;
    if (i + 1 < grid.size() && grid[i + 1][j] == n) return true;
    if (j + 1 < grid[i].size() && grid[i][j + 1] == n) return true;
    return false;
}

bool update_grid(std::vector<std::vector<int>>& grid, const int index) {
    bool was_updated = false;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j] == -1 && has_neighbor(grid, i, j, index - 1)) {
                grid[i][j] = index;
                was_updated = true;
            }
        }
    }
    return was_updated;
}

void output(const int number, const int ring_count) {
    if (ring_count >= 10) std::cout << '.';
    if (number == 0) std::cout << "..";
    else if (number < 10) std::cout << '.' << std::to_string(number);
    else std::cout << number;
}

int main() {
    int row_count;
    int column_count;
    std::cin >> row_count >> column_count;

    std::vector<std::vector<int>> grid(row_count, std::vector<int>(column_count));
    for (int i = 0; i < row_count; ++i) {
        std::string line;
        std::cin >> line;
        for (int j = 0; j < column_count; ++j) {
            if (line[j] == '.') grid[i][j] = 0;
            else grid[i][j] = -1;
        }
    }

    int index = 0;
    while (update_grid(grid, ++index)) {}

    bool is_first = true;
    for (int i = 0; i < row_count; ++i) {
        if (is_first) is_first = false;
        else std::cout << '\n';
        for (int j = 0; j < column_count; ++j)
            output(grid[i][j], index - 1);
    }

    return 0;
}
