#include <iostream>

int distance(const char letter, const int row, const int column) {
    const int target_row = (letter - 'A') / 4;
    const int target_column = (letter - 'A') % 4;
    return std::abs(row - target_row) + std::abs(column - target_column);
}

int main() {
    char letter;
    int result = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cin >> letter;
            if (letter == '.') continue;
            result += distance(letter, i, j);
        }
    }

    std::cout << result << '\n';

    return 0;
}
