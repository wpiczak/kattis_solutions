#include <array>
#include <iostream>
#include <vector>

int main() {
    int row_count;
    int column_count;
    std::cin >> row_count >> column_count;

    std::vector<std::string> rows(row_count);
    for (int i = 0; i < row_count; ++i)
        std::cin >> rows[i];

    std::array<int, 5> answers{};
    for (int i = 0; i < row_count - 1; ++i) {
        for (int j = 0; j < column_count - 1; ++j) {
            int car_count = 0;
            bool is_free = true;
            for (int k = 0; k < 2; ++k) {
                for (int l = 0; l < 2; ++l) {
                    if (rows[i + k][j + l] == '#') is_free = false;
                    if (rows[i + k][j + l] == 'X') ++car_count;
                }
            }

            if (!is_free) continue;
            ++answers[car_count];
        }
    }

    for (int i = 0; i < 5; ++i)
        std::cout << answers[i] << '\n';

    return 0;
}
