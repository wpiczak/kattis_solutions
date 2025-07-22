#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int row_count;
    int column_count;
    std::cin >> row_count >> column_count;

    std::vector<bool> is_blank(column_count, true);
    for (int i = 0; i < row_count; ++i) {
        std::string row;
        std::cin >> row;

        for (int j = 0; j < column_count; ++j)
            if (row[j] == '$') is_blank[j] = false;
    }

    std::cout << std::count(is_blank.begin(), is_blank.end(), true) + 1;

    return 0;
}
